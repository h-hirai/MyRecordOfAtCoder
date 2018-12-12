#include <iostream>
#include <vector>

int main() {
  size_t N, M, Q;
  std::cin >> N >> M >> Q;

  std::vector<std::vector<size_t>> Table(N+1, std::vector<size_t>(N+1, 0));

  for (size_t i=0; i<M; i++) {
    size_t L, R;
    std::cin >> L >> R;

    for (size_t r=R; r<N+1; r++) {
      Table[L][r]++;
    }
  }

  for (size_t i=0; i<Q; i++) {
    size_t p, q;
    std::cin >> p >> q;

    size_t ans = 0;

    for (size_t l=p; l<q+1; l++) {
      ans += Table[l][q];
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
