#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  long ans = 700;

  for (auto const& c : S) {
    if (c == 'o') ans += 100;
  }

  std::cout << ans << std::endl;

  return 0;
}
