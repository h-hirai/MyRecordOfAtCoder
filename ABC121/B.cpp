#include <iostream>
#include <vector>

int main() {
  size_t N, M;
  int C;

  std::cin >> N >> M >> C;

  std::vector<int> B(M);

  for (size_t i=0; i<M; i++)
    std::cin >> B[i];

  size_t ans = 0;

  for (size_t i=0; i<N; i++) {
    auto calc = C;
    for (size_t j=0; j<M; j++) {
      int a;
      std::cin >> a;
      calc += a * B[j];
    }
    if (calc > 0) ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
