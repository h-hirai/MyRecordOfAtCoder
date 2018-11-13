#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long A, B, C;

  std::cin >> A;
  std::cin >> B;
  std::cin >> C;

  std::vector<long> seq{A, B, C};
  std::sort(seq.begin(), seq.end());

  long diff21 = seq[2] - seq[1];
  long diff10 = seq[1] - seq[0];

  long ans = diff21;
  ans += diff10 / 2;
  ans += diff10 % 2 == 1 ? 2 : 0;

  std::cout << ans << std::endl;

  return 0;
}
