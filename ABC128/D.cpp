#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, K;

  std::cin >> N >> K;

  std::vector<int> D(N);

  for (int i=0; i<N; i++) std::cin >> D[i];

  int ans = 0;

  for (int kl=0; kl<=std::min(N, K); kl++) {
    for (int kr=0; kl+kr<=std::min(N, K); kr++) {
      // std::cerr << kl << ' ' << kr << ':';

      std::vector<int> gotten(kl);
      gotten.reserve(kl+kr);
      std::copy(D.begin(), std::next(D.begin(), kl), gotten.begin());
      std::copy(std::next(D.begin(), N-kr), D.end(), std::back_inserter(gotten));
      std::sort(gotten.begin(), gotten.end());

      // for (auto e: gotten) std::cerr << ' ' << e;
      // std::cerr << std::endl;

      int can_skip = K-kl-kr;
      int value = 0;

      for (auto v: gotten) {
        // std::cerr << ' ' << v;
        if (v < 0 && can_skip > 0) {
          // std::cerr << 'S';
          can_skip--;
          continue;
        }
        value += v;
      }
      // std::cerr << std::endl;
      // std::cerr << ' ' << value << std::endl;

      ans = std::max(ans, value);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
