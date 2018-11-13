#include <iostream>
#include <iomanip>

size_t solv(size_t N, size_t K) {
  if (K>N*2) return 0;
  if (K==1) return N*N*N;
  if (K==2) {
    size_t half = N/2;
    if (N%2==0)
      return half*half*half*2;
    else
      return half*half*half+(half+1)*(half+1)*(half+1);
  }

  if (K%2==1) return solv(N/K, 1);

  return solv(N/(K/2), 2);
}

int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::cout << solv(N, K) << std::endl;

  return 0;
}
