#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>

ssize_t distance(ssize_t x1, ssize_t y1,
                 ssize_t x2, ssize_t y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

ssize_t height(ssize_t x, ssize_t y,
               ssize_t cx, ssize_t cy,
               ssize_t h) {
  return std::max(h - distance(x, y, cx, cy),
                  static_cast<ssize_t>(0));
}

int main() {
  ssize_t const Height = 100000000;
  ssize_t const Width = 101;

  ssize_t const cx = 39;
  ssize_t const cy = 39;

  std::mt19937 mt(19937);
  std::uniform_int_distribution<> rand100(0, 100);

  std::cout << 100 << std::endl;
  for (size_t i=0; i<100; i++) {
    size_t x = rand100(mt);
    size_t y = rand100(mt);
    std::cout << x << ' '
              << y << ' '
              << height(x, y, cx, cy, Height) << std::endl;
  }

  return 0;
}
