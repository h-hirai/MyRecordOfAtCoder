#include <iostream>
#include <map>
#include <cmath>

std::map<size_t, size_t>
get_prime_factors(size_t const N) {
  std::map<size_t, size_t> prime_factors;

  if (N<2) {
    prime_factors.insert(std::make_pair(N, 1));
    return prime_factors;
  }

  auto n = N;
  for (size_t p=2; p*p<=N; p++) {
    while (n % p == 0) {
      prime_factors[p]++;
      n /= p;
    }
  }

  if (n > 1) prime_factors[n]++;

  return prime_factors;
}
int main() {
  size_t N, P;
  std::cin >> N >> P;

  size_t ans = 1;

  for (auto const & p : get_prime_factors(P)) {
    auto n = std::get<1>(p);
    while (n >= N) {
      ans *= std::get<0>(p);
      n -= N;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
