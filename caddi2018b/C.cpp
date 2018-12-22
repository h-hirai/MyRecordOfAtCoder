#include <iostream>
#include <vector>
#include <map>
#include <cmath>

std::vector<size_t>
get_primes(size_t MaxPrime) {
  std::vector<size_t> primes;
  std::vector<bool> is_prime(MaxPrime+1, true);
  is_prime[0] = false;
  is_prime[1] = false;

  for (size_t i=2; i<=std::sqrt(MaxPrime); i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (size_t j=i*i; j<=MaxPrime; j+=i) {
        is_prime[j] = false;
      }
    }
  }

  for (size_t i=std::sqrt(MaxPrime)+1; i<=MaxPrime; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

std::map<size_t, size_t>
get_prime_factors(size_t N) {
  std::map<size_t, size_t> prime_factors;

  if (N<2) {
    prime_factors.insert(std::make_pair(N, 1));
    return prime_factors;
  }

  for (auto const p : get_primes(std::sqrt(N))) {
    while (N % p == 0) {
      prime_factors[p]++;
      N /= p;
    }
  }

  if (N > 1) prime_factors[N]++;

  return prime_factors;
}
int main() {
  size_t N, P;
  std::cin >> N >> P;

  size_t ans = 1;

  for (auto const & p : get_prime_factors(P)) {
    if (std::get<1>(p) >= N)
      ans *= std::get<0>(p);
  }

  std::cout << ans << std::endl;

  return 0;
}
