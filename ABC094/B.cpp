#include <iostream>
#include <vector>

int main() {
  long N, M, X;

  std::cin >> N;
  std::cin >> M;
  std::cin >> X;

  long cost_l = 0;
  long cost_r = 0;

  for (long i=0; i<M; i++) {
    long A;
    std::cin >> A;

    if (A < X)
      cost_l++;
    else
      cost_r++;
  }

  std::cout << (cost_l<cost_r ? cost_l : cost_r) << std::endl;

  return 0;
}
