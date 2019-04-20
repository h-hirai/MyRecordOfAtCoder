#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::string S;
  std::cin >> S;

  std::vector<int> acc_b(N+1);

  for (int i=0; i<N; i++)
    acc_b[i+1]=acc_b[i] + (S[i]=='#' ? 1 : 0);

  std::vector<int> acc_w(N+1);

  for (int i=N-1; i>=0; i--)
    acc_w[i]=acc_w[i+1] + (S[i]=='.' ? 1 : 0);

  int ans = N;

  for (int i=0; i<N+1; i++)
    ans = std::min(ans, acc_w[i] + acc_b[i]);

  std::cout << ans << std::endl;

  return 0;
}
