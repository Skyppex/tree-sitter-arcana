const PREC = {
  COMMENT: -100,
  CONDITIONAL: -3,
  CLOSURE: -2,
  MATCH: -1,
  ASSIGNMENT: 0,
  DEFAULT: 0,
  EXPRESSION: 0,
  BLOCK: 1,
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
  LITERAL: 17,
  FIELD: 18,
  IDENTIFIER: 19,
};

module.exports = grammar({
  name: "arcana",

  conflicts: ($) => [[$.type_annotation]],

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) =>
      seq(
        choice(
          $.mod,
          $.use,
          $.comment,
          $.struct_declaration,
          $.enum_declaration,
          $.union_declaration,
          $.protocol_declaration,
          $.type_alias_declaration,
          $.implementation_declaration,
          $.function_declaration,
          $._expression,
        ),
        optional(";"),
      ),

    comment: ($) => choice($.line_comment, $.block_comment),
    line_comment: (_) => seq("//", /[^\n\r]*/),
    block_comment: (_) => seq("/-", /[^-]*-+([^/-][^-]*-+)*/, "/"),
    identifier: (_) => prec(PREC.IDENTIFIER, /[_a-z][_a-z\d]*/),
    type_identifier_name: (_) => prec(PREC.IDENTIFIER, /[A-Z]\w*/),
    generic_identifier: (_) => prec(PREC.IDENTIFIER, /T\w*/),
    function_type_identifier_name: (_) =>
      prec(PREC.IDENTIFIER, /[_a-z][_a-z\d]*/),

    access_modifier: (_) => "pub",

    mod: ($) => seq(optional($.access_modifier), "mod", $.mod_path, ";"),

    mod_path: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq($.identifier, optional(seq("::", $.mod_path))),
      ),

    use: ($) => seq("use", $.use_path, ";"),

    use_path: ($) =>
      seq(
        choice($.type_identifier_name, $.identifier),
        optional(seq("::", choice($.use_path, $.use_group))),
      ),

    use_group: ($) => seq("{", sepTrailing1(",", $.use_path), "}"),

    struct_declaration: ($) =>
      prec.right(
        PREC.DEFAULT,
        seq(
          optional($.access_modifier),
          "struct",
          field("identifier", $.type_identifier),
          optional(field("where_clauses", $.where_clauses)),
          choice(
            seq("{", optional(field("fields", $.struct_fields)), "}"),
            ";",
          ),
        ),
      ),

    struct_fields: ($) =>
      prec.left(
        PREC.FIELD,
        seq(sepTrailing1(",", $.struct_field), comments($)),
      ),

    struct_field: ($) =>
      seq(
        comments($),
        optional($.access_modifier),
        field("field_name", $.identifier),
        field("field_type", afterColon($.type_annotation)),
      ),

    enum_declaration: ($) =>
      prec.right(
        PREC.DEFAULT,
        seq(
          optional($.access_modifier),
          "enum",
          field("identifier", $.type_identifier),
          optional(field("where_clauses", $.where_clauses)),
          choice(
            seq("{", optional(field("members", $.enum_members)), "}"),
            ";",
          ),
        ),
      ),

    enum_members: ($) =>
      prec.left(
        PREC.FIELD,
        seq(sepTrailing1(",", choice($.enum_member)), comments($)),
      ),

    enum_member: ($) =>
      seq(comments($), choice($.enum_shared_field, $.enum_variant)),

    enum_shared_field: ($) =>
      seq(
        optional($.access_modifier),
        field("field_name", $.identifier),
        field("field_type", afterColon($.type_annotation)),
      ),

    enum_variant: ($) =>
      seq(
        field("variant_name", $.type_identifier_name),
        optional(seq("{", field("fields", $.struct_fields), "}")),
      ),

    union_declaration: ($) =>
      seq(
        optional($.access_modifier),
        "union",
        field("name", $.type_identifier_name),
        optional(field("where_clauses", $.where_clauses)),
        choice(seq("{", field("variants", $.union_variants), "}"), ";"),
      ),

    union_variants: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(sepTrailing1(",", $.union_variant), comments($)),
      ),

    union_variant: ($) => seq(comments($), $.literal),

    protocol_declaration: ($) =>
      seq(
        optional($.access_modifier),
        "proto",
        field("name", $.type_identifier),
        optional(field("where_clauses", $.where_clauses)),
        choice(
          seq(
            "{",
            repeat(choice($.associated_type, $.function_declaration)),
            "}",
          ),
          ";",
        ),
      ),

    associated_type: ($) =>
      seq(
        comments($),
        "type",
        field("name", $.type_identifier),
        optional(seq("=", $.type_annotation)),
        ";",
      ),

    type_alias_declaration: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(
          optional($.access_modifier),
          "type",
          field("name", $.type_identifier),
          optional(field("where_clauses", $.where_clauses)),
          choice(
            seq("=", optional(field("variants", $.type_alias_variants)), ";"),
            ";",
          ),
        ),
      ),

    type_alias_variants: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(sepTrailing1("or", $.type_alias_variant), comments($)),
      ),

    type_alias_variant: ($) => seq(comments($), $.type_annotation),

    implementation_declaration: ($) =>
      prec.right(
        PREC.DEFAULT,
        seq(
          "imp",
          optional($.generic_type_parameters),
          field("protocol_name", $.type_identifier),
          "for",
          field("type_name", $.type_identifier),
          optional(field("where_clauses", $.where_clauses)),
          choice(
            seq(
              "{",
              repeat(choice($.associated_type, $.function_declaration)),
              "}",
            ),
            ";",
          ),
        ),
      ),

    function_declaration: ($) =>
      seq(
        optional($.access_modifier),
        "fun",
        field("identifier", $.function_type_identifier),
        "(",
        optional(field("params", $.parameters)),
        ")",
        optional(field("return_type", afterColon($.type_annotation))),
        optional(field("where_clauses", $.where_clauses)),
        choice(seq("=>", field("body", $._expression)), ";"),
      ),

    type_identifier: ($) =>
      prec.right(
        PREC.IDENTIFIER,
        seq(
          field("name", $.type_identifier_name),
          optional(field("generics", $.generic_type_parameters)),
        ),
      ),

    function_type_identifier: ($) =>
      prec.right(
        PREC.IDENTIFIER,
        seq(
          field("name", $.function_type_identifier_name),
          optional(field("generics", $.generic_type_parameters)),
        ),
      ),

    generic_type_parameters: ($) =>
      prec(
        PREC.DEFAULT,
        seq("<", type_parameters($, $.generic_identifier), ">"),
      ),

    concrete_type_parameters: ($) =>
      prec(
        PREC.DEFAULT,
        seq("<", type_parameters($, $.type_identifier_name), ">"),
      ),

    parameters: ($) => sepTrailing1(",", $.parameter),

    parameter: ($) =>
      choice(
        seq(
          field("param_name", $.identifier),
          field("param_type", afterColon($.type_annotation)),
        ),
        seq(
          field("param_name", $.identifier),
          field(
            "param_spread_type",
            afterColon(seq("..", "[", $.type_annotation, "]")),
          ),
        ),
      ),

    where_clauses: ($) => seq("where", sepTrailing1(",", $.where_clause)),

    where_clause: ($) =>
      seq(
        choice(field("type_name", $.generic_identifier), "imp"),
        ":",
        sep1("and", field("protocol_name", $.type_annotation)),
      ),

    type_annotation: ($) =>
      prec.left(
        PREC.DEFAULT,
        choice(
          "Void",
          "Unit",
          "Bool",
          "Int",
          "UInt",
          "Float",
          "Char",
          "String",
          seq("[", field("array_type", $.type_annotation), "]"),
          seq(
            "fun",
            "(",
            sepTrailing(",", "param_types", $.type_annotation),
            ")",
            optional(afterColon(field("return_type", $.type_annotation))),
          ),
          seq(
            optional(seq($.mod_path, "::")),
            choice(
              seq(
                field("type_name", $.type_identifier_name),
                optional($.concrete_type_parameters),
              ),
              seq(
                field("enum_name", $.type_identifier_name),
                optional($.concrete_type_parameters),
                "::",
                field("enum_variant", $.type_identifier_name),
                optional($.concrete_type_parameters),
              ),
            ),
          ),
        ),
      ),

    function_type_annotation: ($) =>
      prec(
        PREC.IDENTIFIER,
        seq(
          field("name", $.function_type_identifier_name),
          optional(field("generics", seq("::", $.generic_type_parameters))),
        ),
      ),

    _expression: ($) =>
      prec.left(
        PREC.EXPRESSION,
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
          $.match,
          $.trailing_closure,
          $.call,
          $.member,
          $.type_constructor,
          $.static_member_function,
          $.literal,
          $.collection,
          $.identifier,
          $.break,
          $.continue,
          $.return,
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
          optional(seq("|", field("params", $.closure_parameters), "|")),
          optional(field("return_type", afterColon($.type_annotation))),
          optional("=>"),
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
          optional(field("return_type", afterColon($.type_annotation))),
          optional("=>"),
          field("body", $._expression),
        ),
      ),

    closure_parameters: ($) =>
      prec.left(PREC.CLOSURE, sepTrailing1(",", $.closure_parameter)),

    closure_parameter: ($) =>
      seq(
        field("param_name", $.identifier),
        optional(field("param_type", afterColon($.type_annotation))),
      ),

    match: ($) =>
      prec.left(
        PREC.MATCH,
        seq(field("matchee", $._expression), "match", $.match_arms),
      ),

    match_arms: ($) =>
      prec.left(
        PREC.MATCH,
        seq(
          optional(seq($.match_arm, ",")),
          sepTrailing1(",", seq("|", $.match_arm)),
          comments($),
        ),
      ),

    match_arm: ($) =>
      prec.left(
        PREC.MATCH,
        seq(field("pattern", $.pattern), "=>", field("body", $._expression)),
      ),

    pattern: ($) =>
      prec.left(
        PREC.DEFAULT,
        choice(
          $.wildcard,
          $.unit,
          $.bool,
          $.int,
          $.uint,
          $.float,
          $.char,
          $.string,
          $.identifier,
          $.constructor,
        ),
      ),

    wildcard: (_) => "_",

    constructor: ($) =>
      prec.left(
        PREC.MATCH,
        seq(
          field("type", $.type_annotation),
          optional(field("fields", $.constructor_fields)),
        ),
      ),

    constructor_fields: ($) =>
      prec.left(
        PREC.MATCH,
        seq("{", sepTrailing(",", "fields", $.constructor_field), "}"),
      ),

    constructor_field: ($) =>
      prec.left(
        PREC.MATCH,
        seq(
          optional(comments($)),
          choice(
            field("field_pattern", $.identifier),
            seq(
              field("field_name", $.identifier),
              field("field_pattern", afterColon($.pattern)),
            ),
          ),
        ),
      ),

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

    arguments: ($) => sepTrailing1(",", $.argument),

    argument: ($) => $._expression,

    member: ($) =>
      prec.left(
        PREC.FIELD,
        seq(field("object", $._expression), ".", field("member", $.identifier)),
      ),

    type_constructor: ($) =>
      prec.right(
        PREC.LITERAL,
        seq(
          optional(seq(field("path", $.mod_path), "::")),
          field("type_name", $.type_annotation),
          optional(seq("::", field("member_type_name", $.type_annotation))),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    struct_literal: ($) =>
      prec.right(
        PREC.LITERAL,
        seq(
          optional(seq(field("path", $.mod_path), "::")),
          field("struct_name", $.type_identifier),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    enum_literal: ($) =>
      prec.right(
        PREC.LITERAL,
        seq(
          optional(seq(field("path", $.mod_path), "::")),
          field("enum_name", $.type_identifier),
          "::",
          field("enum_variant_name", $.type_identifier_name),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    static_member_function: ($) =>
      prec.right(
        PREC.FIELD,
        seq(
          field("type", $.type_identifier),
          "::",
          field("function", $.function_type_identifier),
        ),
      ),

    literal: ($) =>
      prec(
        PREC.LITERAL,
        choice($.unit, $.bool, $.int, $.uint, $.float, $.char, $.string),
      ),

    unit: (_) => "unit",
    bool: (_) => choice("true", "false"),

    int: (_) =>
      choice(
        token(/\d+d?/),
        seq(choice("0b", "0o", "0d", "0x"), token(/\d+d?/)),
      ),

    uint: (_) =>
      choice(token(/\d+u/), seq(choice("0b", "0o", "0d", "0x"), token(/\d+u/))),

    float: (_) => choice(token(/\d+f/), token(/\d*\.\d+f?/)),
    char: (_) => choice(token(/'.'/), token(/'\\.'/)),

    string: ($) =>
      seq('"', repeat(choice($.string_content, $.escape_sequence)), '"'),

    collection: ($) =>
      prec.left(PREC.LITERAL, seq("[", optional($.collection_elements), "]")),

    collection_elements: ($) => sepTrailing1(",", $._expression),

    fields: ($) => choice($.named_fields, $.unnamed_fields),

    named_fields: ($) => sepTrailing1(",", $.named_field),

    named_field: ($) =>
      seq(
        field("field_name", $.identifier),
        field("field_initializer", afterColon($._expression)),
      ),

    unnamed_fields: ($) => sepTrailing1(",", $.unnamed_field),
    unnamed_field: ($) => field("field_initializer", $._expression),

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

function sepTrailing1(separator, rule) {
  return seq(rule, repeat(seq(separator, rule)), optional(separator));
}

function sepTrailing(separator, field_name, rule) {
  return optional(field(field_name, sepTrailing1(separator, rule)));
}

function sep1(separator, rule) {
  return seq(rule, repeat(seq(separator, rule)));
}

function type_parameters($, identifier_rule) {
  return sepTrailing1(
    ",",
    choice(
      field("type_name", identifier_rule),
      seq(
        field("type_name", identifier_rule),
        "=",
        field("associated_type_name", $.type_identifier_name),
      ),
      seq("[", optional(".."), identifier_rule, "]"),
    ),
  );
}
