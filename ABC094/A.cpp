#include <iostream>

int main() {
  long A, B, X;

  std::cin >> A;
  std::cin >> B;
  std::cin >> X;

  if (A <= X && A+B >= X)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  return 0;
}
