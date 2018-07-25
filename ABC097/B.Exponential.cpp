#include <iostream>
#include <complex>

int main() {
  long X;

  std::cin >> X;

  double r = std::sqrt(X);
  long f = std::floor(r);

  long ans = 1;

  for (long i=2; i<=X; i++) {
    for (long j=i*i; j<=X; j*=i) {
      ans = ans < j ? j : ans;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
