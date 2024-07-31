const PREC = {
  COMMENT: -100,
  CONDITIONAL: -2,
  CLOSURE: -1,
  ASSIGNMENT: 0,
  DEFAULT: 0,
  EXPRESSION: 0,
  DECLARATION: 2,
  RANGE: 3,
  LOGICAL_OR: 4,
  LOGICAL_AND: 5,
  BITWISE_OR: 6,
  BITWISE_XOR: 7,
  BITWISE_AND: 8,
  EQUAL: 9,
  RELATIONAL: 10,
  SHIFT: 11,
  ADD: 12,
  MULTIPLY: 13,
  UNARY: 14,
  TRAILING_CLOSURE: 15,
  CALL: 16,
  FIELD: 17,
  LITERAL: 18,
  IDENTIFIER: 19,
  BLOCK: 21,
};

module.exports = grammar({
  name: "arcana",

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) =>
      choice(
        $.comment,
        $.struct_declaration,
        $.enum_declaration,
        $.union_declaration,
        $.function_declaration,
        $._expression,
      ),

    comment: ($) => choice($.line_comment, $.block_comment),
    line_comment: (_) => seq("//", /[^\n\r]*/),
    block_comment: (_) => seq("/-", /[^-]*-+([^/-][^-]*-+)*/, "/"),

    struct_declaration: ($) =>
      seq(
        "struct",
        field("name", $.identifier),
        "{",
        optional(field("fields", $.struct_fields)),
        "}",
      ),

    struct_fields: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(commaSepTrailing1($.struct_field), comments($)),
      ),

    struct_field: ($) =>
      seq(
        comments($),
        field("field_name", $.identifier),
        field("field_type", afterColon($.type_annotation)),
      ),

    enum_declaration: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(
          "enum",
          field("name", $.identifier),
          "{",
          optional(field("variants", $.enum_variants)),
          "}",
        ),
      ),

    enum_variants: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(commaSepTrailing1($.enum_variant), comments($)),
      ),

    enum_variant: ($) =>
      seq(
        comments($),
        field("variant_name", $.identifier),
        optional(seq("{", field("fields", $.struct_fields), "}")),
      ),

    union_declaration: ($) =>
      seq(
        "union",
        field("name", $.identifier),
        "{",
        optional(field("variants", $.union_variants)),
        "}",
      ),

    union_variants: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(commaSepTrailing1($.union_variant), comments($)),
      ),

    union_variant: ($) => seq(comments($), $.literal),

    function_declaration: ($) =>
      seq(
        "fun",
        field("name", $.identifier),
        "(",
        optional(field("params", $.parameters)),
        ")",
        optional(field("return_type", afterColon($.type_annotation))),
        "=>",
        field("body", $._expression),
      ),

    identifier: (_) => prec(PREC.IDENTIFIER, /[_a-zA-Z]\w*/),

    parameters: ($) => commaSepTrailing1($.parameter),

    parameter: ($) => seq($.identifier, afterColon($.type_annotation)),

    type_annotation: ($) =>
      field(
        "type",
        choice(
          "void",
          "unit",
          "bool",
          "int",
          "float",
          "char",
          "string",
          seq("[", field("array_type", $.type_annotation), "]"),
          seq(
            field("enum_name", $.identifier),
            "::",
            field("enum_variant", $.identifier),
          ),
          $.identifier,
          seq(
            "fun",
            "(",
            commaSepTrailing($.type_annotation),
            ")",
            optional(afterColon($.type_annotation)),
          ),
        ),
      ),

    _expression: ($) =>
      prec.left(
        PREC.EXPRESSION,
        seq(
          choice(
            $.range,
            $.loop,
            $.while,
            $.for,
            $.block,
            $.assignment,
            $.compound_assignment,
            $.binary,
            $.variable_declaration,
            $.if,
            $.unary,
            $.function_propagation,
            $.closure,
            $.trailing_closure,
            $.call,
            $.member,
            $.struct_literal,
            $.enum_literal,
            $.literal,
            $.identifier,

            // These exoressions have no returning value
            $.break,
            $.continue,
            $.return,
          ),
          optional(";"),
        ),
      ),

    loop: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq("loop", optional("=>"), field("body", $._expression)),
      ),

    while: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "while",
          field("condition", $._expression),
          "=>",
          field("body", $._expression),
          optional(
            seq("else", optional("=>"), field("else_expr", $._expression)),
          ),
        ),
      ),

    for: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "for",
          field("identifier", $.identifier),
          "in",
          field("iterable", $._expression),
          "=>",
          field("body", $._expression),
          optional(
            seq("else", optional("=>"), field("else_expr", $._expression)),
          ),
        ),
      ),

    block: ($) => prec(PREC.BLOCK, seq("{", repeat($._statement), "}")),

    assignment: ($) =>
      prec.left(
        PREC.ASSIGNMENT,
        seq(field("member", $._expression), "=", field("value", $._expression)),
      ),

    compound_assignment: ($) =>
      prec.left(
        PREC.ASSIGNMENT,
        seq(
          field("member", $._expression),
          choice("+=", "-=", "*=", "/=", "%=", "&=", "|=", "^="),
          field("value", $._expression),
        ),
      ),

    binary: ($) => {
      const table = [
        ["+", PREC.ADD],
        ["-", PREC.ADD],
        ["*", PREC.MULTIPLY],
        ["/", PREC.MULTIPLY],
        ["%", PREC.MULTIPLY],
        ["||", PREC.LOGICAL_OR],
        ["&&", PREC.LOGICAL_AND],
        ["|", PREC.BITWISE_OR],
        ["^", PREC.BITWISE_XOR],
        ["&", PREC.BITWISE_AND],
        ["==", PREC.EQUAL],
        ["!=", PREC.EQUAL],
        [">", PREC.RELATIONAL],
        [">=", PREC.RELATIONAL],
        ["<=", PREC.RELATIONAL],
        ["<", PREC.RELATIONAL],
        ["<<", PREC.SHIFT],
        [">>", PREC.SHIFT],
      ];

      return choice(
        ...table.map(([operator, precedence]) => {
          return prec.left(
            precedence,
            seq(
              field("left", $._expression),
              field("operator", operator),
              field("right", $._expression),
            ),
          );
        }),
      );
    },

    variable_declaration: ($) =>
      prec(
        PREC.DECLARATION,
        seq(
          "let",
          optional("mut"),
          field("var_name", $.identifier),
          optional(field("type", afterColon($.type_annotation))),
          "=",
          field("initializer", $._expression),
        ),
      ),

    if: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "if",
          field("condition", $._expression),
          "=>",
          field("expr", $._expression),
          optional(repeat($.elif)),
          optional($.else),
        ),
      ),

    elif: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(
          "else",
          "if",
          field("condition", $._expression),
          "=>",
          field("expr", $._expression),
        ),
      ),

    else: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq("else", optional("=>"), field("expr", $._expression)),
      ),

    unary: ($) =>
      prec.right(
        PREC.UNARY,
        seq(
          field("operator", choice("+", "-", "!", "~")),
          field("operand", $._expression),
        ),
      ),

    trailing_closure: ($) =>
      prec.left(
        PREC.TRAILING_CLOSURE,
        seq(
          field("function", $._expression),
          "->",
          field("body", $._expression),
        ),
      ),

    function_propagation: ($) =>
      prec.left(
        PREC.FIELD,
        seq(
          field("prop", $._expression),
          ":",
          field("function", $._expression),
        ),
      ),

    closure: ($) =>
      prec.left(
        PREC.CLOSURE,
        seq(
          "|",
          optional(field("params", $.closure_parameters)),
          "|",
          optional(afterColon($.type_annotation)),
          optional("=>"),
          field("body", $._expression),
        ),
      ),

    closure_parameters: ($) =>
      prec.left(PREC.CLOSURE, commaSepTrailing1($.closure_parameter)),

    closure_parameter: ($) =>
      seq($.identifier, optional(afterColon($.type_annotation))),

    call: ($) =>
      prec.left(
        PREC.CALL,
        seq(
          field("callee", $._expression),
          "(",
          optional(field("args", $.arguments)),
          ")",
        ),
      ),

    arguments: ($) => commaSepTrailing1($.argument),

    argument: ($) => $._expression,

    member: ($) =>
      prec.left(
        PREC.FIELD,
        seq(field("object", $._expression), ".", field("member", $.identifier)),
      ),

    struct_literal: ($) =>
      prec(
        PREC.LITERAL,
        seq(
          field("struct_name", $.identifier),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    enum_literal: ($) =>
      prec(
        PREC.LITERAL,
        seq(
          field("enum_name", $.identifier),
          "::",
          field("enum_variant", $.identifier),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    literal: ($) =>
      prec(
        PREC.LITERAL,
        choice($.unit, $.bool, $.int, $.float, $.char, $.string),
      ),

    unit: (_) => "unit",
    bool: (_) => choice("true", "false"),
    int: (_) => token(/\d+/),
    float: (_) => token(/\d+\.\d+/),
    char: (_) => choice(token(/'.'/), token(/'\\.'/)),

    string: ($) =>
      seq('"', repeat(choice($.string_content, $.escape_sequence)), '"'),

    fields: ($) => commaSepTrailing1($.field),

    field: ($) =>
      seq(
        field("field_name", $.identifier),
        field("field_initializer", afterColon($._expression)),
      ),

    string_content: (_) => token.immediate(prec(1, /[^"\\\n]+/)),
    escape_sequence: (_) =>
      token(
        choice(
          /\\x[0-9a-fA-F]{2,4}/,
          /\\u[0-9a-fA-F]{4}/,
          /\\U[0-9a-fA-F]{8}/,
          /\\[abefnrtv'\"\\\?0]/,
        ),
      ),

    range: ($) =>
      prec.left(
        PREC.RANGE,
        seq(
          field("start", $._expression),
          "..",
          optional($.inclusive),
          field("end", $._expression),
        ),
      ),

    inclusive: (_) => "=",

    break: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq("break", choice(field("value", $._expression), optional(";"))),
      ),

    continue: (_) => prec.left(PREC.DEFAULT, seq("continue", optional(";"))),

    return: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq("return", choice(field("value", $._expression), optional(";"))),
      ),
  },
});

function comments($) {
  return prec(PREC.COMMENT, optional(repeat($.comment)));
}

function afterColon(rule) {
  return seq(":", rule);
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

function commaSepTrailing(rule) {
  return optional(commaSepTrailing1(rule));
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
}

function commaSepTrailing1(rule) {
  return seq(rule, repeat(seq(",", rule)), optional(","));
}
