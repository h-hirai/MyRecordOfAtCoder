#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t N, M;
  std::cin >> N;
  std::cin >> M;

  std::vector<std::pair<size_t, size_t>> Reqs(M);

  for (auto i=0; i<M; i++) {
    size_t a, b;
    std::cin >> a;
    std::cin >> b;
    Reqs[i] = std::make_pair(a, b);
  }

  std::sort(Reqs.begin(), Reqs.end());

  size_t min_r = N;
  size_t ans = 1;

  for (auto r : Reqs) {
    if (r.first > min_r) {
      ans++;
      min_r = r.second - 1;
    } else {
      min_r = std::min(min_r, r.second - 1);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
