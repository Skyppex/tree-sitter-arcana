const PREC = {
  RANGE: -3,
  CONDITIONAL: -2,
  DEFAULT: 0,
  ASSIGNMENT: 1,
  DECLARATION: 2,
  LOGICAL_OR: 3,
  LOGICAL_AND: 4,
  BITWISE_OR: 5,
  BITWISE_XOR: 6,
  BITWISE_AND: 7,
  EQUAL: 8,
  RELATIONAL: 9,
  SHIFT: 10,
  ADD: 11,
  MULTIPLY: 12,
  UNARY: 14,
  TRAILING_CLOSURE: 15,
  CALL: 16,
  FIELD: 17,
  IDENTIFIER: 18,
  LITERAL: 20,
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
        $.break,
        $.continue,
        $.return,
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
        commaSep(
          seq(
            optional(repeat($.comment)),
            field("field_name", $.identifier),
            field("field_type", afterColon($.type_annotation)),
          ),
        ),
        "}",
      ),

    enum_declaration: ($) =>
      seq(
        "enum",
        field("name", $.identifier),
        "{",
        commaSep($.enum_variant),
        "}",
      ),

    enum_variant: ($) =>
      seq(
        optional(repeat($.comment)),
        field("variant_name", $.identifier),
        optional(
          seq(
            "{",
            commaSep1(
              seq(
                optional(repeat($.comment)),
                field("field_name", $.identifier),
                field("field_type", afterColon($.type_annotation)),
              ),
            ),
            "}",
          ),
        ),
      ),

    union_declaration: ($) =>
      seq(
        "union",
        field("name", $.identifier),
        "{",
        commaSep(seq(optional(repeat($.comment)), $.literal)),
        "}",
      ),

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

    break: ($) => seq("break", choice(field("value", $._expression), ";")),

    continue: (_) => seq("continue", ";"),

    return: ($) => seq("return", choice(field("value", $._expression), ";")),

    identifier: (_) => prec(PREC.IDENTIFIER, /[_a-zA-Z]\w*/),

    parameters: ($) =>
      commaSep1(seq($.identifier, afterColon($.type_annotation))),

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
            commaSep($.type_annotation),
            ")",
            optional(afterColon($.type_annotation)),
          ),
        ),
      ),

    _expression: ($) =>
      prec.left(
        0,
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
            $.trailing_closure,
            $.call,
            $.member,
            $.struct_literal,
            $.enum_literal,
            $.literal,
            $.identifier,
          ),
          optional(";"),
        ),
      ),

    loop: ($) =>
      prec.left(PREC.CONDITIONAL, seq("loop", field("body", $._expression))),

    while: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "while",
          field("condition", $._expression),
          field("body", prec.right(PREC.DEFAULT, $._expression)),
          optional(seq("else", field("else_expr", $._expression))),
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
          field("body", prec.right(PREC.DEFAULT, $._expression)),
          optional(seq("else", field("else_expr", $._expression))),
        ),
      ),

    block: ($) => seq("{", repeat($._statement), "}"),

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
          field("true_expr", $._expression),
          optional(
            repeat(
              prec.left(
                PREC.DEFAULT,
                seq(
                  "else",
                  "if",
                  field("condition", $._expression),
                  field("expr", $._expression),
                ),
              ),
            ),
          ),
          optional(seq("else", field("else_expr", $._expression))),
        ),
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
          "=>",
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

    call: ($) =>
      prec.left(
        PREC.CALL,
        seq(
          field("callee", $._expression),
          "(",
          field("args", commaSep($._expression)),
          ")",
        ),
      ),

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

    fields: ($) =>
      commaSep1(
        seq(
          field("field_name", $.identifier),
          field("field_initializer", afterColon($._expression)),
        ),
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
          optional("="),
          field("end", $._expression),
        ),
      ),
  },
});

function afterColon(rule) {
  return seq(":", rule);
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
}
