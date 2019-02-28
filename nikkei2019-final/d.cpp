#include <iostream>
#include <vector>
#include <set>

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<size_t> T(M);
  std::vector<size_t> L(M);
  std::vector<size_t> R(M);

  for (size_t i=0; i<M; i++) {
    std::cin >> T[i];
    std::cin >> L[i];
    std::cin >> R[i];
    L[i]--;
  }

  std::set<size_t> set;
  for (size_t i=0; i<N; i++) {
    set.insert(i);
  }

  size_t ans = 0;

  for (ssize_t i=M-1; i>=0; i--) {
    for (auto it = set.lower_bound(L[i]);
         *it < R[i] && it != set.end();
         it = set.erase(it)) {
      ans += T[i];
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
