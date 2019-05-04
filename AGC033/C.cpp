#include <iostream>
#include <vector>
#include <queue>

// 参考: http://www.prefield.com/algorithm/graph/tree_diameter.html

std::pair<int, int>
search_farthest(std::vector<std::vector<int>> const& tree,
                int start) {
  size_t const N = tree.size();

  std::vector<bool> visited(N, false);
  std::vector<int> dist(N, N*2);
  std::queue<int> que;

  que.push(start);
  dist[start] = 0;

  int farthest = start;

  while (! que.empty()) {
    int curr = que.front();
    // std::cerr << curr << std::endl;
    visited[curr] = true;

    if (dist[curr] > dist[farthest]) {
      farthest = curr;
    }

    for (auto n: tree[curr]) {
      if (visited[n]) continue;
      dist[n] = dist[curr] + 1;
      que.push(n);
    }

    que.pop();
  }

  // std::cerr << farthest << "," << dist[farthest] << std::endl;
  return std::make_pair(farthest, dist[farthest]);
}

int main() {
  int N;
  std::cin >> N;

  std::vector<std::vector<int>> tree(N, std::vector<int>());

  for (int i=0; i<N-1; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  int farthest = search_farthest(tree, 0).first;
  int longest = search_farthest(tree, farthest).second;

  bool judge = longest % 3 == 1;

  // std::cerr << "Path: " << longest << std::endl;

  std::cout << (judge ? "Second" : "First") << std::endl;

  return 0;
}
