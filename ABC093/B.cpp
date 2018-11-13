#include <iostream>

int main() {
  long A, B, K;

  std::cin >> A;
  std::cin >> B;
  std::cin >> K;

  long i=A;

  for (; i<A+K && i<=B; i++)
    std::cout << i << std::endl;

  i = i>(B-K+1) ? i : B-K+1;

  for (; i<=B; i++)
    std::cout << i << std::endl;

  return 0;
}
