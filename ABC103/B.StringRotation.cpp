#include <iostream>
#include <string>

int main() {
  std::string S, T;
  std::cin >> S;
  std::cin >> T;

  for (auto i=0; i<S.length(); i++) {
    auto R = S.substr(i, S.length()) + S.substr(0, i);
    if (R == T) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }

  std::cout << "No" << std::endl;
  return 0;
}
