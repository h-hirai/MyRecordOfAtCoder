#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long A, B, C, X, Y;

  std::cin >> A;
  std::cin >> B;
  std::cin >> C;
  std::cin >> X;
  std::cin >> Y;

  std::vector<long> ans(3);
  ans[0] = A*X + B*Y;

  if (X>Y) {
    ans[1] = C*2*X;
    ans[2] = C*2*Y + A*(X-Y);
  } else {
    ans[1] = C*2*Y;
    ans[2] = C*2*X + B*(Y-X);
  }

  std::sort(ans.begin(), ans.end());

  std::cout << ans[0] << std::endl;

  return 0;
}
