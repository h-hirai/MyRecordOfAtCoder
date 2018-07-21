#include <iostream>
#include <algorithm>

int main() {
  long a, b;

  std::cin >> a;
  std::cin >> b;

  std::cout << std::max({a+b, a-b, a*b}) << std::endl;

  return 0;
}
