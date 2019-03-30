#include <iostream>

int main() {
  size_t N = 100000;
  size_t Q = 100;

  std::cout << N << ' ' << Q << std::endl;

  for (size_t i=0; i<N; i++)
    std::cout << 'A';
  std::cout << std::endl;

  for (size_t i=0; i<Q; i++)
    std::cout << "A L\n";

  return 0;
}
