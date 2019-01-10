#include <iostream>
#include <vector>
#include <map>

using ull = unsigned long long;

static ull const P = 1000000007;

template<typename INT, INT P>
class Modulo {
  INT val;

  friend
  std::ostream&
  operator<<(std::ostream& os, Modulo const& m) {
    return os << m.val;
  }

  friend
  Modulo<INT, P>
  operator*(Modulo<INT, P> const& a, Modulo<INT, P> const& b) {
    return a.val * b.val;
  }

  static std::vector<INT> _facts;

public:
  Modulo(INT v) : val(v % P) {};

  Modulo<INT, P>& operator*=(Modulo<INT, P> const& other) {
    val *= other.val;
    val %= P;
    return *this;
  }

  static INT facts(size_t n) {
    auto s = _facts.size();
    if (s < n+1) {
      _facts.resize(n+1);
      for (size_t i=s; i<n+1; i++) {
        if (i==0) {
          _facts[0] = 1;
        } else {
          _facts[i] = (_facts[i-1] * i) % P;
        }
      }
    }
    return _facts[n];
  }
};

template<typename INT, INT P>
std::vector<INT> Modulo<INT, P>::_facts;

template <typename INT, INT P>
Modulo<INT, P>
power(INT a, INT b) {
  if (b == 0) {
    return 1;
  }

  if (b % 2 == 0) {
    auto d = power<INT, P>(a, b/2);
    return d*d;
  }

  return a * power<INT, P>(a, b-1);
}

template <typename INT, INT P>
Modulo<INT, P>
comb(INT n, INT k) {
  if (n<0 || k<0 || n<k) return 0;
  if (n==0 || k==0) return 1;

  auto a = Modulo<INT, P>::facts(n);
  auto b = Modulo<INT, P>::facts(k);
  auto c = Modulo<INT, P>::facts(n-k);

  return a * power<INT, P>(b, P-2) * power<INT, P>(c, P-2);;
}

std::map<ull, ull>
get_prime_factors(ull const N) {
  std::map<ull, ull> prime_factors;

  if (N<2) {
    // prime_factors.insert(std::make_pair(N, 1));
    return prime_factors;
  }

  auto n = N;
  for (ull p=2; p*p<=N; p++) {
    while (n % p == 0) {
      prime_factors[p]++;
      n /= p;
    }
  }

  if (n > 1) prime_factors[n]++;

  return prime_factors;
}

int main() {
  ull N, M;
  std::cin >> N >> M;

  Modulo<ull, P> ans(1);

  for (auto const& p : get_prime_factors(M)) {
    auto k = std::get<1>(p);
    ans *= comb<ull, P>(N+k-1, k);
  }

  std::cout << ans << std::endl;

  return 0;
}
