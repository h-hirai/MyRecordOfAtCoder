#include <iostream>

int main() {
  size_t N;

  size_t ans = 0;
  unsigned int prev;
  bool prev_changed = false;

  std::cin >> N;

  for (size_t i=0; i<N; i++) {
    unsigned int a;
    std::cin >> a;

    if (i>0) {
      if (prev_changed) {
        prev_changed = false;
      } else if (prev == a) {
        prev_changed = true;
        ans++;
      }
    }

    prev = a;
  }

  std::cout << ans << std::endl;

  return 0;
}
