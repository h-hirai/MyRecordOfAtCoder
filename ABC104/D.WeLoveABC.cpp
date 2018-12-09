#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  size_t const N = S.length();

  std::vector<size_t> dp0(N+1);
  std::vector<size_t> dp1(N+1);
  std::vector<size_t> dp2(N+1);
  std::vector<size_t> dp3(N+1);

  dp0[N] = 0;
  dp1[N] = 0;
  dp2[N] = 0;
  dp3[N] = 1;

  for (ssize_t i=N-1; i>=0; i--) {
    if (S[i] == 'A') dp0[i] = dp0[i+1] + dp1[i+1];
    else if (S[i] == '?') dp0[i] = 3 * dp0[i+1] + dp1[i+1];
    else dp0[i] = dp0[i+1];

    if (S[i] == 'B') dp1[i] = dp1[i+1] + dp2[i+1];
    else if (S[i] == '?') dp1[i] = 3 * dp1[i+1] + dp2[i+1];
    else dp1[i] = dp1[i+1];

    if (S[i] == 'C') dp2[i] = dp2[i+1] + dp3[i+1];
    else if (S[i] == '?') dp2[i] = 3 * dp2[i+1] + dp3[i+1];
    else dp2[i] = dp2[i+1];

    if (S[i] == '?') dp3[i] = 3 * dp3[i+1];
    else dp3[i] = dp3[i+1];

    dp0[i] %= 1000000007;
    dp1[i] %= 1000000007;
    dp2[i] %= 1000000007;
    dp3[i] %= 1000000007;
  }

  std::cout << dp0[0] << std::endl;

  return 0;
}
