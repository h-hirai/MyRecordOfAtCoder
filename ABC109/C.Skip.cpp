#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

size_t gcd(size_t m, size_t n) {
  if (n == 0) return m;
  else return gcd(n, m % n);
}

int main() {
  size_t N, X;
  std::cin >> N >> X;

  std::vector<size_t> Xs(N+1);

  for (size_t i=0; i<N; i++) {
    std::cin >> Xs[i];
  }
  Xs[N] = X;

  std::sort(Xs.begin(), Xs.end());

  for (size_t i=1; i<N+1; i++) {
    Xs[i] -= Xs[0];
  }

  if (N>1)
    std::cout <<
      std::accumulate(Xs.begin()+3, Xs.end(),
                      gcd(Xs[1], Xs[2]),
                      [](size_t init, size_t i) {
                        // std::cout << init << ','
                        //           << i << std::endl;
                        if (init < i)
                          return gcd(init, i);
                        else
                          return gcd(i, init);
                      })
              << std::endl;
  else
    std::cout << Xs[1] << std::endl;

  return 0;
}
