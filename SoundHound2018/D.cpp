#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <limits>

using Graph_t = std::vector<std::unordered_map<size_t, size_t>>;

constexpr size_t INF = std::numeric_limits<size_t>::max() / 2;

std::vector<size_t> calc_fare(Graph_t const& g, size_t start) {
  std::vector<size_t> ret(g.size(), INF);
  std::priority_queue<std::pair<size_t, size_t>> que;

  ret[start] = 0;
  que.emplace(0, start);

  while (! que.empty()) {
    size_t fare, u;
    std::tie(fare, u) = que.top();
    que.pop();

    for (auto const& p: g[u]) {
      size_t v, f;
      std::tie(v, f) = p;
      auto new_f = fare + f;

      if (new_f<ret[v]) {
        ret[v] = new_f;
        que.emplace(new_f, v);
      }
    }
  }

  return ret;
}

int main() {
  size_t n, m, s, t;
  std::cin >> n >> m >> s >> t;
  s--; t--;

  Graph_t g_y(n);
  Graph_t g_s(n);

  for (size_t i=0; i<m; i++) {
    size_t u, v, a, b;
    std::cin >> u >> v >> a >> b;
    u--; v--;
    g_y[u].emplace(v, a);
    g_s[u].emplace(v, b);
    g_y[v].emplace(u, a);
    g_s[v].emplace(u, b);
  }

  auto f_y = calc_fare(g_y, s);
  auto f_s = calc_fare(g_s, t);

  std::multiset<size_t> fare;
  for (size_t i=0; i<n; i++) {
    fare.insert(f_y[i]+f_s[i]);
  }

  for (size_t i=0; i<n; i++) {
    auto ans = 1000'000'000'000'000 - *fare.begin();
    std::cout << ans << '\n';
    fare.erase(f_y[i]+f_s[i]);
  }

  return 0;
}
