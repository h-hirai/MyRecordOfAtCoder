#include <iostream>
#include <vector>

int main() {
  size_t N;
  std::cin >> N;

  unsigned long long ans=0;

  for (auto i=0; i<N; i++) {
    unsigned long long a;
    std::cin >> a;
    ans += a-1;
  }

  std::cout << ans << std::endl;

  return 0;
}
