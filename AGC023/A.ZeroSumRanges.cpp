#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t N;

  std::cin >> N;

  std::vector<long> A(N+1);

  A[0] = 0;
  for (size_t i=0; i<N; i++) {
    long a;
    std::cin >> a;

    A[i+1] = A[i] + a;
  }

  std::sort(A.begin(), A.end());

  size_t ans = 0;
  size_t cnt_same = 0;
  long prev = A[0];

  for (size_t i=1; i<N+1; i++) {
    if (prev == A[i]) {
      cnt_same++;
      ans+=cnt_same;
    } else {
      cnt_same = 0;
    }
    prev = A[i];
  }

  std::cout << ans << std::endl;

  return 0;
}
