#include <iostream>

int main() {
  size_t A, B, C;

  std::cin >> A >> B >> C;

  std::cout << std::min(B/A, C) << std::endl;

  return 0;
}
