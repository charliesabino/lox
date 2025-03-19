#ifndef TOKEN_H
#define TOKEN_H

#include <array>
#include <cstdint>
#include <string>

#undef EOF

class Token {
public:
  enum class Type : uint8_t {
    // Single-character tokens. LEFT_PAREN,
    LEFT_PAREN = 0,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    // One or two character tokens.
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    // Literals.
    IDENTIFIER,
    STRING,
    NUMBER,

    // Keywords.
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    WHILE,
    VAR,
    EOF,
    NUM_TYPES,
  };

  Token(Type t, std::string_view lexeme, std::string_view literal,
        uint32_t line)
      : type{t}, lexeme{lexeme}, literal{literal}, line{line} {}

  auto to_string() -> std::string;

private:
  Type type;
  std::string_view lexeme;
  std::string_view literal;
  uint32_t line;
};

static const std::array type_to_str{
    "LEFT_PAREN", "RIGHT_PAREN",   "LEFT_BRACE", "RIGHT_BRACE", "COMMA",
    "DOT",        "MINUS",         "PLUS",       "SEMICOLON",   "SLASH",
    "STAR",       "BANG",          "BANG_EQUAL", "EQUAL",       "EQUAL_EQUAL",
    "GREATER",    "GREATER_EQUAL", "LESS",       "LESS_EQUAL",  "IDENTIFIER",
    "STRING",     "NUMBER",        "AND",        "CLASS",       "ELSE",
    "FALSE",      "FUN",           "FOR",        "IF",          "NIL",
    "OR",         "PRINT",         "RETURN",     "SUPER",       "THIS",
    "TRUE",       "WHILE",         "VAR",        "EOF",
};

#endif // !TOKEN_H
