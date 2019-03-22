#include <iostream>
#include <vector>
#include <algorithm>

using ull = unsigned long long;

int main() {
  size_t N, M;

  std::cin >> N >> M;

  std::vector<std::pair<ull, size_t>> table;
  table.reserve(N);

  for (size_t i=0; i<N; i++) {
    ull a;
    size_t b;
    std::cin >> a >> b;
    table.emplace_back(a, b);
  }

  std::sort(table.begin(), table.end());

  ull ans = 0;
  size_t cnt = M;

  for (auto p: table) {
    auto a = p.first;
    auto b = p.second;

    ans += a * std::min(b, cnt);

    if (b >= cnt) break;

    cnt -= b;
  }

  std::cout << ans << std::endl;

  return 0;
}
