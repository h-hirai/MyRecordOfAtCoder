#include <iostream>
#include <string>

using ll = long long;

ll gcd(ll m, ll n) {
  if (n == 0) return m;
  else return gcd(n, m%n);
}

ll lcm(ll m, ll n) {
  return (m*n)/gcd(m,n);
}

bool judge(std::string const& s, std::string const& t, ll l) {
  ll step_s = l / t.length();
  ll step_t = l / s.length();

  for (ll is=0, it=0; is<s.length(); is+=step_s, it+=step_t) {
    if (s[is] != t[it]) return false;
  }

  return true;
}

int main() {
  size_t N, M;

  std::cin >> N >> M;

  std::string S, T;

  std::cin >> S >> T;

  ll L = lcm(M, N);

  std::cout << (judge(S, T, L) ? L : -1) << std::endl;

  return 0;
}
