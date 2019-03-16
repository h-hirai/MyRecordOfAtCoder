#include <iostream>
#include <vector>

int main() {
  size_t N;

  std::cin >> N;

  std::vector<size_t> cnt(27, 1);

  for (size_t i=0; i<N; i++) {
    char c;
    std::cin >> c;
    cnt[c-'a']++;
  }

  size_t ans = 1;

  for (char c='a'; c<='z'; c++) {
    ans *= cnt[c-'a'];
    ans %= 1000000007;
  }
  ans--;

  std::cout << ans << std::endl;

  return 0;
}
