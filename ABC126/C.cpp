#include <iostream>
#include <iomanip>

int main() {
  int N, K;

  std::cin >> N >> K;

  double ans = 0;

  for (int i=1; i<=N; i++) {
    double a = 1.0/N;
    for (int j=i; j<K; j<<=1) {
      a *= 0.5;
    }
    ans += a;
  }

  std::cout << std::setprecision(10) << ans << std::endl;

  return 0;
}
