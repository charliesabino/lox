#ifndef SCANNER_H
#define SCANNER_H

#include "token.hpp"
#include <string>
#include <string_view>
#include <vector>

class Scanner {
private:
  std::string_view filename;
  std::string source;
  std::vector<Token> tokens;
  uint32_t start{0};   // idx of first char in lexeme being scanned
  uint32_t current{0}; // idx of current char being considered
  uint32_t line{1};
  bool error{false};

  void tokenize();

  [[nodiscard]]
  auto is_at_end() const -> bool;

  [[nodiscard]]
  auto advance() -> char;
  [[nodiscard]]
  auto match(char expected) -> bool;
  [[nodiscard]]
  auto peek() -> char;
  auto add_token(Token::Type type) -> void;
  auto add_token(Token::Type type, const std::string &literal) -> void;
  auto scan_token() -> void;

public:
  explicit Scanner(std::string &&filename);

  auto scan_tokens() -> std::vector<Token> &;

  [[nodiscard]]
  auto has_error() const -> bool {
    return error;
  }
};

#endif // !SCANNER_H
