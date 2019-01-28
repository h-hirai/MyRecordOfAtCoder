#include <iostream>
#include <vector>

using INT = long long;

static INT const P = 998244353;

template<INT P>
class Modulo {
  INT val;

  friend
  std::ostream&
  operator<<(std::ostream& os, Modulo const& m) {
    return os << m.val;
  }

  friend
  Modulo<P>
  operator*(Modulo<P> const& a, Modulo<P> const& b) {
    return a.val * b.val;
  }

  static std::vector<INT> _facts;

public:
  Modulo(INT v) : val(v % P) {};

  Modulo<P>& operator+=(Modulo<P> const& other) {
    val += other.val;
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

template<INT P>
std::vector<INT> Modulo<P>::_facts;

template <INT P>
Modulo<P>
power(INT a, INT b) {
  if (b == 0) {
    return 1;
  }

  if (b % 2 == 0) {
    auto d = power<P>(a, b/2);
    return d*d;
  }

  return a * power<P>(a, b-1);
}

template <INT P>
Modulo<P>
comb(INT n, INT k) {
  if (n<0 || k<0 || n<k) return 0;
  if (n==0 || k==0) return 1;

  auto a = Modulo<P>::facts(n);
  auto b = Modulo<P>::facts(k);
  auto c = Modulo<P>::facts(n-k);

  return a * power<P>(b, P-2) * power<P>(c, P-2);;
}
