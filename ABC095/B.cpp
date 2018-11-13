#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long N, X;

  std::cin >> N;
  std::cin >> X;

  std::vector<long> M(N);

  long ans = 0;

  for (size_t i=0; i<N; i++) {
    std::cin >> M[i];
    ans += 1;
    X -= M[i];
  }

  std::sort(M.begin(), M.end());

  for (auto const& m : M) {
    if (X < m) break;
    ans += X / m;
    X = X % m;
  }

  std::cout << ans << std::endl;

  return 0;
}
