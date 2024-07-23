module.exports = grammar({
  name: "arcana",

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) => choice($.function_declaration, $._expression),

    function_declaration: ($) =>
      seq(
        "fun",
        field("name", $.identifier),
        "(",
        optional(field("params", $.parameters)),
        ")",
        optional(field("return_type", $.type_annotation_after_colon)),
        "=>",
        field("body", $._expression),
      ),

    identifier: (_) => /[_a-zA-Z]\w*/,

    parameters: ($) =>
      commaSep1(seq($.identifier, $.type_annotation_after_colon)),

    type_annotation_after_colon: ($) => seq(":", $.type_annotation),
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
        ),
      ),

    _expression: ($) =>
      prec.left(
        1,
        seq(
          choice(
            $.literal,
            $.identifier,
            $.variable_declaration,
            $.block,
            $.function_propagation,
            $.call,
          ),
          optional(";"),
        ),
      ),

    literal: ($) => choice($.int, $.float, $.char, $.string, $.bool, $.unit),

    int: (_) => token(/-?\d+/),
    float: (_) => token(/-?\d+\.\d+/),
    char: (_) => token(/'.'/),
    string: (_) => token(/".*?"/),
    bool: (_) => choice("true", "false"),
    unit: (_) => "unit",

    block: ($) => seq("{", repeat($._statement), "}"),

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

    variable_declaration: ($) =>
      seq(
        "let",
        $.identifier,
        optional($.type_annotation_after_colon),
        "=",
        $._expression,
      ),

    binary_expression: ($) =>
      prec.left(
        1,
        seq($._expression, choice("+", "-", "*", "/", "%"), $._expression),
      ),
  },
});

function commaSep(rule) {
  return optional(commaSep1(rule));
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
}
