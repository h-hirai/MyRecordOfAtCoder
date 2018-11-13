#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  if (S.length() == 3) {
    for (auto i=S.crbegin(); i!=S.crend(); i++) {
      std::cout << *i;
    }
  } else {
    std::cout << S;
  }
  std::cout << std::endl;

  return 0;
}
