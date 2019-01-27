#include <iostream>

int main() {
  int N, A, B;

  std::cin >> N >> A >> B;

  std::cout << std::min(A, B) << ' '
            << std::max(0, (A + B) - N) << std::endl;

  return 0;
}
