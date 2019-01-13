#include <iostream>

int main() {
  bool b1 = false;
  bool b9 = false;
  bool b7 = false;
  bool b4 = false;

  for (size_t i=0; i<4; i++) {
    size_t N;
    std::cin >> N;

    switch (N) {
    case 1:
      b1 = true;
      break;
    case 9:
      b9 = true;
      break;
    case 7:
      b7 = true;
      break;
    case 4:
      b4 = true;
      break;
    }
  }

  auto ans = b1 & b9 & b7 & b4;

  std::cout << (ans ? "YES" : "NO") << std::endl;

  return 0;
}
