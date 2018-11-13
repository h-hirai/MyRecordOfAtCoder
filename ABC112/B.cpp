#include <iostream>
#include <algorithm>

int main() {
  size_t N, T;

  std::cin >> N >> T;

  bool tle = true;
  size_t ans = 1000;

  for (size_t i=0; i<N; i++) {
    size_t c, t;
    std::cin >> c >> t;

    if (t <= T) {
      ans = std::min(ans, c);
      tle = false;
    }
  }

  if (tle)
    std::cout << "TLE" << std::endl;
  else
    std::cout << ans << std::endl;

  return 0;
}
