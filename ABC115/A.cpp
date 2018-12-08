#include <iostream>

int main() {
  size_t D;
  std::cin >> D;

  std::cout << "Christmas";
  for (; D<25; D++)
    std::cout << " Eve";
  std::cout << std::endl;

  return 0;
}
