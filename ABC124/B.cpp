#include <iostream>

int main() {
  int N;

  std::cin >> N;

  int highest = 0;
  int ans = 0;

  for (int i=0; i<N; i++) {
    int H;
    std::cin >> H;

    if (highest <= H) {
      ans++;
      highest = H;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
