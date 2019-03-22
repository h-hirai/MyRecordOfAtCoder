#include <iostream>

int main() {
  size_t H, W, h, w;

  std::cin >> H >> W >> h >> w;

  size_t ans = (H-h)*(W-w);

  std::cout << ans << std::endl;

  return 0;
}
