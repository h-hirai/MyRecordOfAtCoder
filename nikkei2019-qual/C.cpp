#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
  size_t N;

  std::cin >> N;

  std::vector<std::pair<ll, ll>> D(N);

  for (size_t i=0; i<N; i++) {
    ll A, B;
    std::cin >> A >> B;
    D[i] = std::make_pair(A, B);
  }

  std::sort(D.begin(), D.end(),
            [](auto a, auto b) {
              return b.first + b.second < a.first + a.second;
            });

  ll res_a = 0;
  ll res_b = 0;

  for (size_t i=0; i<N; i++) {
    if (i%2 == 0)
      res_a += D[i].first;
    else
      res_b += D[i].second;
  }

  std::cout << (res_a - res_b) << std::endl;

  return 0;
}
