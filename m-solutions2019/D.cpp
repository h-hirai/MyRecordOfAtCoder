#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

  std::sort(C.begin(), C.end());

  std::vector<int> inds(N);

  std::iota(inds.begin(), inds.end(), 0);

  std::sort(inds.begin(), inds.end(),
            [&](auto a, auto b) {
              return tree[a].size() < tree[b].size();
            });

  std::vector<int> ans(N);

  for (int i=0; i<N; i++) ans[inds[i]] = C[i];

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
