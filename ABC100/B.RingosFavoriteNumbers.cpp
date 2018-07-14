#include <iostream>

int main() {
  unsigned long d, n;

  std::cin >> d;
  std::cin >> n;

  if (n != 100) {
    unsigned long ans = n;

    for (size_t i=0; i<d; i++)
      ans *= 100;

    std::cout << ans << std::endl;
  } else {
    switch (d) {
    case 0:
      std::cout << 101 << std::endl;
      break;
    case 1:
      std::cout << 10100 << std::endl;
      break;
    case 2:
      std::cout << 1010000 << std::endl;
      break;
    }
  }

  return 0;
}
