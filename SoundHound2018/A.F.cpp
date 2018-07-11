#include <iostream>

int main() {
  int a, b;
  std::cin >> a;
  std::cin >> b;

  if (a+b==15)
    std::cout << '+' << std::endl;
  else if (a*b==15)
    std::cout << '*' << std::endl;
  else
    std::cout << 'x' << std::endl;

  return 0;
}
