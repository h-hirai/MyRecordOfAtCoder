#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using tree_t = std::vector<std::vector<int>>;

int main() {
  int N;

  std::cin >> N;

  tree_t tree(N);
  std::vector<std::pair<int, int>> edges;
  edges.reserve(N-1);

  for (int i=0; i<N-1; i++) {
    int a, b;
    std::cin >> a >> b;

    edges.emplace_back(a-1, b-1);

    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
  }

  std::vector<int> C(N);

  for (int i=0; i<N; i++) {
    std::cin >> C[i];
  }

  std::sort(C.begin(), C.end(), std::greater<int>());

  int root = std::distance(tree.cbegin(),
                           std::max_element(tree.cbegin(), tree.cend(),
                                            [](auto a, auto b) {
                                              return a.size() < b.size();
                                            }));
  std::queue<int> que;
  std::vector<int> ans(N);

  que.push(root);
  int i = 0;

  while(! que.empty()) {
    auto cur = que.front();
    que.pop();

    ans[cur] = C[i];
    i++;

    for (auto n: tree[cur]) {
      if (ans[n] == 0) que.push(n);
    }
  }

  int score = 0;

  for (auto p: edges) {
    int a, b;
    std::tie(a, b) = p;
    score += std::min(ans[a], ans[b]);
  }

  std::cout << score << std::endl;

  for (int i=0; i<N; i++) {
    std::cout << ans[i];
    if (i < N-1)
      std::cout << ' ';
    else
      std::cout << std::endl;
  }

  return 0;
}
