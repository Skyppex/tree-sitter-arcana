#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 104
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 0
#define TOKEN_COUNT 33
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 11

enum ts_symbol_identifiers {
  anon_sym_fun = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  anon_sym_EQ_GT = 4,
  sym_identifier = 5,
  anon_sym_COMMA = 6,
  anon_sym_COLON = 7,
  anon_sym_void = 8,
  anon_sym_unit = 9,
  anon_sym_bool = 10,
  anon_sym_int = 11,
  anon_sym_float = 12,
  anon_sym_char = 13,
  anon_sym_string = 14,
  anon_sym_LBRACK = 15,
  anon_sym_RBRACK = 16,
  anon_sym_SEMI = 17,
  sym_int = 18,
  sym_float = 19,
  sym_char = 20,
  sym_string = 21,
  anon_sym_true = 22,
  anon_sym_false = 23,
  anon_sym_LBRACE = 24,
  anon_sym_RBRACE = 25,
  anon_sym_let = 26,
  anon_sym_EQ = 27,
  anon_sym_PLUS = 28,
  anon_sym_DASH = 29,
  anon_sym_STAR = 30,
  anon_sym_SLASH = 31,
  anon_sym_PERCENT = 32,
  sym_source_file = 33,
  sym__statement = 34,
  sym_function_declaration = 35,
  sym_parameters = 36,
  sym_type_annotation_after_colon = 37,
  sym_type_annotation = 38,
  sym__expression = 39,
  sym_literal = 40,
  sym_bool = 41,
  sym_unit = 42,
  sym_block = 43,
  sym_function_propagation = 44,
  sym_call = 45,
  sym_variable_declaration = 46,
  aux_sym_source_file_repeat1 = 47,
  aux_sym_parameters_repeat1 = 48,
  aux_sym_call_repeat1 = 49,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_fun] = "fun",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_EQ_GT] = "=>",
  [sym_identifier] = "identifier",
  [anon_sym_COMMA] = ",",
  [anon_sym_COLON] = ":",
  [anon_sym_void] = "void",
  [anon_sym_unit] = "unit",
  [anon_sym_bool] = "bool",
  [anon_sym_int] = "int",
  [anon_sym_float] = "float",
  [anon_sym_char] = "char",
  [anon_sym_string] = "string",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_SEMI] = ";",
  [sym_int] = "int",
  [sym_float] = "float",
  [sym_char] = "char",
  [sym_string] = "string",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_function_declaration] = "function_declaration",
  [sym_parameters] = "parameters",
  [sym_type_annotation_after_colon] = "type_annotation_after_colon",
  [sym_type_annotation] = "type_annotation",
  [sym__expression] = "_expression",
  [sym_literal] = "literal",
  [sym_bool] = "bool",
  [sym_unit] = "unit",
  [sym_block] = "block",
  [sym_function_propagation] = "function_propagation",
  [sym_call] = "call",
  [sym_variable_declaration] = "variable_declaration",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_call_repeat1] = "call_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_fun] = anon_sym_fun,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [sym_identifier] = sym_identifier,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_unit] = anon_sym_unit,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_int] = sym_int,
  [sym_float] = sym_float,
  [sym_char] = sym_char,
  [sym_string] = sym_string,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_function_declaration] = sym_function_declaration,
  [sym_parameters] = sym_parameters,
  [sym_type_annotation_after_colon] = sym_type_annotation_after_colon,
  [sym_type_annotation] = sym_type_annotation,
  [sym__expression] = sym__expression,
  [sym_literal] = sym_literal,
  [sym_bool] = sym_bool,
  [sym_unit] = sym_unit,
  [sym_block] = sym_block,
  [sym_function_propagation] = sym_function_propagation,
  [sym_call] = sym_call,
  [sym_variable_declaration] = sym_variable_declaration,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_call_repeat1] = aux_sym_call_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unit] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [sym_int] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_type_annotation_after_colon] = {
    .visible = true,
    .named = true,
  },
  [sym_type_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [sym_unit] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_function_propagation] = {
    .visible = true,
    .named = true,
  },
  [sym_call] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_declaration] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_call_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_args = 1,
  field_array_type = 2,
  field_body = 3,
  field_callee = 4,
  field_function = 5,
  field_name = 6,
  field_params = 7,
  field_prop = 8,
  field_return_type = 9,
  field_type = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_args] = "args",
  [field_array_type] = "array_type",
  [field_body] = "body",
  [field_callee] = "callee",
  [field_function] = "function",
  [field_name] = "name",
  [field_params] = "params",
  [field_prop] = "prop",
  [field_return_type] = "return_type",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 3},
  [6] = {.index = 9, .length = 2},
  [7] = {.index = 11, .length = 3},
  [8] = {.index = 14, .length = 3},
  [9] = {.index = 17, .length = 3},
  [10] = {.index = 20, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_callee, 0},
  [1] =
    {field_function, 2},
    {field_prop, 0},
  [3] =
    {field_type, 0},
  [4] =
    {field_args, 2},
    {field_callee, 0},
  [6] =
    {field_args, 2},
    {field_args, 3},
    {field_callee, 0},
  [9] =
    {field_body, 5},
    {field_name, 1},
  [11] =
    {field_array_type, 1},
    {field_type, 0},
    {field_type, 2},
  [14] =
    {field_body, 6},
    {field_name, 1},
    {field_return_type, 4},
  [17] =
    {field_body, 6},
    {field_name, 1},
    {field_params, 3},
  [20] =
    {field_body, 7},
    {field_name, 1},
    {field_params, 3},
    {field_return_type, 5},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 3,
  [5] = 5,
  [6] = 6,
  [7] = 5,
  [8] = 6,
  [9] = 9,
  [10] = 9,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 12,
  [16] = 16,
  [17] = 16,
  [18] = 18,
  [19] = 13,
  [20] = 18,
  [21] = 21,
  [22] = 11,
  [23] = 23,
  [24] = 21,
  [25] = 23,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 36,
  [40] = 32,
  [41] = 38,
  [42] = 33,
  [43] = 34,
  [44] = 27,
  [45] = 26,
  [46] = 30,
  [47] = 35,
  [48] = 37,
  [49] = 31,
  [50] = 29,
  [51] = 28,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 55,
  [57] = 54,
  [58] = 53,
  [59] = 59,
  [60] = 52,
  [61] = 59,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 65,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 75,
  [77] = 71,
  [78] = 73,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 74,
  [83] = 81,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 93,
  [97] = 94,
  [98] = 88,
  [99] = 92,
  [100] = 100,
  [101] = 95,
  [102] = 89,
  [103] = 91,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(34);
      ADVANCE_MAP(
        '"', 2,
        '%', 108,
        '\'', 32,
        '(', 36,
        ')', 37,
        '*', 106,
        '+', 104,
        ',', 74,
        '-', 105,
        '/', 107,
        ':', 75,
        ';', 92,
        '=', 103,
        '[', 90,
        ']', 91,
        'b', 62,
        'c', 49,
        'f', 39,
        'i', 58,
        'l', 47,
        's', 71,
        't', 63,
        'u', 55,
        'v', 61,
        '{', 99,
        '}', 100,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 2,
        '\'', 32,
        ')', 37,
        '-', 30,
        ':', 75,
        '=', 102,
        'f', 41,
        'l', 47,
        't', 63,
        'u', 55,
        '{', 99,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(95);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(37);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 5:
      if (lookahead == '>') ADVANCE(38);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '[', 90,
        'b', 23,
        'c', 11,
        'f', 16,
        'i', 19,
        's', 26,
        'u', 17,
        'v', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(29);
      END_STATE();
    case 9:
      if (lookahead == 'd') ADVANCE(76);
      END_STATE();
    case 10:
      if (lookahead == 'g') ADVANCE(88);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(7);
      END_STATE();
    case 12:
      if (lookahead == 'i') ADVANCE(9);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 14:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 19:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 20:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 21:
      if (lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 22:
      if (lookahead == 'o') ADVANCE(12);
      END_STATE();
    case 23:
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 26:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(78);
      END_STATE();
    case 29:
      if (lookahead == 't') ADVANCE(84);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      END_STATE();
    case 32:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      ADVANCE_MAP(
        '"', 2,
        '\'', 32,
        '(', 36,
        ')', 37,
        ',', 74,
        '-', 30,
        ':', 75,
        ';', 92,
        '=', 5,
        'f', 40,
        'l', 47,
        't', 63,
        'u', 55,
        '{', 99,
        '}', 100,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(33);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_fun);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(53);
      if (lookahead == 'l') ADVANCE(59);
      if (lookahead == 'u') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_void);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_unit);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_bool);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_float);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_char);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_string);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_int);
      if (lookahead == '.') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_float);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(38);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 33},
  [2] = {.lex_state = 33},
  [3] = {.lex_state = 33},
  [4] = {.lex_state = 33},
  [5] = {.lex_state = 33},
  [6] = {.lex_state = 33},
  [7] = {.lex_state = 33},
  [8] = {.lex_state = 33},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 33},
  [27] = {.lex_state = 33},
  [28] = {.lex_state = 33},
  [29] = {.lex_state = 33},
  [30] = {.lex_state = 33},
  [31] = {.lex_state = 33},
  [32] = {.lex_state = 33},
  [33] = {.lex_state = 33},
  [34] = {.lex_state = 33},
  [35] = {.lex_state = 33},
  [36] = {.lex_state = 33},
  [37] = {.lex_state = 33},
  [38] = {.lex_state = 33},
  [39] = {.lex_state = 33},
  [40] = {.lex_state = 33},
  [41] = {.lex_state = 33},
  [42] = {.lex_state = 33},
  [43] = {.lex_state = 33},
  [44] = {.lex_state = 33},
  [45] = {.lex_state = 33},
  [46] = {.lex_state = 33},
  [47] = {.lex_state = 33},
  [48] = {.lex_state = 33},
  [49] = {.lex_state = 33},
  [50] = {.lex_state = 33},
  [51] = {.lex_state = 33},
  [52] = {.lex_state = 33},
  [53] = {.lex_state = 33},
  [54] = {.lex_state = 33},
  [55] = {.lex_state = 33},
  [56] = {.lex_state = 33},
  [57] = {.lex_state = 33},
  [58] = {.lex_state = 33},
  [59] = {.lex_state = 33},
  [60] = {.lex_state = 33},
  [61] = {.lex_state = 33},
  [62] = {.lex_state = 6},
  [63] = {.lex_state = 6},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 33},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 33},
  [76] = {.lex_state = 33},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 33},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 33},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 33},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 33},
  [98] = {.lex_state = 33},
  [99] = {.lex_state = 4},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_fun] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_unit] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [sym_char] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(90),
    [sym__statement] = STATE(2),
    [sym_function_declaration] = STATE(2),
    [sym__expression] = STATE(52),
    [sym_literal] = STATE(32),
    [sym_bool] = STATE(29),
    [sym_unit] = STATE(29),
    [sym_block] = STATE(32),
    [sym_function_propagation] = STATE(32),
    [sym_call] = STATE(32),
    [sym_variable_declaration] = STATE(32),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_fun] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_unit] = ACTIONS(9),
    [sym_int] = ACTIONS(11),
    [sym_float] = ACTIONS(13),
    [sym_char] = ACTIONS(13),
    [sym_string] = ACTIONS(13),
    [anon_sym_true] = ACTIONS(15),
    [anon_sym_false] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(17),
    [anon_sym_let] = ACTIONS(19),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(5), 1,
      anon_sym_fun,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    STATE(52), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(4), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [50] = 13,
    ACTIONS(23), 1,
      anon_sym_fun,
    ACTIONS(26), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_unit,
    ACTIONS(32), 1,
      sym_int,
    ACTIONS(41), 1,
      anon_sym_LBRACE,
    ACTIONS(44), 1,
      anon_sym_RBRACE,
    ACTIONS(46), 1,
      anon_sym_let,
    STATE(60), 1,
      sym__expression,
    ACTIONS(38), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(35), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(3), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [100] = 13,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      anon_sym_fun,
    ACTIONS(52), 1,
      sym_identifier,
    ACTIONS(55), 1,
      anon_sym_unit,
    ACTIONS(58), 1,
      sym_int,
    ACTIONS(67), 1,
      anon_sym_LBRACE,
    ACTIONS(70), 1,
      anon_sym_let,
    STATE(52), 1,
      sym__expression,
    ACTIONS(64), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(61), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(4), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [150] = 13,
    ACTIONS(73), 1,
      anon_sym_fun,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(87), 1,
      anon_sym_RBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    STATE(60), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(8), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [200] = 13,
    ACTIONS(73), 1,
      anon_sym_fun,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(91), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(3), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [250] = 13,
    ACTIONS(73), 1,
      anon_sym_fun,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(93), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(6), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [300] = 13,
    ACTIONS(73), 1,
      anon_sym_fun,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(95), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(3), 3,
      sym__statement,
      sym_function_declaration,
      aux_sym_source_file_repeat1,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [350] = 11,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(97), 1,
      anon_sym_RPAREN,
    STATE(65), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [392] = 11,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(99), 1,
      anon_sym_RPAREN,
    STATE(67), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [434] = 9,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(27), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [471] = 9,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(103), 1,
      sym_identifier,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(42), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [508] = 10,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    STATE(57), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [547] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    STATE(68), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [586] = 9,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(105), 1,
      sym_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(33), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [623] = 10,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    STATE(58), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [662] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    STATE(53), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [701] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    STATE(61), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [740] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    STATE(54), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [779] = 10,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    STATE(59), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [818] = 10,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    STATE(56), 1,
      sym__expression,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(32), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [857] = 9,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(44), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [894] = 9,
    ACTIONS(9), 1,
      anon_sym_unit,
    ACTIONS(11), 1,
      sym_int,
    ACTIONS(17), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(109), 1,
      sym_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_bool,
      sym_unit,
    ACTIONS(13), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(34), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [931] = 10,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    STATE(55), 1,
      sym__expression,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(40), 5,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [970] = 9,
    ACTIONS(77), 1,
      anon_sym_unit,
    ACTIONS(79), 1,
      sym_int,
    ACTIONS(85), 1,
      anon_sym_LBRACE,
    ACTIONS(89), 1,
      anon_sym_let,
    ACTIONS(111), 1,
      sym_identifier,
    ACTIONS(83), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 2,
      sym_bool,
      sym_unit,
    ACTIONS(81), 3,
      sym_float,
      sym_char,
      sym_string,
    STATE(43), 6,
      sym__expression,
      sym_literal,
      sym_block,
      sym_function_propagation,
      sym_call,
      sym_variable_declaration,
  [1007] = 2,
    ACTIONS(115), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(113), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1029] = 2,
    ACTIONS(119), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(117), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1051] = 2,
    ACTIONS(123), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(121), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1073] = 2,
    ACTIONS(127), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(125), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1095] = 2,
    ACTIONS(131), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(129), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1117] = 2,
    ACTIONS(135), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(133), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1139] = 3,
    ACTIONS(141), 1,
      anon_sym_SEMI,
    ACTIONS(139), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(137), 9,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1163] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(145), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(143), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1189] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(153), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(151), 8,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1215] = 2,
    ACTIONS(157), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(155), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1237] = 2,
    ACTIONS(161), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(159), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1259] = 2,
    ACTIONS(165), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(163), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1281] = 2,
    ACTIONS(169), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(167), 10,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
  [1303] = 2,
    ACTIONS(161), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(159), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1323] = 3,
    ACTIONS(171), 1,
      anon_sym_SEMI,
    ACTIONS(137), 7,
      anon_sym_LPAREN,
      anon_sym_COLON,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(139), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1345] = 2,
    ACTIONS(169), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(167), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1365] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(143), 6,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(145), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1389] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(151), 6,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(153), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1413] = 2,
    ACTIONS(119), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(117), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1433] = 2,
    ACTIONS(115), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(113), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1453] = 2,
    ACTIONS(131), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(129), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1473] = 2,
    ACTIONS(157), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(155), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1493] = 2,
    ACTIONS(165), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(163), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1513] = 2,
    ACTIONS(135), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(133), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1533] = 2,
    ACTIONS(127), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(125), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1553] = 2,
    ACTIONS(123), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
    ACTIONS(121), 8,
      anon_sym_LPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1573] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(177), 5,
      ts_builtin_sym_end,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
    ACTIONS(179), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1596] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(181), 5,
      ts_builtin_sym_end,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
    ACTIONS(183), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1619] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(185), 5,
      ts_builtin_sym_end,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
    ACTIONS(187), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1642] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(191), 5,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(189), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1665] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(191), 5,
      ts_builtin_sym_end,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
    ACTIONS(189), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1688] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(185), 5,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(187), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1711] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(181), 5,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(183), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1734] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(195), 5,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(193), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1757] = 4,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(175), 1,
      anon_sym_COLON,
    ACTIONS(177), 5,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    ACTIONS(179), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1780] = 4,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(195), 5,
      ts_builtin_sym_end,
      sym_float,
      sym_char,
      sym_string,
      anon_sym_LBRACE,
    ACTIONS(193), 7,
      anon_sym_fun,
      sym_identifier,
      anon_sym_unit,
      sym_int,
      anon_sym_true,
      anon_sym_false,
      anon_sym_let,
  [1803] = 3,
    ACTIONS(199), 1,
      anon_sym_LBRACK,
    STATE(100), 1,
      sym_type_annotation,
    ACTIONS(197), 7,
      anon_sym_void,
      anon_sym_unit,
      anon_sym_bool,
      anon_sym_int,
      anon_sym_float,
      anon_sym_char,
      anon_sym_string,
  [1819] = 3,
    ACTIONS(199), 1,
      anon_sym_LBRACK,
    STATE(69), 1,
      sym_type_annotation,
    ACTIONS(197), 7,
      anon_sym_void,
      anon_sym_unit,
      anon_sym_bool,
      anon_sym_int,
      anon_sym_float,
      anon_sym_char,
      anon_sym_string,
  [1835] = 2,
    ACTIONS(203), 1,
      anon_sym_EQ,
    ACTIONS(201), 4,
      anon_sym_RPAREN,
      anon_sym_EQ_GT,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1845] = 5,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(205), 1,
      anon_sym_RPAREN,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    STATE(77), 1,
      aux_sym_call_repeat1,
  [1861] = 2,
    ACTIONS(211), 1,
      anon_sym_EQ,
    ACTIONS(209), 4,
      anon_sym_RPAREN,
      anon_sym_EQ_GT,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1871] = 5,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(213), 1,
      anon_sym_RPAREN,
    STATE(71), 1,
      aux_sym_call_repeat1,
  [1887] = 3,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    ACTIONS(149), 1,
      anon_sym_COLON,
    ACTIONS(215), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [1898] = 2,
    ACTIONS(219), 1,
      anon_sym_EQ,
    ACTIONS(217), 3,
      anon_sym_RPAREN,
      anon_sym_EQ_GT,
      anon_sym_COMMA,
  [1907] = 3,
    ACTIONS(221), 1,
      anon_sym_RPAREN,
    ACTIONS(223), 1,
      anon_sym_COMMA,
    STATE(80), 1,
      aux_sym_parameters_repeat1,
  [1917] = 3,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(225), 1,
      anon_sym_RPAREN,
    STATE(72), 1,
      aux_sym_call_repeat1,
  [1927] = 3,
    ACTIONS(215), 1,
      anon_sym_RPAREN,
    ACTIONS(227), 1,
      anon_sym_COMMA,
    STATE(72), 1,
      aux_sym_call_repeat1,
  [1937] = 3,
    ACTIONS(230), 1,
      anon_sym_EQ_GT,
    ACTIONS(232), 1,
      anon_sym_COLON,
    STATE(94), 1,
      sym_type_annotation_after_colon,
  [1947] = 3,
    ACTIONS(234), 1,
      anon_sym_RPAREN,
    ACTIONS(236), 1,
      sym_identifier,
    STATE(101), 1,
      sym_parameters,
  [1957] = 3,
    ACTIONS(232), 1,
      anon_sym_COLON,
    ACTIONS(238), 1,
      anon_sym_EQ_GT,
    STATE(88), 1,
      sym_type_annotation_after_colon,
  [1967] = 3,
    ACTIONS(232), 1,
      anon_sym_COLON,
    ACTIONS(240), 1,
      anon_sym_EQ_GT,
    STATE(98), 1,
      sym_type_annotation_after_colon,
  [1977] = 3,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(242), 1,
      anon_sym_RPAREN,
    STATE(72), 1,
      aux_sym_call_repeat1,
  [1987] = 3,
    ACTIONS(232), 1,
      anon_sym_COLON,
    ACTIONS(244), 1,
      anon_sym_EQ_GT,
    STATE(97), 1,
      sym_type_annotation_after_colon,
  [1997] = 3,
    ACTIONS(223), 1,
      anon_sym_COMMA,
    ACTIONS(246), 1,
      anon_sym_RPAREN,
    STATE(70), 1,
      aux_sym_parameters_repeat1,
  [2007] = 3,
    ACTIONS(248), 1,
      anon_sym_RPAREN,
    ACTIONS(250), 1,
      anon_sym_COMMA,
    STATE(80), 1,
      aux_sym_parameters_repeat1,
  [2017] = 3,
    ACTIONS(232), 1,
      anon_sym_COLON,
    ACTIONS(253), 1,
      anon_sym_EQ,
    STATE(93), 1,
      sym_type_annotation_after_colon,
  [2027] = 3,
    ACTIONS(236), 1,
      sym_identifier,
    ACTIONS(255), 1,
      anon_sym_RPAREN,
    STATE(95), 1,
      sym_parameters,
  [2037] = 3,
    ACTIONS(232), 1,
      anon_sym_COLON,
    ACTIONS(257), 1,
      anon_sym_EQ,
    STATE(96), 1,
      sym_type_annotation_after_colon,
  [2047] = 2,
    ACTIONS(232), 1,
      anon_sym_COLON,
    STATE(79), 1,
      sym_type_annotation_after_colon,
  [2054] = 1,
    ACTIONS(259), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2059] = 2,
    ACTIONS(232), 1,
      anon_sym_COLON,
    STATE(85), 1,
      sym_type_annotation_after_colon,
  [2066] = 1,
    ACTIONS(261), 1,
      sym_identifier,
  [2070] = 1,
    ACTIONS(263), 1,
      anon_sym_EQ_GT,
  [2074] = 1,
    ACTIONS(265), 1,
      anon_sym_LPAREN,
  [2078] = 1,
    ACTIONS(267), 1,
      ts_builtin_sym_end,
  [2082] = 1,
    ACTIONS(269), 1,
      sym_identifier,
  [2086] = 1,
    ACTIONS(271), 1,
      sym_identifier,
  [2090] = 1,
    ACTIONS(273), 1,
      anon_sym_EQ,
  [2094] = 1,
    ACTIONS(275), 1,
      anon_sym_EQ_GT,
  [2098] = 1,
    ACTIONS(277), 1,
      anon_sym_RPAREN,
  [2102] = 1,
    ACTIONS(279), 1,
      anon_sym_EQ,
  [2106] = 1,
    ACTIONS(281), 1,
      anon_sym_EQ_GT,
  [2110] = 1,
    ACTIONS(283), 1,
      anon_sym_EQ_GT,
  [2114] = 1,
    ACTIONS(285), 1,
      sym_identifier,
  [2118] = 1,
    ACTIONS(287), 1,
      anon_sym_RBRACK,
  [2122] = 1,
    ACTIONS(289), 1,
      anon_sym_RPAREN,
  [2126] = 1,
    ACTIONS(291), 1,
      anon_sym_LPAREN,
  [2130] = 1,
    ACTIONS(293), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 150,
  [SMALL_STATE(6)] = 200,
  [SMALL_STATE(7)] = 250,
  [SMALL_STATE(8)] = 300,
  [SMALL_STATE(9)] = 350,
  [SMALL_STATE(10)] = 392,
  [SMALL_STATE(11)] = 434,
  [SMALL_STATE(12)] = 471,
  [SMALL_STATE(13)] = 508,
  [SMALL_STATE(14)] = 547,
  [SMALL_STATE(15)] = 586,
  [SMALL_STATE(16)] = 623,
  [SMALL_STATE(17)] = 662,
  [SMALL_STATE(18)] = 701,
  [SMALL_STATE(19)] = 740,
  [SMALL_STATE(20)] = 779,
  [SMALL_STATE(21)] = 818,
  [SMALL_STATE(22)] = 857,
  [SMALL_STATE(23)] = 894,
  [SMALL_STATE(24)] = 931,
  [SMALL_STATE(25)] = 970,
  [SMALL_STATE(26)] = 1007,
  [SMALL_STATE(27)] = 1029,
  [SMALL_STATE(28)] = 1051,
  [SMALL_STATE(29)] = 1073,
  [SMALL_STATE(30)] = 1095,
  [SMALL_STATE(31)] = 1117,
  [SMALL_STATE(32)] = 1139,
  [SMALL_STATE(33)] = 1163,
  [SMALL_STATE(34)] = 1189,
  [SMALL_STATE(35)] = 1215,
  [SMALL_STATE(36)] = 1237,
  [SMALL_STATE(37)] = 1259,
  [SMALL_STATE(38)] = 1281,
  [SMALL_STATE(39)] = 1303,
  [SMALL_STATE(40)] = 1323,
  [SMALL_STATE(41)] = 1345,
  [SMALL_STATE(42)] = 1365,
  [SMALL_STATE(43)] = 1389,
  [SMALL_STATE(44)] = 1413,
  [SMALL_STATE(45)] = 1433,
  [SMALL_STATE(46)] = 1453,
  [SMALL_STATE(47)] = 1473,
  [SMALL_STATE(48)] = 1493,
  [SMALL_STATE(49)] = 1513,
  [SMALL_STATE(50)] = 1533,
  [SMALL_STATE(51)] = 1553,
  [SMALL_STATE(52)] = 1573,
  [SMALL_STATE(53)] = 1596,
  [SMALL_STATE(54)] = 1619,
  [SMALL_STATE(55)] = 1642,
  [SMALL_STATE(56)] = 1665,
  [SMALL_STATE(57)] = 1688,
  [SMALL_STATE(58)] = 1711,
  [SMALL_STATE(59)] = 1734,
  [SMALL_STATE(60)] = 1757,
  [SMALL_STATE(61)] = 1780,
  [SMALL_STATE(62)] = 1803,
  [SMALL_STATE(63)] = 1819,
  [SMALL_STATE(64)] = 1835,
  [SMALL_STATE(65)] = 1845,
  [SMALL_STATE(66)] = 1861,
  [SMALL_STATE(67)] = 1871,
  [SMALL_STATE(68)] = 1887,
  [SMALL_STATE(69)] = 1898,
  [SMALL_STATE(70)] = 1907,
  [SMALL_STATE(71)] = 1917,
  [SMALL_STATE(72)] = 1927,
  [SMALL_STATE(73)] = 1937,
  [SMALL_STATE(74)] = 1947,
  [SMALL_STATE(75)] = 1957,
  [SMALL_STATE(76)] = 1967,
  [SMALL_STATE(77)] = 1977,
  [SMALL_STATE(78)] = 1987,
  [SMALL_STATE(79)] = 1997,
  [SMALL_STATE(80)] = 2007,
  [SMALL_STATE(81)] = 2017,
  [SMALL_STATE(82)] = 2027,
  [SMALL_STATE(83)] = 2037,
  [SMALL_STATE(84)] = 2047,
  [SMALL_STATE(85)] = 2054,
  [SMALL_STATE(86)] = 2059,
  [SMALL_STATE(87)] = 2066,
  [SMALL_STATE(88)] = 2070,
  [SMALL_STATE(89)] = 2074,
  [SMALL_STATE(90)] = 2078,
  [SMALL_STATE(91)] = 2082,
  [SMALL_STATE(92)] = 2086,
  [SMALL_STATE(93)] = 2090,
  [SMALL_STATE(94)] = 2094,
  [SMALL_STATE(95)] = 2098,
  [SMALL_STATE(96)] = 2102,
  [SMALL_STATE(97)] = 2106,
  [SMALL_STATE(98)] = 2110,
  [SMALL_STATE(99)] = 2114,
  [SMALL_STATE(100)] = 2118,
  [SMALL_STATE(101)] = 2122,
  [SMALL_STATE(102)] = 2126,
  [SMALL_STATE(103)] = 2130,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 3, 0, 1),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 3, 0, 1),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_propagation, 3, 0, 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_propagation, 3, 0, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unit, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unit, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 5, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 5, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 4, 0, 4),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 4, 0, 4),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 2, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 5, 0, 5),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 5, 0, 5),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 7, 0, 8),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 7, 0, 8),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 7, 0, 9),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 7, 0, 9),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 8, 0, 10),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 8, 0, 10),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 6, 0, 6),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 6, 0, 6),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 3, 0, 7),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_annotation, 3, 0, 7),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 1, 0, 3),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_annotation, 1, 0, 3),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_call_repeat1, 2, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation_after_colon, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_annotation_after_colon, 2, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [227] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_call_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 3, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [267] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_arcana(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
