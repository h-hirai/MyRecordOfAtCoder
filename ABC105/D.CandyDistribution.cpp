#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<size_t> Mods(N+1);
  Mods[0] = 0;
  ll Sum = 0;
  for (size_t i=1; i<N+1; i++) {
    ll a;
    std::cin >> a;
    Sum += a;
    Mods[i] = Sum % M;
  }

  std::sort(Mods.begin(), Mods.end());

  ll ans = 0;
  size_t cnt = 0;

  for (size_t i=1; i<N+1; i++) {
    if (Mods[i] == Mods[i-1]) {
      cnt++;
      ans+=cnt;
    } else {
      cnt=0;
    }
  }

  std::cout << ans << std::endl;
}

