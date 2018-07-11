#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  long N;
  std::cin >> N;

  std::vector<long> B(N);
  for (long i=0; i<N; i++) {
    long a;
    std::cin >> a;

    B[i] = a - i - 1;
  }
  std::sort(B.begin(), B.end());

  long const median =
    (N%2==1) ? B[N/2] : (B[N/2-1] + B[N/2]) / 2;

  long ans = 0;
  for (auto const b : B) {
    ans += std::abs(b - median);
  }

  std::cout << ans << std::endl;

  return 0;
}
