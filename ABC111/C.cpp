#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  std::cin >> N;

  std::vector<size_t> DictEven(100000, 0);
  std::vector<size_t> DictOdd(100000, 0);

  for (size_t i=0; i<N; i+=2) {
    size_t v;
    std::cin >> v;
    DictEven[v-1]++;

    std::cin >> v;
    DictOdd[v-1]++;
  }

  auto i_max_even =
    std::max_element(DictEven.begin(), DictEven.end());
  auto i_max_odd =
    std::max_element(DictOdd.begin(), DictOdd.end());

  auto max_even = *i_max_even;
  auto max_odd = *i_max_odd;

  if (std::distance(DictEven.begin(), i_max_even) ==
      std::distance(DictOdd.begin(), i_max_odd)) {
    *i_max_even = 0;
    *i_max_odd = 0;

    i_max_even =
      std::max_element(DictEven.begin(), DictEven.end());
    i_max_odd =
      std::max_element(DictOdd.begin(), DictOdd.end());

    if (*i_max_even > *i_max_odd) {
      max_even = *i_max_even;
    } else {
      max_odd = *i_max_odd;
    }
  }

  auto ans = N - max_even - max_odd;

  std::cout << ans << std::endl;

  return 0;
}
