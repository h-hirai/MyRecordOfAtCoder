#include <iostream>
#include <vector>
#include <algorithm>

bool judge(std::vector<int> const& xs,
           std::vector<int> const& ys) {
  auto mx = *std::max_element(xs.cbegin(), xs.cend());
  auto my = *std::min_element(ys.cbegin(), ys.cend());

  return mx < my;
}

int main() {
  int N, M, X, Y;

  std::cin >> N >> M >> X >> Y;

  std::vector<int> xs(N+1);
  std::vector<int> ys(M+1);

  for (size_t i=0; i<N; i++)
    std::cin >> xs[i];
  xs[N] = X;

  for (size_t i=0; i<M; i++)
    std::cin >> ys[i];
  ys[M] = Y;

  std::cout << (judge(xs, ys) ? "No War" : "War") << std::endl;

  return 0;
}
