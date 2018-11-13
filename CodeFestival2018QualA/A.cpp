#include <iostream>

int main() {
  size_t A, B, C, S;
  std::cin >> A >> B >> C >> S;

  size_t sum = A + B + C;
  if (sum <= S && S <= sum + 3)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
