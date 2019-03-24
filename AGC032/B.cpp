#include <iostream>
#include <vector>

int main() {
  size_t N;

  std::cin >> N;

  auto s_factor = N + (N+1)%2;

  std::vector<std::pair<size_t, size_t>> ans;

  for (size_t i=1; i<N; i++) {
    for (size_t j=i+1; j<N+1; j++) {
      if (j == s_factor-i) continue;
      ans.emplace_back(i, j);
    }
  }

  std::cout << ans.size() << '\n';
  for (auto const& p: ans)
    std::cout << p.first << ' ' << p.second << '\n';

  return 0;
}
