#include <iostream>
#include <vector>

int main() {
  size_t N;
  std::cin >> N;

  std::vector<long> A(N);
  for (size_t i=0; i<N; i++) {
    std::cin >> A[i];
  }

  size_t ans = 0;
  size_t l = 0;
  long s = 0;
  long x = 0;

  for (size_t r=0; r<N; r++) {
    s += A[r];
    x ^= A[r];
    if (s != x)
      while (s != x) {
        s -= A[l];
        x ^= A[l];
        l++;
      }
    ans+=r-l+1;
  }

  std::cout << ans << std::endl;

  return 0;
}
