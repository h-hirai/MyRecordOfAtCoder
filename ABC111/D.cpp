#include <iostream>
#include <vector>
#include <cmath>

int main() {
  size_t N;
  std::cin >> N;

  std::vector<ssize_t> X(N);
  std::vector<ssize_t> Y(N);

  std::cin >> X[0];
  std::cin >> Y[0];

  size_t abs_x = std::abs(X[0]);
  size_t abs_y = std::abs(Y[0]);

  size_t max_m = abs_x + abs_y;

  bool is_even = (abs_x + abs_y) % 2 == 0;
  bool judge = true;

  for (size_t i=1; i<N; i++) {
    std::cin >> X[i];
    std::cin >> Y[i];

    abs_x = std::abs(X[i]);
    abs_y = std::abs(Y[i]);
    max_m = std::max(max_m, abs_x + abs_y);

    if (judge) {
      if (is_even)
        judge = (abs_x + abs_y) % 2 == 0;
      else
        judge = (abs_x + abs_y) % 2 == 1;
    }
  }

  if (! judge) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::cout << max_m << std::endl;
  for (size_t i=0; i<max_m; i++) {
    if (i > 0) std::cout << ' ';
    std::cout << 1;
  }
  std::cout << std::endl;

  for (size_t i=0; i<N; i++) {
    if (X[i]>0) {
      for (ssize_t x=0; x<X[i]; x++) {
        std::cout << 'R';
      }
    } else {
      for (ssize_t x=0; x>X[i]; x--) {
        std::cout << 'L';
      }
    }

    if (Y[i]>0) {
      for (ssize_t y=0; y<Y[i]; y++) {
        std::cout << 'U';
      }
    } else {
      for (ssize_t y=0; y>Y[i]; y--) {
        std::cout << 'D';
      }
    }

    size_t rest = max_m - std::abs(X[i]) - std::abs(Y[i]);

    for (ssize_t r=0; r<rest/2; r++) {
      std::cout << "DU";
    }

    std::cout << std::endl;
  }

  return 0;
}
