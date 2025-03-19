#include "token.hpp"
#include <format>

auto Token::to_string() -> std::string {
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
  return std::format("{} {} null", type_to_str[static_cast<uint8_t>(type)],
                     lexeme);
}
