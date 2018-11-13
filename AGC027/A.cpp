#include <iostream>
#include <vector>
#include <algorithm>

size_t solv(size_t N,
            size_t x,
            std::vector<size_t> const& A) {
  for (size_t i=0; i<N; i++) {
    if (A[i] > x) {
      return i;
    }
    x -= A[i];
  }

  if (x > 0) {
    return N-1;
  }

  return N;
}

int main() {
  size_t N, x;

  std::cin >> N;
  std::cin >> x;

  std::vector<size_t> A(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  std::cout << solv(N, x, A) << std::endl;

  return 0;
}
