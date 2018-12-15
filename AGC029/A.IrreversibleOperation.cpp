#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  long long ans = 0;
  long long cnt_black = 0;

  for (auto const c : S) {
    if (c == 'B')
      cnt_black++;
    else
      ans += cnt_black;
  }

  std::cout << ans << std::endl;

  return 0;
}
