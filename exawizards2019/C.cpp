#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>

int main() {
  size_t N, Q;

  std::cin >> N >> Q;

  std::unordered_map<char, std::vector<size_t>> Cells;

  for (size_t i=0; i<N; i++) {
    char c;
    std::cin >> c;
    Cells[c].push_back(i);
  }

  size_t ans = N;
  std::vector<size_t> Golems(N, 1);

  for (size_t i=0; i<Q; i++) {
    char t, d;
    std::cin >> t >> d;

    auto const& cells = Cells[t];

    if (d == 'L') {
      for (auto j: cells) {
        if (j == 0) {
          ans -= Golems[j];
        } else {
          Golems[j-1] += Golems[j];
        }
        Golems[j] = 0;
      }
    } else {
      for (auto it = cells.crbegin();
           it != cells.crend();
           it++) {
        auto j = *it;

        if (j == N-1) {
          ans -= Golems[j];
        } else {
          Golems[j+1] += Golems[j];
        }
        Golems[j] = 0;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
