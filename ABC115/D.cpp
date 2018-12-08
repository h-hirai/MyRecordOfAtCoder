#include <iostream>
#include <vector>

using ll = long long;

ll solv(size_t N, ll X,
        std::vector<ll> const& Height,
        std::vector<ll> const& Patties) {
  if (X == 0) return 0;

  if (X == Height[N]) return Patties[N];

  if (X-1 <= Height[N-1]) return solv(N-1, X-1, Height, Patties);

  return Patties[N-1] + 1 + solv(N-1, X-Height[N-1]-2, Height, Patties);
}

int main() {
  size_t N;
  ll X;

  std::cin >> N >> X;

  std::vector<ll> Height(N+1);
  std::vector<ll> Patties(N+1);

  Height[0] = 1;
  Patties[0] = 1;

  for (size_t l=1; l<N+1; l++) {
    Height[l] = Height[l-1] * 2 + 3;
    Patties[l] = Patties[l-1] * 2 + 1;
  }

  std::cout << solv(N, X, Height, Patties) << std::endl;

  return 0;
}
