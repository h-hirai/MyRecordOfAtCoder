#include <iostream>

bool judge(int i) {
  int digit0 = i % 10;
  int digit1 = (i % 100) / 10;
  int digit3 = (i % 10000) / 1000;
  int digit4 = (i % 100000) / 10000;

  return digit4 == digit0 && digit3 == digit1;
}

int main() {
  int a, b;

  std::cin >> a;
  std::cin >> b;

  int ans=0;
  for (int i=a; i<=b; i++) {
    if (judge(i)) ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
