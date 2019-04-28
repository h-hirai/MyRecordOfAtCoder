#include <iostream>
#include <vector>
#include <algorithm>

// #include <iomanip>

using ll = long long;

int main() {
  int N;

  std::cin >> N;

  std::vector<ll> A(N);

  for (int i=0; i<N; i++)
    std::cin >> A[i];

  std::vector<ll> dp_p(N+1);
  std::vector<ll> dp_n(N+1);

  dp_n[0] = -1e10;

  for (int i=0; i<N; i++) {
    dp_p[i+1] = std::max(dp_p[i]+A[i], dp_n[i]-A[i]);
    dp_n[i+1] = std::max(dp_p[i]-A[i], dp_n[i]+A[i]);
  }

  // for (int i=1; i<N+1; i++)
  //   std::cerr << std::setw(4) << dp_p[i];
  // std::cerr << std::endl;
  // for (int i=1; i<N+1; i++)
  //   std::cerr << std::setw(4) << dp_n[i];
  // std::cerr << std::endl;

  std::cout << dp_p[N] << std::endl;

  return 0;
}
