#include <iostream>

using ll = long long;

static ll const P = 998244353;

ll facts[300001];

ll mod_power(ll a, ll b) {
  if (b == 0) {
    return 1;
  }

  if (b % 2 == 0) {
    auto d = mod_power(a, b/2);
    return (d*d) % P;
  }

  auto ret = (a * mod_power(a, b-1)) % P;

  return ret;
}

ll mod_comb(ll n, ll k) {
  if (n<0 || k<0 || n<k) return 0;
  if (n==0 || k==0) return 1;

  auto a=facts[n];
  auto b=facts[k];
  auto c=facts[n-k];
  auto ret=a*mod_power(b, P-2);
  ret %= P;
  ret *= mod_power(c, P-2);
  ret %= P;

  return ret;
}

int main() {
  ll N, A, B, K;

  std::cin >> N;
  std::cin >> A;
  std::cin >> B;
  std::cin >> K;

  facts[0] = 1;
  for (ll i=1; i<N+1; i++)
    facts[i] = (facts[i-1]*i)%P;

  ll ans = 0;

  for (ll a=0; a<N+1; a++) {
    if (K >= A * a && (K - A * a) % B == 0) {
      ll b=(K - A * a) / B;
      if (b>N) continue;
      ll c=mod_comb(N, a);
      ll d=mod_comb(N, b);
      // std::cout << N << 'C' << a << '=' << c << std::endl;
      // std::cout << N << 'C' << b << '=' << d << std::endl;
      ans += (c*d)%P;
      ans %= P;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
