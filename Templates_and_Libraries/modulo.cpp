#include <iostream>
#include <vector>

using INT = long long;

static INT const P = 1000000007;

template <INT P>
class Modulo;

template <INT P>
Modulo<P> power(INT, INT);

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
  operator+(Modulo<P> const& a, Modulo<P> const& b) {
    return a.val + b.val;
  }

  friend
  Modulo<P>
  operator*(Modulo<P> const& a, Modulo<P> const& b) {
    return a.val * b.val;
  }

  friend
  Modulo<P>
  operator-(Modulo<P> const& a, Modulo<P> const& b) {
    return P + a.val - b.val;
  }

  friend
  Modulo<P>
  operator/(Modulo<P> const& a, Modulo<P> const& b) {
    return a * power<P>(b.val, P-2);
  }

  static std::vector<INT> _facts;

public:
  Modulo(INT v) : val(v % P) {};

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
comb(INT n, INT r) {
  if (n<0 || r<0 || n<r) return 0;
  if (n==0 || r==0) return 1;

  if (n-r<r) r = n-r;

  Modulo<P> a=1;
  for (INT i=0; i<r; i++) a = a*(n-i);
  auto b = Modulo<P>::facts(r);

  return a / b;
}
