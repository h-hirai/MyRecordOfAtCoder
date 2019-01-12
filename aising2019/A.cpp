#include <iostream>

int main() {
  size_t N, H, W;

  std::cin >> N >> H >> W;

  size_t ans = (N-H+1)*(N-W+1);

  std::cout << ans << std::endl;

  return 0;
}
