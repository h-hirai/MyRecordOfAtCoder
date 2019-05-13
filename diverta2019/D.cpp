#include <iostream>
#include <iomanip>

using ll = long long;

int main() {
  ll N;
  std::cin >> N;

  ll ans = 0;

  for (ll i=1; i*(i+2)<=N; i++) {
    if (N % i == 0) {
      ans += N / i - 1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
