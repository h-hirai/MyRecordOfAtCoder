#include <iostream>

bool solv() {
  size_t N;
  std::cin >> N;

  for (size_t i=0; i<N; i++) {
    size_t a;
    std::cin >> a;
    if (a % 2 == 1) return true;
  }

  return false;
}


int main() {
  std::cout << (solv() ? "first" : "second") << std::endl;

  return 0;
}
