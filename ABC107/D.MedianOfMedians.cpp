#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

size_t calc(ssize_t l, ssize_t r) {
  size_t abs_l = std::abs(l);
  if (l < 0 && r > 0) {
    size_t min = std::min(abs_l, r);
    size_t max = std::max(abs_l, r);
    return 2 * min + max;
  } else if (l < 0) {
    return abs_l;
  } else {
    return r;
  }
}


int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::vector<ssize_t> X(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> X[i];
  }

  size_t ans = calc(X[i], X[N-1]);

  for (size_t i=0; i<N-K; i++) {
    size_t tmp = calc(X[i], X[i+K-1]);
    ans = std::min(ans, tmp);
  }

  std::cout << ans << std::endl;
  return 0;
}
