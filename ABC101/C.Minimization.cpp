#include <iostream>

int main() {
  unsigned int N;
  unsigned int K;

  std::cin >> N;
  std::cin >> K;

  unsigned int ans = (N-1)/(K-1);
  if ((N-1)%(K-1)!=0) ans++;

  std::cout << ans << std::endl;

  return 0;
}
