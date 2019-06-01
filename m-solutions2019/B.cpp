#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  int win = 0;

  for (auto c: S) if (c == 'o') win++;

  bool ans = 8-win <= 15-S.size();

  std::cout << (ans?"YES":"NO") << std::endl;

  return 0;
}
