#include <iostream>
#include <vector>
#include <map>

using ll = long long;

int main() {
  ll N, M;

  std::cin >> N >> M;

  std::vector<ll> A(N);

  for (int i=0; i<N; i++) std::cin >> A[i];

  std::map<ll, ll, std::greater<ll>> nums;

  for (int i=0; i<M; i++) {
    ll b, c;
    std::cin >> b >> c;
    nums[c] += b;
  }

  for (int i=0; i<N; i++) nums[A[i]]++;

  ll ans = 0;

  for (auto p: nums) {
    ll b, c;
    std::tie(c, b) = p;

    if (N < b) {
      ans += N * c;
      break;
    } else {
      ans += b * c;
    }

    N -= b;
  }

  std::cout << ans << std::endl;

  return 0;
}
