#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

std::vector<unsigned int>
get_primes(unsigned int MaxPrime) {
  std::vector<unsigned int> primes;
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

std::map<unsigned int, size_t>
get_prime_factors(unsigned int N) {
  std::map<unsigned int, size_t> prime_factors;

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

std::vector<unsigned int>
get_factors(unsigned int N) {
  std::vector<unsigned int> factors(1, 1);

  for (auto const p : get_prime_factors(N)) {
    unsigned int const prime = std::get<0>(p);
    unsigned int const exp = std::get<1>(p);

    std::vector<unsigned int> mult_space(factors.size());
    std::copy(factors.begin(), factors.end(),
              mult_space.begin());

    for (size_t i=0; i<exp; i++) {
      std::transform(mult_space.begin(), mult_space.end(),
                     mult_space.begin(),
                     [=](unsigned int a){return a * prime;});
      std::copy(mult_space.begin(), mult_space.end(),
                std::back_inserter(factors));
    }
  }

  return factors;
}

int main() {
  unsigned int N, M;

  std::cin >> N >> M;

  auto factors = get_factors(M);
  std::sort(factors.begin(), factors.end());
  auto f = *std::find_if(factors.begin(), factors.end(),
                         [=](auto f){return f >= N;});

  std::cout << M / f << std::endl;

  return 0;
}
