#include <iostream>

int main() {
  unsigned int N;
  std::cin >> N;

  unsigned int max;
  unsigned int min;

  for (size_t i=0; i<N; i++) {
    unsigned int a;
    std::cin >> a;

    if (i==0) {
      max = a;
      min = a;
    }

    if (max < a) max = a;
    if (min > a) min = a;
  }

  std::cout << (max - min) << std::endl;

  return 0;
}
