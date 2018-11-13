#include <iostream>

int main() {
  long a, b, c, d;

  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  std::cin >> d;

  long ans = ((a < b ? a : b) + (c < d ? c : d));

  std::cout << ans << std::endl;

  return 0;
}
