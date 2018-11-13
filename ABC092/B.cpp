#include <iostream>

int main() {
  long N, D, X;

  std::cin >> N;
  std::cin >> D;
  std::cin >> X;

  long ans = 0;

  for (long i=0; i<N; i++) {
    long A;
    std::cin >> A;
    ans += 1 + ((D-1) / A);
  }

  std::cout << (ans+X) << std::endl;

  return 0;
}
