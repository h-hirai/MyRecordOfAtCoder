#include <iostream>

int main() {
  size_t A, B, C;

  std::cin >> A >> B >> C;

  auto ans = A == B && B == C;

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}
