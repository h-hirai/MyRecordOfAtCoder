#include <iostream>
#include <vector>
#include <map>
#include <set>

using INT = long long;

std::vector<INT>
get_primes(INT MaxPrime) {
  std::vector<INT> primes;
  std::vector<bool> is_prime(MaxPrime+1, true);
  is_prime[0] = false;
  is_prime[1] = false;

  size_t i=2;
  for (; i*i<=MaxPrime; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (size_t j=i*i; j<=MaxPrime; j+=i) {
        is_prime[j] = false;
      }
    }
  }

  for (; i<=MaxPrime; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

std::map<INT, INT>
get_prime_factors(INT const N) {
  std::map<INT, INT> prime_factors;

  // 空を返したほうがいい場合もある
  if (N<2) {
    prime_factors.insert(std::make_pair(N, 1));
    return prime_factors;
  }

  auto n = N;
  for (INT p=2; p*p<=N; p++) {
    while (n % p == 0) {
      prime_factors[p]++;
      n /= p;
    }
  }

  if (n > 1) prime_factors[n]++;

  return prime_factors;
}

std::set<INT> get_factors(INT n) {
  std::set<INT> ret;

  for (INT i=1; i*i<=n; i++) {
    if (n%i==0) {
      ret.insert(i);
      ret.insert(n/i);
    }
  }

  return ret;
}

int main() {
  INT n;
  std::cin >> n;

  for (auto p : get_primes(n)) {
    std::cout << p << '\n';
  }

  for (auto f : get_prime_factors(n)) {
    auto p = std::get<0>(f);
    auto k = std::get<1>(f);
    std::cout << p << ' ' << k << '\n';
  }

  for (auto f : get_factors(n)) {
    std::cout << f << '\n';
  }

  return 0;
}
