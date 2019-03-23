#include <iostream>
#include <algorithm>
#include <bitset>

using ll = long long;

ll count_bit(ll n, ll digit) {
  ll base = 2LL << digit;
  ll a = n / base * base / 2;
  ll b = (n % base) - (base / 2 - 1);
  return a + std::max(0LL, b);
}

ll solv(ll A, ll B) {
  A = std::max(0LL, A-1);

  auto ans = std::bitset<50>(0);

  for (size_t d=0; 1LL<<d <= B; d++) {
    auto cnt = count_bit(B, d) - count_bit(A, d);
    ans.set(d, cnt % 2 == 1);
  }

  return ans.to_ullong();
}

int main() {
  ll A, B;

  std::cin >> A >> B;

  std::cout << solv(A, B) << std::endl;

  return 0;
}
