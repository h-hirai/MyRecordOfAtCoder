#include <iostream>
#include <string>

int main() {
  size_t N;
  std::string S;

  std::cin >> N >> S;

  size_t R = 0;
  size_t B = 0;

  for (auto const c: S) {
    if (c == 'R')
      R++;
    else
      B++;
  }

  std::cout << (R > B ? "Yes" : "No") << std::endl;

  return 0;
}
