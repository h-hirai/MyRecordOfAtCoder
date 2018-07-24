#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> A(3);
  std::cin >> A[0];
  std::cin >> A[1];
  std::cin >> A[2];

  std::sort(A.begin(), A.end());

  std::cout << (A[1]-A[0] + A[2]-A[1]) << std::endl;

  return 0;
}
