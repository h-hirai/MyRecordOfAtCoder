#include <iostream>
#include <string>

int main() {
  int N, K;
  std::cin >> N >> K;

  int ans = N - K + 1;

  std::cout << ans << std::endl;

  return 0;
}
