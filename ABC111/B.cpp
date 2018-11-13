#include <iostream>

int main() {
  size_t N;
  std::cin >> N;

  size_t i=111;
  for (; i<N; i+=111);

  std::cout << i << std::endl;

  return 0;
}
