#include <iostream>

int main() {
  long a, b;

  std::cin >> a;
  std::cin >> b;

  if (a > b)
    std::cout << (a-1) << std::endl;
  else
    std::cout << a << std::endl;

  return 0;
}
