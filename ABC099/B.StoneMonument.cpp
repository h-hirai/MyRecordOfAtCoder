#include <iostream>

int main() {
  long a, b;

  std::cin >> a;
  std::cin >> b;

  long const pos_b = b - a;
  long height_b = 0;

  for (long i=0; i<pos_b; i++) {
    height_b+=i+1;
  }

  std::cout << height_b - b << std::endl;

  return 0;
}
