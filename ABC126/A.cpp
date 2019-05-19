#include <iostream>
#include <locale>

int main() {
  std::locale l = std::locale::classic();

  int N, K;

  std::cin >> N >> K;

  for (int i=0; i<N; i++) {
    char c;
    std::cin >> c;

    if (i==K-1) {
      std::cout << std::tolower(c, l);
    } else {
      std::cout << c;
    }
  }

  std::cout << std::endl;

  return 0;
}
