#include <iostream>
#include <vector>
#include <tuple>

using ll = long long;

std::tuple<ssize_t, ll>
simulate(ssize_t start,
         size_t N,
         ll Cost,
         std::vector<ll> const& Garbages,
         std::vector<ll> const& ShareNum) {
  ssize_t num = 1;

  for (ssize_t pos=start;
       num<ShareNum[pos] && pos+num < N;
       num++, pos++);

  std::cout << "  num=" << num << std::endl;

  ll cost = Cost * (num+1) + Garbages[start+num-1];

  for (ssize_t d=1; d<num; d++) {
    ssize_t pos=start + d;
    ll dist = Garbages[pos] - Garbages[pos-1];
    ssize_t n = num - d;
    std::cout << "  add "
              << Garbages[pos] << " to "
              << Garbages[pos-1] << " with "
              << n << std::endl;
    cost += (n+1) * (n+1) * dist;
  }

  cost += (num+1) * (num+1) * Garbages[start];

  return std::make_tuple(start+num, cost);
}

size_t share(ll dist, ll C) {
  size_t n = 3;
  while ((2 * n * n - 2 * n - 6) * dist < C) n++;
  return n-1;
}

int main() {
  size_t N;
  std::cin >> N;

  ll Cost;
  std::cin >> Cost;

  std::vector<ll> Garbages(N);
  std::vector<ll> ShareNum(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> Garbages[i];
    ShareNum[i] = share(Garbages[i], Cost);
  }

  ll ans = 0;
  ssize_t pos = 0;

  while (pos < N) {
    ll cost;
    std::tie(pos, cost) =
      simulate(pos, N, Cost, Garbages, ShareNum);
    ans += cost;

    std::cout << pos << ' ' << cost << ' ' << ans << std::endl;
  }

  std::cout << ans << std::endl;

  return 0;
}
