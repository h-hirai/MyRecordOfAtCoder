#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using Graph_t = std::vector<std::unordered_map<size_t, size_t>>;

constexpr size_t INF = std::numeric_limits<size_t>::max() / 2;

std::vector<size_t> dijkstra(Graph_t const& g, size_t const start) {
  std::vector<size_t> ret(g.size(), INF);
  using P = std::pair<size_t, size_t>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;

  ret[start] = 0;
  que.emplace(0, start);

  while (! que.empty()) {
    auto p = que.top();
    que.pop();
    size_t const dist = p.first;
    size_t const u = p.second;

    if (dist > ret[u]) continue;

    for (auto const& q: g[u]) {
      size_t const v = q.first;
      size_t const d = q.second;

      auto const new_d = dist + d;

      if (new_d<ret[v]) {
        ret[v] = new_d;
        que.emplace(new_d, v);
      }
    }
  }

  return ret;
}

int main() {
  Graph_t g(6);

  g[0].emplace(1, 7);
  g[0].emplace(2, 9);
  g[0].emplace(5, 14);
  g[1].emplace(2, 10);
  g[1].emplace(3, 15);
  g[2].emplace(3, 11);
  g[2].emplace(5, 2);
  g[3].emplace(4, 6);
  g[4].emplace(5, 9);

  auto ds = dijkstra(g, 0);

  for (auto d: ds) {
    std::cout << d << std::endl;
  }

  return 0;
}
