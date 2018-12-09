#include <iostream>

int main() {
  size_t N;
  std::cin >> N;

  size_t max_price = 0;
  size_t sum = 0;

  for (size_t i=0; i<N; i++) {
    size_t p;
    std::cin >> p;
    max_price = std::max(p, max_price);
    sum += p;
  }

  std::cout << (sum - max_price / 2) << std::endl;

  return 0;
}
