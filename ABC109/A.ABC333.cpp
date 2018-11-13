#include <iostream>

int main() {
  size_t A, B;
  std::cin >> A >> B;

  std::cout << ((A == 2 || B == 2) ? "No" : "Yes") << std::endl;

  return 0;
}
