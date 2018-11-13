#include <iostream>

int main() {
  size_t A, B, K;

  std::cin >> A >> B >> K;

  for (size_t i=0; i<K; i++) {
    if (i%2 == 0) {
      A -= A%2;
      A /= 2;
      B += A;
    } else {
      B -= B%2;
      B /= 2;
      A += B;
    }
  }

  std::cout << A << ' ' << B << std::endl;

  return 0;
}
