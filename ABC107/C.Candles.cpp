#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

size_t calc(ssize_t l, ssize_t r) {
  size_t abs_l = std::abs(l);
  if (l >= 0) {
    return static_cast<size_t>(r);
  } else if (r <= 0) {
    return abs_l;
  }
  size_t min = std::min(abs_l, static_cast<size_t>(r));
  size_t max = std::max(abs_l, static_cast<size_t>(r));
  return 2 * min + max;
}


int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::vector<ssize_t> X(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> X[i];
  }

  size_t ans = calc(X[0], X[N-1]);

  for (size_t i=0; i<N-K+1; i++) {
    ans = std::min(ans, calc(X[i], X[i+K-1]));
  }

  std::cout << ans << std::endl;
  return 0;
}
