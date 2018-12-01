#include <iostream>
#include <vector>

static constexpr size_t T = 1000;
static constexpr size_t N = 10;
static constexpr size_t M = 30000;

int main() {
  size_t _t, _n, _m;
  std::cin >> _t >> _n >> _m;

  std::vector<size_t> start_turn(M);
  std::vector<size_t> end_turn(M);
  std::vector<size_t> pay(M);
  std::vector<std::vector<size_t>> requirement(M, std::vector<size_t>(N));

  for (size_t i=0; i<M; i++) {
    std::cin >> start_turn[i];
    std::cin >> end_turn[i];
    std::cin >> pay[i];

    for (size_t j=0; j<N; j++) {
      std::cin >> requirement[i][j];
    }
  }

  for (size_t i=0; i<T; i++) {
    std::cout << 3 << std::endl;
  }

  return 0;
}
