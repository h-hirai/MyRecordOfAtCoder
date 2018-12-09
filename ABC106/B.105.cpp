#include <iostream>
#include <cmath>

size_t num_factor(size_t N) {
  size_t ans = 0;
  for (size_t i=1; i<std::sqrt(N)+1; i++) {
    if (N % i == 0) {
      if (N / i == i)
        ans += 1;
      else
        ans += 2;
    }
  }
  return ans;
}

int main() {
  size_t N;
  std::cin >> N;

  size_t ans = 0;

  for (size_t i=1; i<N+1; i+=2)
    if (num_factor(i) == 8) ans ++;

  std::cout << ans << std::endl;

  return 0;
}
