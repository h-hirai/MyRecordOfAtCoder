#include <iostream>

int main() {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  int a = x2 - x1;
  int b = y2 - y1;

  int x3 = x2 - b;
  int y3 = y2 + a;
  int x4 = x3 - a;
  int y4 = y3 - b;

  std::cout << x3 << ' ' << y3 << ' '
            << x4 << ' ' << y4 << std::endl;

  return 0;
}
