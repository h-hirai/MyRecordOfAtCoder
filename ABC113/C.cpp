#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct City {
  size_t PrefId;
  size_t Year;

  City(size_t P, size_t Y) : PrefId(P), Year(Y) {}
};

int main() {
  size_t N, M;

  std::cin >> N >> M;

  std::vector<City> Input;
  Input.reserve(M);
  std::vector<std::vector<size_t>>
    Sort(N+1, std::vector<size_t>());

  for (size_t i=0; i<M; i++) {
    size_t P;
    size_t Y;
    std::cin >> P >> Y;
    Input.push_back(City(P, Y));
    Sort[P].push_back(Y);
  }

  std::vector<std::unordered_map<size_t, size_t>> dicts(N+1);
  for (size_t p=1; p<N+1; p++) {
    std::sort(Sort[p].begin(), Sort[p].end());
    size_t num = 1;
    for (auto y : Sort[p]) {
      dicts[p].insert(std::make_pair(y, num));
      num++;
    }
  }

  for (auto c : Input) {
    auto p = c.PrefId;
    auto y = c.Year;
    std::cout << std::setw(6) << std::setfill('0') << p
              << std::setw(6) << std::setfill('0') << dicts[p][y]
              << std::endl;
  }

  return 0;
}
