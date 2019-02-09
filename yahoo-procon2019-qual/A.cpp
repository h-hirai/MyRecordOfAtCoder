#include <iostream>

int main() {
  size_t N, K;

  std::cin >> N >> K;

  std::cout << ((N+1)/2 >= K ? "YES" : "NO") << std::endl;

  return 0;
}
