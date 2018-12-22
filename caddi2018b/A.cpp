#include <iostream>
#include <string>

int main() {
  std::string N;
  std::cin >> N;

  size_t ans = 0;

  for (auto const c : N) {
    if (c == '2') ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
