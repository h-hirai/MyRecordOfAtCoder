#include <iostream>

int main() {
  size_t X;
  std::cin >> X;

  if (X == 7 || X == 5 || X == 3) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
