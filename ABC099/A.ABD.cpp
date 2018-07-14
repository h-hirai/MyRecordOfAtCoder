#include <iostream>

int main() {
  long n;

  std::cin >> n;

  std::cout << (n < 1000 ? "ABC" : "ABD") << std::endl;

  return 0;
}
