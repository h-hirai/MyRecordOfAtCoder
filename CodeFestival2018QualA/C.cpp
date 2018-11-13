#include <iostream>
#include <vector>
#include <algorithm>
// #include <numeric>

using ull = unsigned long long;

int main() {
  ull N, K;
  std::cin >> N >> K;

  std::vector<ull> DivableNums(N, 0);
  ull DivableNumSum = 0;

  for (ull i=0; i<N; i++) {
    ull A;
    std::cin >> A;
    while (A>0) {
      A /= 2;
      DivableNums[i]++;
    }

    DivableNumSum += DivableNums[i];

    std::cout << ' ' << DivableNums[i];
  }

  std::cout << std::endl;

  // ull Selectables = 0;
  // for (ull d : DivableNums) {
  //   Selectables += std::max(d, DivableNumSum - d);
  // }

  // std::size_t ans = std::accumulate(Cells.begin(), Cells.end(), 0);

  // std::cout << ans << std::endl;

  return 0;
}
