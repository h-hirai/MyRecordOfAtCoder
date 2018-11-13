#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long N;

  std::cin >> N;
  std::vector<long> X(N);
  std::vector<long> X_sorted(N);

  for (long i=0; i<N; i++) {
    std::cin >> X[i];
    X_sorted[i] = X[i];
  }

  std::sort(X_sorted.begin(), X_sorted.end());

  long const med_small = X_sorted[N/2-1];
  long const med_big = X_sorted[N/2];

  for (auto const& x : X) {
    if (x <= med_small)
      std::cout << med_big << std::endl;
    else
      std::cout << med_small << std::endl;
  }

  return 0;
}
