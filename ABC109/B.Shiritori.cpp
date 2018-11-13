#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  bool ans = true;

  size_t N;
  std::cin >> N;

  std::vector<std::string> SS(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> SS[i];
  }

  for (auto it = SS.cbegin(); it != SS.cend(); it++) {
    if (it != SS.cbegin())
      if (std::prev(it)->back() != it->front()) {
        ans = false;
        break;
      }

    if (std::find(std::next(it), SS.cend(), *it) != SS.cend()) {
      ans = false;
      break;
    }
  }

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}
