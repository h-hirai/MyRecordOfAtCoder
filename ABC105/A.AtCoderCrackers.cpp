#include <iostream>

int main() {
  size_t n, k;
  std::cin >> n >> k;

  size_t ans = 0;

  if (n % k == 0)
    ans = 0;
  else
    ans = 1;

  std::cout << ans << std::endl;

  return 0;
}
