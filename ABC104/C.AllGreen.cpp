#include <iostream>
#include <vector>

int main() {
  size_t D;
  unsigned long G;
  std::cin >> D;
  std::cin >> G;

  std::vector<size_t> P(D);
  std::vector<unsigned long> C(D);

  size_t ans = 0;

  for (size_t i=0; i<D; i++) {
    std::cin >> P[i];
    std::cin >> C[i];

    ans += P[i];
  }

  for (size_t flags=0; flags<((1<<D)-1); flags++) {
    size_t max_i=0;
    size_t p=0;
    unsigned long score=0;
    for (size_t i=0; i<D; i++) {
      if ((flags>>i)%2==1) {
        p += P[i];
        score += 100*(i+1) * P[i];
        score += C[i];
      } else {
        max_i = i;
      }
    }

    if (score >= G) {
      ans = std::min(ans, p);
    } else {
      for (size_t i=0; i<P[max_i]-1; i++) {
        p++;
        score += 100*(max_i+1);
        if (score >= G) {
          ans = std::min(ans, p);
          break;
        }
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
