const PREC = {
  COMMENT: -100,
  CONDITIONAL: -3,
  CLOSURE: -2,
  // Below LITERAL, so `E::V { .. }` is a constructor rather than a braceless
  // variant followed by a block.
  ENUM_LITERAL: -1,
  MATCH: 1,
  // Above BITWISE_OR: inside a match, a leading `|` starts the next arm rather
  // than continuing the previous arm's body as a bitwise-or.
  MATCH_ARM: 7,
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

  conflicts: ($) => [
    [$.struct_field],
    [$.indexer, $.collection_elements],
    // `a::` may be a module path or the start of a turbofish; the `<` after it
    // is what tells them apart.
    [$.mod_path, $._expression],
  ],

  rules: {
    source_file: ($) =>
      seq(optional($.shebang), optional(repeat($._statement))),

    shebang: () => seq("#!", /.*\r?\n?/),

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
    function_type_identifier_name: (_) =>
      prec(PREC.IDENTIFIER, /[_a-z][_a-z\d]*/),

    access_modifier: (_) => choice("pub", "sup"),

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
      prec.left(
        PREC.DEFAULT,
        seq(
          optional($.access_modifier),
          "struct",
          field("identifier", $.type_identifier),
          optional(field("where_clauses", $.where_clauses)),
          choice(
            seq(
              "{",
              optional(field("embedded_structs", $.embedded_structs)),
              optional(field("fields", $.struct_fields)),
              "}",
            ),
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
      prec.right(
        PREC.FIELD,
        seq(
          comments($),
          optional($.access_modifier),
          field("field_name", $.identifier),
          field("field_type", afterColon($.type_annotation)),
        ),
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
      seq(comments($), choice($.struct_field, $.enum_variant)),

    enum_variant: ($) =>
      choice(
        seq(
          optional("struct"),
          field("variant_name", $.type_identifier_name),
          optional(
            seq(
              "{",
              optional(field("embedded_structs", $.embedded_structs)),
              optional(field("fields", $.struct_fields)),
              "}",
            ),
          ),
        ),
        seq(
          "enum",
          field("variant_name", $.type_identifier_name),
          choice(
            seq("{", optional(field("members", $.enum_members)), "}"),
            ";",
          ),
        ),
      ),

    embedded_structs: ($) =>
      prec.left(
        PREC.DEFAULT,
        seq(sepTrailing1(",", $.embedded_struct), comments($)),
      ),

    embedded_struct: ($) =>
      seq(
        field("identifier", $.type_annotation),
        optional(seq("{", $.fields, "}")),
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
        choice(fatArrowOrBlock($, "body"), ";"),
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

    // One rule for both `struct Foo<T>` and `Foo<Int>`: they are the same shape,
    // and which is meant follows from where it appears rather than from
    // anything syntactic.
    generic_type_parameters: ($) =>
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
        field("type_name", $.type_identifier_name),
        "is",
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
          "Rune",
          "String",
          seq("[", field("array_type", $.type_annotation), "]"),
          seq("(", sepTrailing1(",", $.type_annotation), ")"),
          prec.right(
            seq(
              "fun",
              "(",
              sepTrailing(",", "param_types", $.type_annotation),
              ")",
              optional(afterColon(field("return_type", $.type_annotation))),
            ),
          ),
          $.literal_type,
          choice($.concrete_type_annotation, $.qualified_type_annotation),
        ),
      ),

    // A type inhabited by one value: `#3` is the type of that exact `3`, and
    // `#Int` the type of any int literal.
    literal_type: ($) =>
      seq(
        "#",
        choice(
          $.literal,
          seq(field("sign", choice("+", "-")), choice($.int, $.float)),
          field("literal_type_name", $.type_identifier_name),
        ),
      ),

    concrete_type_annotation: ($) =>
      prec.left(
        choice(
          seq(
            field("type_name", $.type_identifier_name),
            optional($.generic_type_parameters),
          ),
          $._enum_variant_path,
        ),
      ),

    // `E::V`, and through nested enums `E::Inner::V`. The leading segment names
    // the enum; every segment after it names a variant of the one before.
    //
    // Hidden, so the segments land on whichever rule uses it. Its head is a
    // `type_identifier` so that this and `static_member_function` share a
    // prefix: which one it is only shows up at the name after `::`.
    _enum_variant_path: ($) =>
      prec.right(
        seq(
          field("enum_name", $.type_identifier),
          repeat1(seq("::", field("enum_variant", $.type_identifier_name))),
        ),
      ),

    qualified_type_annotation: ($) =>
      prec.left(seq($.mod_path, "::", $.concrete_type_annotation)),

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
          $.propagation,
          $.closure,
          $.match,
          $.trailing_closure,
          $.call,
          $.member,
          $.type_constructor,
          $.enum_literal,
          $.generic_instantiation,
          $.static_member_function,
          $.literal,
          $.tuple,
          $.collection,
          $.identifier,
          $.break,
          $.continue,
          $.return,
        ),
      ),

    loop: ($) =>
      prec.left(PREC.CONDITIONAL, seq("loop", fatArrowOrBlock($, "body"))),

    while: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "while",
          field("condition", $._expression),
          fatArrowOrBlock($, "body"),
          optional(seq("else", fatArrowOrBlock($, "else_expr"))),
        ),
      ),

    for: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "for",
          field("pattern", $.pattern),
          "in",
          field("iterable", $._expression),
          fatArrowOrBlock($, "body"),
          optional(seq("else", fatArrowOrBlock($, "else_expr"))),
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
      prec.right(
        PREC.DECLARATION,
        seq(
          "let",
          optional("mut"),
          field("pattern", $.pattern),
          optional(field("type", afterColon($.type_annotation))),
          optional(seq("=", field("initializer", $._expression))),
        ),
      ),

    if: ($) =>
      prec.left(
        PREC.CONDITIONAL,
        seq(
          "if",
          field("condition", $._expression),
          fatArrowOrBlock($, "expr"),
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
          fatArrowOrBlock($, "expr"),
        ),
      ),

    else: ($) =>
      prec.left(PREC.DEFAULT, seq("else", fatArrowOrBlock($, "expr"))),

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
          closureBody($, "body"),
        ),
      ),

    propagation: ($) =>
      prec.left(
        PREC.FIELD,
        seq(
          field("prop", $._expression),
          ":",
          choice(field("function", $._expression), field("indexer", $.indexer)),
        ),
      ),

    indexer: ($) => seq("[", field("index", $._expression), "]"),

    closure: ($) =>
      prec.left(
        PREC.CLOSURE,
        seq(
          "|",
          optional(field("params", $.closure_parameters)),
          "|",
          optional(field("return_type", afterColon($.type_annotation))),
          closureBody($, "body"),
        ),
      ),

    closure_parameters: ($) =>
      prec.left(PREC.CLOSURE, sepTrailing1(",", $.closure_parameter)),

    closure_parameter: ($) =>
      seq(
        field("pattern", $.pattern),
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
          optional("|"),
          $.match_arm,
          repeat(prec(PREC.MATCH_ARM, seq(optional(","), "|", $.match_arm))),
          optional(","),
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
          $.constructor,
          $.constructor_fields,
          $.comparison_pattern,
          $.collection_pattern,
          $.tuple_pattern,
          $.binding_pattern,
          $.string,
          $.rune,
          $.float,
          $.uint,
          $.int,
          $.bool,
          $.unit,
          $.rest,
          $.wildcard,
          $.range_pattern,
        ),
      ),

    wildcard: (_) => "_",
    rest: (_) => "..",

    binding_pattern: ($) =>
      seq(prec(PREC.MATCH, /[_a-z][_a-z\d]*/), optional(seq("@", $.pattern))),

    constructor: ($) =>
      prec.left(
        PREC.MATCH,
        choice(
          seq(field("type", $.type_annotation), optional($._variant_tail)),
          seq(
            repeat1(seq("::", field("variant", $.type_identifier_name))),
            optional($._variant_tail),
          ),
        ),
      ),

    // What follows a constructor: its fields, or a binding of the value it
    // matched. Never both — `@` is how to ask for both.
    _variant_tail: ($) =>
      choice(
        field("fields", $.constructor_fields),
        field("binding", $.binding_pattern),
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

    tuple_pattern: ($) =>
      prec.left(100, seq("(", sepTrailing1(",", $.pattern), ")")),

    range_pattern: ($) =>
      prec.left(
        PREC.MATCH,
        seq(
          field("start", choice($.int, $.uint, $.rune, $.identifier)),
          "..",
          optional($.inclusive),
          field("end", choice($.int, $.uint, $.rune, $.identifier)),
        ),
      ),

    // `< 5`, `>= x` — a bound is a number, a rune or a variable holding one.
    comparison_pattern: ($) =>
      prec.left(
        PREC.MATCH,
        seq(
          field("operator", choice("<", ">", "<=", ">=")),
          field("bound", choice($.int, $.uint, $.float, $.rune, $.identifier)),
        ),
      ),

    collection_pattern: ($) =>
      prec(PREC.MATCH, seq("[", sepTrailing(",", "patterns", $.pattern), "]")),

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
          field(
            "type_name",
            choice($.concrete_type_annotation, $.qualified_type_annotation),
          ),
          "{",
          optional(field("fields", $.fields)),
          "}",
        ),
      ),

    // `E::V`, `E::Inner::V` — a variant that sets no fields needs no braces.
    // Below LITERAL so a following `{` is read as the variant's fields.
    enum_literal: ($) => prec.right(PREC.ENUM_LITERAL, $._enum_variant_path),

    // `id::<Int>`, the turbofish. It names a generic function's type arguments
    // at the use site, and a call may follow it.
    generic_instantiation: ($) =>
      prec.left(
        PREC.CALL,
        seq(
          field("function", $._expression),
          "::",
          field("generics", $.generic_type_parameters),
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
        choice($.unit, $.bool, $.int, $.uint, $.float, $.rune, $.string),
      ),

    tuple: ($) => seq("(", sepTrailing1(",", $._expression), ")"),

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
    rune: (_) => choice(token(/'.'/), token(/'\\.'/)),

    string: ($) =>
      seq('"', repeat(choice($.string_content, $.escape_sequence)), '"'),

    collection: ($) =>
      prec.left(PREC.LITERAL, seq("[", optional($.collection_elements), "]")),

    collection_elements: ($) => sepTrailing1(",", $._expression),

    fields: ($) => sepTrailing1(",", $.field),

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

// A closure's body is any expression, and its `=>` is optional — unlike an
// `if`, `while`, `for` or `fun` body, which needs `=>` or a block.
function closureBody($, exprFieldName) {
  return seq(optional("=>"), field(exprFieldName, $._expression));
}

function fatArrowOrBlock($, exprFieldName) {
  return choice(
    seq("=>", field(exprFieldName, $._expression)),
    field(exprFieldName, $.block),
  );
}

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
      seq(
        field("type_name", identifier_rule),
        "=",
        field("associated_type_name", $.type_identifier_name),
      ),
      seq("[", optional(".."), identifier_rule, "]"),
      // A whole type, which covers a bare parameter name as well as
      // `Foo<Foo<Int>>` and `Foo<[Int]>`.
      field("type", $.type_annotation),
    ),
  );
}
