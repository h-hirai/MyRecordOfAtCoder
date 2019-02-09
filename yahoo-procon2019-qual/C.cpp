#include <iostream>

using INT = long long;

int main() {
  INT K, A, B;

  std::cin >> K >> A >> B;

  INT ans = 0;

  if (A + 2 < B && K >= A + 1) {
    auto rest_K = K - A - 1;
    ans = B + (rest_K / 2 * (B - A));
    ans += rest_K % 2;
  } else {
    ans = 1 + K;
  }

  std::cout << ans << std::endl;

  return 0;
}
