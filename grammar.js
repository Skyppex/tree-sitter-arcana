const PREC = {
  ASSIGNMENT: -2,
  CONDITIONAL: -1,
  DEFAULT: 0,
  LOGICAL_OR: 1,
  LOGICAL_AND: 2,
  BITWISE_OR: 3,
  BITWISE_XOR: 4,
  BITWISE_AND: 5,
  EQUAL: 6,
  RELATIONAL: 7,
  SHIFT: 9,
  ADD: 10,
  MULTIPLY: 11,
  DECLARATION: 12,
  UNARY: 14,
  CALL: 15,
  FIELD: 16,
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
        field("variants", commaSep($.enum_variant)),
        "}",
      ),

    enum_variant: ($) =>
      seq(
        optional(repeat($.comment)),
        field("variant_name", $.identifier),
        optional(
          seq(
            "(",
            commaSep1(
              seq(
                optional(repeat($.comment)),
                field("field_name", $.identifier),
                field("field_type", afterColon($.type_annotation)),
              ),
            ),
            ")",
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

    identifier: (_) => /[_a-zA-Z]\w*/,

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
            $.loop,
            $.while,
            $.block,
            $.asssignement,
            $.compund_assignement,
            $.binary_expression,
            $.variable_declaration,
            $.if,
            $.trailing_closure,
            $.function_propagation,
            $.call,
            $.literal,
            $.identifier,
          ),
          optional(";"),
        ),
      ),

    loop: ($) => seq("loop", field("body", $._expression)),

    while: ($) =>
      seq(
        "while",
        field("condition", $._expression),
        field("body", $._expression),
      ),

    block: ($) => seq("{", repeat($._statement), "}"),

    asssignement: ($) => seq($.identifier, "=", $._expression),

    compund_assignement: ($) =>
      prec.left(
        PREC.ASSIGNMENT,
        seq(
          $._expression,
          choice("+=", "-=", "*=", "/=", "%=", "&=", "|=", "^="),
          $._expression,
        ),
      ),

    binary_expression: ($) => {
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
      prec.left(
        PREC.DECLARATION,
        seq(
          "let",
          optional("mut"),
          $.identifier,
          optional(afterColon($.type_annotation)),
          "=",
          $._expression,
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
            field(
              "else_ifs",
              repeat(
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

    trailing_closure: ($) => seq("=>", field("body", $._expression)),

    function_propagation: ($) =>
      prec.left(
        1,
        seq(
          field("prop", $._expression),
          ":",
          field("function", $._expression),
        ),
      ),

    call: ($) =>
      prec.left(
        1,
        seq(
          field("callee", $._expression),
          "(",
          field("args", commaSep($._expression)),
          ")",
        ),
      ),

    literal: ($) => choice($.int, $.float, $.char, $.string, $.bool, $.unit),

    int: (_) => token(/-?\d+/),
    float: (_) => token(/-?\d+\.\d+/),
    char: (_) => token(/'.'/),
    string: (_) => token(/".*?"/),
    bool: (_) => choice("true", "false"),
    unit: (_) => "unit",
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
