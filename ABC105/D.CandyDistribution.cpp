#include <iostream>
#include <vector>

using ll = long long;

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<ll> A(N+1);
  A[0] = 0;
  for (size_t i=1; i<N+1; i++) {
    ll a;
    std::cin >> a;
    A[i] = A[i-1] + a;
  }

  ll ans = 0;

  for (size_t i=0; i<N; i++) {
    for (size_t j=i+1; j<N+1; j++) {
      if ((A[j] - A[i]) % M == 0) ans++;
    }
  }

  std::cout << ans << std::endl;
}

