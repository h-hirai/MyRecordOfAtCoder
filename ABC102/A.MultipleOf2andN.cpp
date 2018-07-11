#include <iostream>

int main() {
  unsigned int N;
  std::cin >> N;

  if (N % 2 == 0)
    std::cout << N << std::endl;
  else
    std::cout << (N*2) << std::endl;

  return 0;
}
