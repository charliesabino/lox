#include "scanner.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  if (argc < 3) {
    std::cerr << "Usage: ./your_program tokenize <filename>" << '\n';
    return 1;
  }

  const std::string command = argv[1];

  if (command == "tokenize") {
    Scanner scanner{std::string(argv[2])};
    for (auto tokens = scanner.scan_tokens(); auto &token : tokens) {
      std::cout << token.to_string() << '\n';
    }
    if (scanner.has_error()) {
      return 65;
    }
  } else {
    std::cerr << "Unknown command: " << command << '\n';
    return 1;
  }

  return 0;
}
