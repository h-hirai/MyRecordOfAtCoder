#include <iostream>
#include <string>

int main() {
  std::string S;
  size_t w;

  std::cin >> S;
  std::cin >> w;

  size_t cnt = 0;
  for (char const c : S) {
    if (cnt == 0) std::cout << c;
    cnt++;
    if (cnt == w) cnt = 0;
  }

  std::cout << std::endl;

  return 0;
}
