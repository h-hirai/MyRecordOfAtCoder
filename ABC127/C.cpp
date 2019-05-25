#include <iostream>

int main() {
  int N, M;

  std::cin >> N >> M;

  int max_l = 0;
  int min_r = N+1;

  for (int i=0; i<M; i++) {
    int l, r;
    std::cin >> l >> r;

    max_l = std::max(max_l, l);
    min_r = std::min(min_r, r);
  }

  int ans = min_r - max_l + 1;

  std::cout << ans << std::endl;

  return 0;
}
