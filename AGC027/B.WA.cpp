#include <iostream>
#include <vector>
#include <tuple>

using ll = long long;

std::tuple<ssize_t, ll>
simulate(ssize_t N,
         ll Cost,
         std::vector<ll> const& Garbages,
         std::vector<ll> const& ShareNum) {
  ll cost = Garbages[N] + Cost;
  ssize_t pos = N;
  ssize_t num = 1;

  std::cout << "sim start: pos=" << pos << std::endl;

  while (num+1 <= ShareNum[pos-1] && pos > 0) {
    ll dist = Garbages[pos] - Garbages[pos-1];
    cost += (num+1) * (num+1) * dist;
    cost += Cost;

    std::cout << "  add cost " << Garbages[pos]
              << " to " << Garbages[pos-1]
              << " num=" << num
              << std::endl;
    std::cout << "  cost=" << cost
              << std::endl;

    num++;
    pos--;
  }

  cost += (num+1) * (num+1) * Garbages[pos];
  cost += Cost;

  std::cout << "  add cost " << Garbages[pos]
            << " to " << 0
            << " num=" << num
            << std::endl;

  return std::make_tuple(pos-1, cost);
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
  ssize_t pos = N-1;

  while (pos >= 0) {
    ll cost;
    std::tie(pos, cost) = simulate(pos, Cost, Garbages, ShareNum);
    ans += cost;

    std::cout << pos << ' ' << cost << ' ' << ans << std::endl;
  }

  std::cout << ans << std::endl;

  return 0;
}
