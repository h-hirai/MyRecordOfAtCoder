#include <iostream>
#include <cmath>
#include <algorithm>

bool is753(size_t n) {
  size_t cnt7 = 0;
  size_t cnt5 = 0;
  size_t cnt3 = 0;

  while (n>0) {
    switch (n % 10) {
    case 7: cnt7++; break;
    case 5: cnt5++; break;
    case 3: cnt3++; break;
    default: return false;
    }
    n/=10;
  }
  return cnt7 > 0 && cnt5 > 0 && cnt3 > 0;
}

int main() {
  size_t N;

  std::cin >> N;

  size_t ans = 0;

  for (size_t i=1; i<N+1; i++) {
    if (is753(i)) ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
