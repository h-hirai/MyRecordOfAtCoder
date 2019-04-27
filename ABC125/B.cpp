#include <iostream>
#include <vector>

int main() {
  int N;

  std::cin >> N;

  std::vector<int> X(N);
  std::vector<int> C(N);

  for (int i=0; i<N; i++)
    std::cin >> X[i];

  for (int i=0; i<N; i++)
    std::cin >> C[i];

  int ans = 0;
  for (int i=0; i<N; i++) {
    if (X[i] - C[i] > 0)
      ans += X[i] - C[i];
  }

  std::cout << ans << std::endl;

  return 0;
}
