#include <iostream>

int main() {
  int A, B;

  std::cin >> A >> B;

  if (A < 6)
    std::cout << 0 << std::endl;
  else if (A < 13)
    std::cout << B/2 << std::endl;
  else
    std::cout << B << std::endl;

  return 0;
}
