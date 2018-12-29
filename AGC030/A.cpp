#include <iostream>

int main() {
  size_t A, B, C;

  std::cin >> A >> B >> C;

  auto detox = A + B;

  size_t ans = detox >= C ? C : detox + 1;

  ans += B;

  std::cout << ans << std::endl;

  return 0;
}
