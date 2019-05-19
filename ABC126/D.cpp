#include <iostream>
#include <vector>

void solv(int curr,
          std::vector<std::vector<std::pair<int, int>>> const& tree,
          std::vector<int>& ans) {
  for (auto n: tree[curr]) {
    auto v = n.first;
    auto w = n.second;

    if (ans[v] > 1) {
      if (w % 2 == 0) {
        ans[v] = ans[curr];
      } else {
        ans[v] = (ans[curr]+1)%2;
      }
      solv(v, tree, ans);
    }
  }
}

int main() {
  int N;

  std::cin >> N;

  std::vector<std::vector<std::pair<int, int>>> tree(N);

  for (int i=0; i<N-1; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    tree[u].emplace_back(v, w);
    tree[v].emplace_back(u, w);
  }

  std::vector<int> ans(N, 8);
  ans[0] = 0;
  solv(0, tree, ans);

  for (int a: ans) {
    std::cout << a << '\n';
  }

  return 0;
}
