#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<long> A(3);

  std::cin >> A[0];
  std::cin >> A[1];
  std::cin >> A[2];

  long K;

  std::cin >> K;

  std::sort(A.begin(), A.end());

  A[2] <<= K;

  long ans = 0;

  for (auto const& a : A)
    ans += a;

  std::cout << ans << std::endl;

  return 0;
}
