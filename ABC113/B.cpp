#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
  size_t N;
  double T, A;

  std::cin >> N;
  std::cin >> T >> A;

  std::vector<double> diffA(N);

  for (size_t i=0; i<N; i++) {
    double h;
    std::cin >> h;
    auto Ti = T - h * 0.006;
    diffA[i] = std::abs(A - Ti);
  }

  auto imin = std::min_element(diffA.begin(), diffA.end());
  auto ans = std::distance(diffA.begin(), imin) + 1;

  std::cout << ans << std::endl;

  return 0;
}
