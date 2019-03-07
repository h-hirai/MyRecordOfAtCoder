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

  INT from_left(size_t burned_left, size_t burned_right) {
    if (cache_L[burned_left][burned_right] >= 0)
      return cache_L[burned_left][burned_right];

    INT dist_to_left = (L + X[burned_left+1] - X[burned_left]) % L;
    INT dist_to_right = (L + X[burned_left] - X[N-burned_right]) % L;

    INT ans;

    if (burned_left + burned_right < N) {
      INT ans_to_left = dist_to_left + from_left(burned_left+1, burned_right);
      INT ans_to_right = dist_to_right + from_right(burned_left, burned_right+1);
      ans = std::max(ans_to_left, ans_to_right);
    } else {
      ans = 0;
    }

    return cache_L[burned_left][burned_right] = ans;
  }

  INT from_right(size_t burned_left, size_t burned_right) {
    if (cache_R[burned_left][burned_right] >= 0)
      return cache_R[burned_left][burned_right];

    INT dist_to_left = (L + X[burned_left+1] - X[N-burned_right+1]) % L;
    INT dist_to_right = (L + X[N-burned_right+1] - X[N-burned_right]) % L;

    INT ans;

    if (burned_left + burned_right < N) {
      INT ans_to_left = dist_to_left + from_left(burned_left+1, burned_right);
      INT ans_to_right = dist_to_right + from_right(burned_left, burned_right+1);
      ans = std::max(ans_to_left, ans_to_right);
    } else {
      ans = 0;
    }

    return cache_R[burned_left][burned_right] = ans;
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
