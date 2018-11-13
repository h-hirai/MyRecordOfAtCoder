#include <iostream>
#include <vector>

long abs(long v) {
  return (v < 0) ? -v : v;
}

int main() {
  long N;

  std::cin >> N;

  std::vector<long> A(N+2);
  std::vector<long> memo(N+2);

  A[0] = 0;
  memo[0] = 0;
  for (long i=1; i<N+1; i++) {
    std::cin >> A[i];
    memo[i] = memo[i-1] + abs(A[i-1] - A[i]);
  }
  A[N+1] = 0;
  memo[N+1] = memo[N] + abs(A[N]);

  for (long i=1; i<N+1; i++) {
    long ans =
      abs(memo[i-1]-memo[0]) + abs(A[i+1]-A[i-1]) + abs(memo[N+1]-memo[i+1]);
    std::cout << ans << std::endl;
  }

  return 0;
}
