#include <iostream>
#include <vector>
#include <algorithm>

// #include <iomanip>

using ll = long long;

int main() {
  int N;

  std::cin >> N;

  std::vector<ll> A(N+1);

  for (int i=1; i<N+1; i++)
    std::cin >> A[i];

  std::vector<ll> Acc_pp(N+1);
  std::vector<ll> Acc_nn(N+1);
  std::vector<ll> Acc_pn(N+1);
  std::vector<ll> Acc_np(N+1);

  for (int i=2; i<N+1; i++) {
    auto acc = std::max({Acc_pp[i-2], Acc_pn[i-2],
                         Acc_np[i-2], Acc_nn[i-2]});
    Acc_pp[i-1] = acc + A[i-1];
    Acc_nn[i-1] = acc - A[i-1];

    Acc_pp[i] = Acc_pp[i-1] + A[i];
    Acc_nn[i] = Acc_nn[i-1] - A[i];

    Acc_pn[i] = Acc_pp[i-1] - A[i];
    Acc_np[i] = Acc_nn[i-1] + A[i];

    // for (int j=2; j<i; j++) std::cerr << "    ";
    // std::cerr << std::setw(4) << Acc_pp[i-1]
    //           << std::setw(4)  << Acc_pp[i] << std::endl;
    // for (int j=2; j<i; j++) std::cerr << "    ";
    // std::cerr << std::setw(4) << Acc_nn[i-1]
    //           << std::setw(4)  << Acc_nn[i] << std::endl;
    // for (int j=2; j<i; j++) std::cerr << "    ";
    // std::cerr << std::setw(4) << Acc_pn[i-1]
    //           << std::setw(4)  << Acc_pn[i] << std::endl;
    // for (int j=2; j<i; j++) std::cerr << "    ";
    // std::cerr << std::setw(4) << Acc_np[i-1]
    //           << std::setw(4)  << Acc_np[i] << std::endl;
  }

  auto ans = std::max(Acc_pp[N], Acc_nn[N]);

  std::cout << ans << std::endl;

  return 0;
}
