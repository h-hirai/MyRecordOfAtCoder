#include <iostream>
#include <algorithm>

int main() {
  size_t N, A, B;

  std::cin >> N >> A >> B;

  size_t P1=0;
  size_t P2=0;
  size_t P3=0;

  for (size_t i=0; i<N; i++) {
    size_t p;
    std::cin >> p;

    if (p > B)
      P3++;
    else if (p > A)
      P2++;
    else
      P1++;
  }

  size_t ans = std::min({P1, P2, P3});

  std::cout << ans << std::endl;

  return 0;
}
