#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  int cnt = 0;
  int ans = 0;

  for (auto c: S) {
    if (c == '0') {
      if (cnt > 0) ans++;
      cnt--;
    } else if (c == '1') {
      if (cnt < 0) ans++;
      cnt++;
    }
  }

  std::cout << (ans * 2) << std::endl;

  return 0;
}
