#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  std::vector<int> B(N);

  for (int i=0; i<N; i++) {
    std::cin >> A[i];
  }

  for (int i=0; i<N; i++) {
    std::cin >> B[i];
  }

  int ans=0;

  for (int k=29; k>=0; k--) {
    int T = 1<<k;

    for (int j=0; j<N; j++) {
      B[j] %= 2*T;
    }
    std::sort(B.begin(), B.end());

    for (int i=0; i<N; i++) {
      int a = A[i] % (2*T);

      decltype(B)::iterator lb0 = std::lower_bound(B.begin(), B.end(), T-a);
      decltype(B)::iterator ub0 = std::upper_bound(B.begin(), B.end(), 2*T-a-1);
      decltype(B)::iterator lb1 = std::lower_bound(B.begin(), B.end(), 3*T-a);
      decltype(B)::iterator ub1 = std::upper_bound(B.begin(), B.end(), 4*T-a-1);

      if (((ub0 - lb0) + (ub1 - lb1)) % 2 == 1) {
        ans ^= T;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
