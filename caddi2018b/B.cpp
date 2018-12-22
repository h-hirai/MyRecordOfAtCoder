#include <iostream>

int main() {
  size_t N, H, W;
  std::cin >> N >> H >> W;

  size_t ans = 0;

  for (size_t i=0; i<N; i++) {
    size_t a, b;
    std::cin >> a >> b;

    if (a >= H && b >= W) ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
