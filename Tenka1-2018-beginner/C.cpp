#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t N;

  std::cin >> N;

  std::vector<size_t> A(N);

  for (size_t i=0; i<N; i++)
    std::cin >> A[i];

  std::sort(A.begin(), A.end());

  auto i_min = A.begin();
  auto i_max = std::prev(A.end());

  auto i_med = N%2==1 ? std::next(i_min, N/2) : A.end();

  unsigned long long ans = *i_max - *i_min;

  while (true) {
    std::advance(i_max, -1);
    if (i_min == i_max) break;
    if (i_max == i_med) {
      ans += std::max(*i_max - *i_min,
                      *std::next(i_max) - *i_max);
    } else {
      ans += *i_max - *i_min;
    }

    std::advance(i_min, 1);
    if (i_min == i_max) break;
    ans += *std::next(i_max) - *i_min;

    std::advance(i_min, 1);
    if (i_min == i_max) break;
    if (i_min == i_med) {
      ans += std::max(*i_max - *i_min,
                      *i_min - *std::prev(i_min));
    } else {
      ans += *i_max - *i_min;
    }

    std::advance(i_max, -1);
    if (i_min == i_max) break;
    ans += *i_max - *std::prev(i_min);
  }

  std::cout << ans << std::endl;

  return 0;
}
