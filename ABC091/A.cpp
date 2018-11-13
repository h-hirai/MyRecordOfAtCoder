#include <iostream>

int main() {
  long a, b, c;

  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

  if (a + b >= c)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
