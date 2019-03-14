#include <iostream>
#include <vector>

using INT = long long;

struct Solver {
  size_t const L;
  size_t const N;
  std::vector<INT> const& X;

  std::vector<std::vector<INT>> cache_L;
  std::vector<std::vector<INT>> cache_R;

  Solver(size_t L, size_t N, std::vector<INT> const& X)
    : L(L)
    , N(N)
    , X(X)
    , cache_L(N+1, std::vector<INT>(N+1, -1))
    , cache_R(N+1, std::vector<INT>(N+1, -1)) {}

  INT solv_main(size_t curr, size_t left, size_t right) {
    INT dist_to_left = (L + X[left+1] - X[curr]) % L;
    INT dist_to_right = (L + X[curr] - X[N-right]) % L;

    if (left + right < N) {
      INT ans_to_left = dist_to_left + from_left(left+1, right);
      INT ans_to_right = dist_to_right + from_right(left, right+1);
      return std::max(ans_to_left, ans_to_right);
    } else {
      return 0;
    }
  }

  INT from_left(size_t burned_left, size_t burned_right) {
    auto& cache = cache_L[burned_left][burned_right];
    if (cache >= 0) return cache;
    return cache = solv_main(burned_left, burned_left, burned_right);
  }

  INT from_right(size_t burned_left, size_t burned_right) {
    auto& cache = cache_R[burned_left][burned_right];
    if (cache >= 0) return cache;
    return cache = solv_main(N-burned_right+1, burned_left, burned_right);
  }

  INT solv() {
    return std::max(X[1] + from_left(1, 0), X[N+1]-X[N] + from_right(0, 1));
  }
};

int main() {
  size_t L, N;

  std::cin >> L >> N;

  std::vector<INT> X;
  X.reserve(N+2);

  X.push_back(0);
  for (size_t i=0; i<N; i++) {
    INT x;
    std::cin >> x;
    X.push_back(x);
  }
  X.push_back(L);

  std::cout << Solver(L, N, X).solv() << std::endl;

  return 0;
}
