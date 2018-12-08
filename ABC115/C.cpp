#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::vector<size_t> H(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> H[i];
  }

  std::sort(H.begin(), H.end());
  size_t ans = H.back() - H.front();

  for (auto i=std::next(H.begin(), K-1);
       i != H.end();
       i++) {
    ans = std::min(ans, *i - *(std::prev(i, K-1)));
  }

  std::cout << ans << std::endl;

  return 0;
}
