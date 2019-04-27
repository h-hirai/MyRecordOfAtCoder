#include <iostream>

int main() {
  int A, B, T;

  std::cin >> A >> B >> T;

  int ans = T / A * B;

  std::cout << ans << std::endl;

  return 0;
}
