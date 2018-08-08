#include <iostream>
#include <algorithm>

int main() {
  long C, D;
  std::cin >> C;
  std::cin >> D;

  long ans = 0;

  for (long c=140, d=170; c<D; c*=2, d*=2) {
    if (d<C) continue;
    ans += std::min(D, d) - std::max(C, c);
  }

  std::cout << ans << std::endl;

  return 0;
}
