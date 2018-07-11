#include <iostream>
#include <iomanip>

int main() {
  unsigned long n, m, d;

  std::cin >> n;
  std::cin >> m;
  std::cin >> d;

  double const ans =
    static_cast<double>((m-1) * (n-d) * (d==0?1:2)) /
    static_cast<double>(n * n);

  std::cout << std::setprecision(9) << ans << std::endl;

  return 0;
}
