#include <iostream>

using INT = long long;

int main() {
  INT K, A, B;

  std::cin >> K >> A >> B;

  if (A + 2 < B) {
    auto rest_K = K - A - 1;
    auto ans = B + (rest_K / 2 * (B - A));
    ans += rest_K % 2;

    std::cerr << rest_K << std::endl;
    std::cout << ans << std::endl;
  } else {
    auto ans = 1 + K;
    std::cout << ans << std::endl;
  }

  return 0;
}
