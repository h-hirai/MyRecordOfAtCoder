#include <iostream>
#include <vector>

using ull = unsigned long long;

ull solv(size_t L, size_t loc, size_t ccw, size_t cw,
         std::vector<size_t> const& X) {
  auto dist_ccw = (L + X[ccw] - loc) % L;
  auto dist_cw = (L + loc - X[cw]) % L;

  if (ccw == cw) return std::max(dist_ccw, dist_cw);

  auto rest_ccw = solv(L, X[ccw], ccw+1, cw, X);
  auto rest_cw = solv(L, X[cw], ccw, cw-1, X);

  return std::max(dist_ccw + rest_ccw, dist_cw + rest_cw);
}

int main() {
  size_t L, N;

  std::cin >> L >> N;

  std::vector<size_t> X(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> X[i];
  }

  std::cout << solv(L, 0, 0, N-1, X) << std::endl;

  return 0;
}
