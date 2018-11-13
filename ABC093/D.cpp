#include <iostream>
#include <cmath>

int main() {
  long Q;
  std::cin >> Q;

  for (long i=0; i<Q; i++) {
    long A, B;

    std::cin >> A;
    std::cin >> B;

    long min = A < B ? A : B;
    long score = A*B;
    long center = static_cast<long>(std::sqrt(score-1));

    if (A == B || A-B == 1 || B-A == 1) {
      std::cout << 2 * (min - 1) << std::endl;
    } else {
      long ans = (min - 1) + center + (center - min);
      if (center*center == score-1) ans -= 1;
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
