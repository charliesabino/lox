#include "scanner.h"
#include "token.h"
#include <format>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>

Scanner::Scanner(std::string &&filename) : filename(std::move(filename)) {
  std::ifstream file{filename};
  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();

  source = buffer.str();
}

[[nodiscard]] auto Scanner::is_at_end() const -> bool {
  return current >= source.size();
}

auto Scanner::advance() -> char { return source[current++]; }

auto Scanner::match(char expected) -> bool {
  if (is_at_end() || source[current] != expected) {
    return false;
  }
  current++;
  return true;
}

auto Scanner::peek() -> char {
  if (is_at_end()) {
    return '\0';
  }
  return source[current];
}

auto Scanner::add_token(const Token::Type type) -> void {
  std::string literal{};
  add_token(type, literal);
}

auto Scanner::add_token(const Token::Type type, const std::string &literal)
    -> void {
  tokens.emplace_back(type,
                      std::string_view(source.data() + start, current - start),
                      literal, line);
}

auto Scanner::scan_token() -> void {
  char c = advance();

  switch (c) {
  case '(':
    add_token(Token::Type::LEFT_PAREN);
    break;
  case ')':
    add_token(Token::Type::RIGHT_PAREN);
    break;
  case '{':
    add_token(Token::Type::LEFT_BRACE);
    break;
  case '}':
    add_token(Token::Type::RIGHT_BRACE);
    break;
  case ',':
    add_token(Token::Type::COMMA);
    break;
  case '.':
    add_token(Token::Type::DOT);
    break;
  case '-':
    add_token(Token::Type::MINUS);
    break;
  case '+':
    add_token(Token::Type::PLUS);
    break;
  case ';':
    add_token(Token::Type::SEMICOLON);
    break;
  case '*':
    add_token(Token::Type::STAR);
    break;
  case '!':
    add_token(match('=') ? Token::Type::BANG_EQUAL : Token::Type::BANG);
    break;
  case '=':
    add_token(match('=') ? Token::Type::EQUAL_EQUAL : Token::Type::EQUAL);
    break;
  case '<':
    add_token(match('=') ? Token::Type::LESS_EQUAL : Token::Type::LESS);
    break;
  case '>':
    add_token(match('=') ? Token::Type::GREATER_EQUAL : Token::Type::GREATER);
    break;
  case '/':
    if (match('/')) {
      while (peek() != '\n' && !is_at_end()) {
        advance();
      }
      break;
    }
    add_token(Token::Type::SLASH);
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    line++;
    break;
  default:
    std::cerr << std::format("[line {}] Error: Unexpected character: {}\n",
                             line, c);
    error = true;
    break;
  }
}

auto Scanner::scan_tokens() -> std::vector<Token> & {
  while (!is_at_end()) {
    start = current;
    scan_token();
  }
  std::string s, t;
  tokens.emplace_back(Token::Type::EOF, s, t, line);
  return tokens;
}
