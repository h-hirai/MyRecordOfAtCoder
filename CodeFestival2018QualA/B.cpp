#include <iostream>
#include <vector>
#include <numeric>

int main() {
  size_t N, M, A, B;
  std::cin >> N >> M >> A >> B;

  std::vector<size_t> Cells(N, B);

  for (size_t i=0; i<M; i++) {
    size_t L, R;
    std::cin >> L >> R;
    for (size_t j=L-1; j<R; j++) {
      Cells[j] = A;
    }
  }

  std::size_t ans = std::accumulate(Cells.begin(), Cells.end(), 0);

  std::cout << ans << std::endl;

  return 0;
}
