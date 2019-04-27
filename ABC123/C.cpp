#include <iostream>
#include <algorithm>

using ll = long long;

int main() {
  ll n, a, b, c, d, e;

  std::cin >> n >> a >> b >> c >> d >> e;

  ll minflow = std::min({a, b, c, d, e});
  ll time = n/minflow;
  if (n%minflow>0) time += 1;

  std::cout << time + 4 << std::endl;

  return 0;
}
