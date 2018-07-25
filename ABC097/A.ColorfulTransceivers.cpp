#include <iostream>
#include <complex>

int main() {
  long a, b, c, d;

  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  std::cin >> d;

  if (std::abs(a-c)<=d)
    std::cout << "Yes" << std::endl;
  else if (std::abs(a-b)<=d && std::abs(b-c)<=d)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
