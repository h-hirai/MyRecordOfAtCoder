#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<size_t> a(3);

  for (size_t i=0; i<3; i++)
    std::cin >> a[i];

  std::sort(a.begin(), a.end());

  auto ans = a[2] * 10 + a[1] + a[0];

  std::cout << ans << std::endl;

  return 0;
}
