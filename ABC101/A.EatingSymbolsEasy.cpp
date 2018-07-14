#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  int ans = 0;

  for (auto const c : S) {
    if (c == '+')
      ans++;
    else if (c == '-')
      ans--;
  }

  std::cout << ans << std::endl;

  return 0;
}
