module.exports = grammar({
  name: "arcana",

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) =>
      choice(
        $.struct_declaration,
        $.enum_declaration,
        $.union_declaration,
        $.function_declaration,
        $.break,
        $.continue,
        $.return,
        $._expression,
      ),

    struct_declaration: ($) =>
      seq(
        "struct",
        field("name", $.identifier),
        "{",
        commaSep(
          seq(
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
        field("variant_name", $.identifier),
        optional(
          seq(
            "(",
            commaSep1(
              seq(
                field("field_name", $.identifier),
                field("field_type", afterColon($.type_annotation)),
              ),
            ),
            ")",
          ),
        ),
      ),

    union_declaration: ($) =>
      seq("union", field("name", $.identifier), "{", commaSep($.literal), "}"),

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

    break: ($) => seq("break", optional(field("value", $._expression)), ";"),
    continue: (_) => seq("continue", ";"),
    return: ($) => seq("return", optional(field("value", $._expression)), ";"),

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
        1,
        seq(
          choice(
            $.loop,
            $.while,
            $.block,
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

    compund_assignement: ($) =>
      prec.left(
        1,
        seq(
          $._expression,
          choice("+=", "-=", "*=", "/=", "%=", "&=", "|=", "^="),
          $._expression,
        ),
      ),

    binary_expression: ($) =>
      prec.left(
        1,
        seq(
          $._expression,
          choice(
            "+",
            "-",
            "*",
            "/",
            "%",
            "&",
            "|",
            "^",
            "<<",
            ">>",
            "&&",
            "||",
            "==",
            "!=",
            "<",
            ">",
            "<=",
            ">=",
          ),
          $._expression,
        ),
      ),

    variable_declaration: ($) =>
      seq(
        "let",
        optional("mut"),
        $.identifier,
        optional(afterColon($.type_annotation)),
        "=",
        $._expression,
      ),

    if: ($) =>
      prec.left(
        1,
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
