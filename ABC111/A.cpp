#include <iostream>

int main() {
  for (size_t i=0; i<3; i++) {
    char c;
    std::cin >> c;
    if (c == '1') std::cout << '9';
    else if (c == '9') std::cout << '1';
    else std::cout << c;
  }

  std::cout << std::endl;

  return 0;
}
