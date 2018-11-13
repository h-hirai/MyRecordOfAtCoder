#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using ull = unsigned long long;
static ull const Mod = 1000000007;

std::vector<ull> Fib;
std::map<std::tuple<int, int, int>, int> Memo;

ull Amida1(int W, int J, int K) {
  if (J < 1 || K < 1 || J > W || K > W || std::abs(J-K) > 1) {
    return 0;
  }

  auto s = std::min(J, K);
  auto l = std::max(J, K);

  return (Fib[s-1] * Fib[W-l]) % Mod;
}

ull Amida(int H, int W, int K) {
  if (K < 1 || K > W || std::abs(K-1) > H) {
    return 0;
  }

  auto key = std::make_tuple(H, W, K);
  if (Memo.count(key) > 0) return Memo.at(key);

  if (H == 1) {
    auto ans = Amida1(W, 1, K);
    Memo.insert(std::make_pair(key, ans));
    return ans;
  }

  ull ans;
  ans  = Amida(H-1, W, K-1) * Amida1(W, K-1, K);
  ans %= Mod;
  ans += Amida(H-1, W, K  ) * Amida1(W, K  , K);
  ans %= Mod;
  ans += Amida(H-1, W, K+1) * Amida1(W, K+1, K);
  ans %= Mod;

  Memo.insert(std::make_pair(key, ans));
  return ans;
}

int main() {
  int H, W, K;

  std::cin >> H >> W >> K;

  Fib.resize(W+1);
  Fib[0] = 1;
  Fib[1] = 1;

  for (size_t i=2; i<W+1; i++)
    Fib[i] = Fib[i-2] + Fib[i-1];

  std::cout << Amida(H, W, K) << std::endl;

  return 0;
}
