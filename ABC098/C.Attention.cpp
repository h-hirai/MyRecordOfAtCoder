#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>

int main() {
  long N;
  std::string S;

  std::cin >> N;
  std::cin >> S;

  std::vector<size_t> westers(N+1);
  std::vector<size_t> easters(N+1);

  westers[0] = 0;
  for (size_t i=1; i<N+1; i++) {
    westers[i] = westers[i-1] + (S[i-1] == 'W' ? 1 : 0);
  }

  easters[N] = 0;
  for (size_t i=N; i>0; i--) {
    easters[i-1] = easters[i] + (S[i-1] == 'E' ? 1 : 0);
  }

  // std::cout << ' ';
  // for (size_t i=0; i<N; i++) {
  //   std::cout << S[i];
  // }
  // std::cout << std::endl;

  // for (size_t i=0; i<N+1; i++) {
  //   std::cout << westers[i];
  // }
  // std::cout << std::endl;

  // for (size_t i=0; i<N+1; i++) {
  //   std::cout << easters[i];
  // }
  // std::cout << std::endl;

  size_t ans = N+1;

  for (size_t i=0; i<N+1; i++) {
    size_t n = westers[i] + easters[i];
    if (ans > n) ans = n;
  }

  std::cout << ans << std::endl;

  return 0;
}
