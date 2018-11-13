#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for (int i=0; i<n; i++) {
    char c;
    std::cin >> c;

    if (c == 'Y') {
      std::cout << "Four" << std::endl;
      return 0;
    }
  }

  std::cout << "Three" << std::endl;

  return 0;
}
