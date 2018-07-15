#include <iostream>
#include <cmath>

long long gcd(long long m, long long n) {
  if (n==0) return std::abs(m);
  else return gcd(n, m % n);
}

bool solv(long long init,
          long long buy,
          long long check,
          long long reload) {
  if (init < buy) return false;
  if (reload < buy) return false;

  auto a = init % buy;
  if (check < a) return false;
  if (reload % buy == 0) return true;

  auto g = gcd(buy, reload);
  auto m = (check + 1 - a) / g;
  m += ((check + 1 - a) % g) == 0 ? 0 : 1;

  if (a + m * g < buy) return false;

  return true;
}

int main() {
  size_t N;

  std::cin >> N;

  for (size_t i=0; i<N; i++) {
    long long init;
    long long buy;
    long long check;
    long long reload;

    std::cin >> init;
    std::cin >> buy;
    std::cin >> check;
    std::cin >> reload;

    std::cout << (solv(init, buy, check, reload) ? "Yes" : "No")
              << std::endl;
  }

  return 0;
}
