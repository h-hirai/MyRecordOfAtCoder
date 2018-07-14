#include <iostream>

int main() {
  unsigned int a, b;

  std::cin >> a;
  std::cin >> b;

  if (a <= 8 && b <= 8)
    std::cout << "Yay!" << std::endl;
  else
    std::cout << ":(" << std::endl;

  return 0;
}
