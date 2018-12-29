#include <iostream>
#include <vector>
#include <map>

using ull = unsigned long long;
using Key_t = std::tuple<size_t, size_t, size_t>;

ull solv(size_t L, size_t loc, size_t ccw, size_t cw,
         std::vector<size_t> const& X, std::map<Key_t, ull>& memo) {
  Key_t key = std::make_tuple(loc, ccw, cw);
  if (memo.count(key) > 0) return memo.at(key);

  auto dist_ccw = (L + X[ccw] - loc) % L;
  auto dist_cw = (L + loc - X[cw]) % L;

  if (ccw == cw) return std::max(dist_ccw, dist_cw);

  auto rest_ccw = solv(L, X[ccw], ccw+1, cw, X, memo);
  auto rest_cw = solv(L, X[cw], ccw, cw-1, X, memo);

  auto ans = std::max(dist_ccw + rest_ccw, dist_cw + rest_cw);
  memo.insert(std::make_pair(key, ans));

  return ans;
}

int main() {
  size_t L, N;

  std::cin >> L >> N;

  std::vector<size_t> X(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> X[i];
  }

  std::map<Key_t, ull> memo;

  std::cout << solv(L, 0, 0, N-1, X, memo) << std::endl;

  return 0;
}
