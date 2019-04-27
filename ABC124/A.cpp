#include <iostream>

int main() {
  int a, b;

  std::cin >> a >> b;

  int ans;

  if (a == b) {
    ans = a + b;
  } else {
    ans = std::max(a, b);
    ans += ans - 1;
  }

  std::cout << ans << std::endl;

  return 0;
}
