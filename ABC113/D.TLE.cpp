#include <iostream>
#include <vector>

using ull = unsigned long long;
static ull const Mod = 1000000007;

ull Amida1(int W, int J, int K,
           std::vector<ull> const& Fib) {
  if (J < 1 || K < 1 || J > W || K > W || std::abs(J-K) > 1) {
    return 0;
  }

  auto s = std::min(J, K);
  auto l = std::max(J, K);

  return (Fib[s-1] * Fib[W-l]) % Mod;
}

ull Amida(int H, int W, int J, int K,
          std::vector<ull> const& Fib) {
  if (J < 1 || K < 1 || J > W || K > W || std::abs(J-K) > H) {
    return 0;
  }

  if (H == 1) {
    auto ans = Amida1(W, J, K, Fib);
    return ans;
  }

  ull ans;
  ans  = Amida(H-1, W, J, K-1, Fib) * Amida1(W, K-1, K, Fib);
  ans %= Mod;
  ans += Amida(H-1, W, J, K  , Fib) * Amida1(W, K  , K, Fib);
  ans %= Mod;
  ans += Amida(H-1, W, J, K+1, Fib) * Amida1(W, K+1, K, Fib);
  ans %= Mod;

  return ans;
}

int main() {
  int H, W, K;

  std::cin >> H >> W >> K;

  std::vector<ull> Fib(W+1);
  Fib[0] = 1;
  Fib[1] = 1;

  for (size_t i=2; i<W+1; i++)
    Fib[i] = Fib[i-2] + Fib[i-1];

  std::cout << Amida(H, W, 1, K, Fib) << std::endl;

  return 0;
}
