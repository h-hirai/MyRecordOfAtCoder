#include <iostream>
#include <vector>

int main() {
  unsigned long N;

  std::cin >> N;

  std::vector<long> A(N);

  for (size_t i=0; i<N; i++)
    std::cin >> A[i];

  size_t ans = 0;

  for (auto a : A) {
    while (a % 2 == 0) {
      ans++;
      a = a>>1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
