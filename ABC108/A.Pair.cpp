#include <iostream>

int main() {
  size_t k;
  std::cin >> k;

  size_t ans = k % 2 == 1 ?
    (k / 2) * (k / 2 + 1) :
    (k / 2) * (k / 2);

  std::cout << ans << std::endl;

  return 0;
}
