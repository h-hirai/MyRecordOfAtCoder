#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

bool comp_k_comb(long n, long k, long j) {
  uintmax_t numer = 1;
  uintmax_t denom = 1;

  for (long i=n-k; i>n-(k+j); i--) numer *= i;
  for (long i=k+j; i>k; i--) denom *= i;

  return numer > denom;
}

int main() {
  long N;

  std::cin >> N;
  std::vector<long> A(N);

  for (long i=0; i<N; i++)
    std::cin >> A[i];

  std::sort(A.begin(), A.end());

  long max_k=A[0];

  for (long idx_k=1; idx_k<N-1; idx_k++) {
    if (comp_k_comb(A[N-1], max_k, A[idx_k]-max_k))
      max_k = A[idx_k];
    else
      break;
  }

  std::cout << A[N-1] << ' ' << max_k << std::endl;

  return 0;
}
