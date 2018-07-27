#include <iostream>
#include <cmath>

size_t primes[5555];

int main() {
  for (size_t i=2; i<std::sqrt(5555); i++) {
    if (primes[i] == 0) {
      for (size_t j=2; i*j<5555; j++) {
        primes[i*j] = 1;
      }
    }
  }

  size_t N;
  std::cin >> N;

  size_t n=0;

  for (size_t i=2; i<5555; i++) {
    if (primes[i] == 0 && i % 5 == 1) {
      std::cout << i;
      n++;

      if (n<N)
        std::cout << ' ';
      else
        break;
    }
  }

  std::cout << std::endl;

  return 0;
}
