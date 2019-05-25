#include <iostream>

using ll = long long;

int main() {
  ll r, D, x;

  std::cin >> r >> D >> x;

  for (int y=2001; y<2011; y++) {
    x = r * x - D;
    std::cout << x << std::endl;
  }

  return 0;
}
