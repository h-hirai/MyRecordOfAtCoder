#include <iostream>

int main() {
  int a, b, c, d, e, k;
  std::cin >> a >> b >> c >> d >> e >> k;

  std::cout << (e-a > k ? ":(" : "Yay!") << std::endl;

  return 0;
}
