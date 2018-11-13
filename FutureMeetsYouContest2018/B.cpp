#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <cassert>

void calc(ssize_t N,
          std::vector<ssize_t>& A,
          std::vector<ssize_t>& Differs) {
  auto min_d = std::min_element(Differs.begin(), Differs.end());
  auto max_d = std::max_element(Differs.begin(), Differs.end());

  ssize_t i = std::distance(Differs.begin(), max_d);
  ssize_t k = std::distance(Differs.begin(), min_d);

  ssize_t v = std::min({N-A[i], A[k]-1, std::abs(*max_d), std::abs(*min_d)});

  std::cout << i+1 << ' '
            << i+1 << ' '
            << k+1 << ' '
            << k+1 << ' '
            << v << std::endl;
  // std::cout << "  *Debug* A[" << i << "]=" << A[i]
  //           << ", A[" << k << "]=" << A[k] << std::endl;

  A[i] -= v;
  Differs[i] -= v;

  assert(A[i] > 0);

  A[k] += v;
  Differs[k] += v;

  assert(A[k] < 30001);
}


int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::vector<ssize_t> A(N);
  std::vector<ssize_t> Differs(N);

  for (size_t i=1; i<N+1; i++) {
    std::cin >> A[i-1];
    Differs[i-1] = A[i-1] - i;
  }

  for (size_t i=0; i<K; i++)
    calc(N, A, Differs);

  return 0;
}
