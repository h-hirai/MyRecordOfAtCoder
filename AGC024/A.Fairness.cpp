#include <iostream>

int main() {
  long A, B, C, K;

  std::cin >> A;
  std::cin >> B;
  std::cin >> C;
  std::cin >> K;

  if (K%2==1)
    std::cout << (B-A) << std::endl;
  else
    std::cout << (A-B) << std::endl;

  return 0;
}
