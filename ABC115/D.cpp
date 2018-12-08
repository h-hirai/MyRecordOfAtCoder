#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> Burger(size_t L) {
  if (L==0) return {true};

  auto const b = Burger(L-1);
  std::vector<bool> ret = {false};
  std::copy(b.begin(), b.end(), std::back_inserter(ret));
  ret.push_back(true);
  std::copy(b.begin(), b.end(), std::back_inserter(ret));
  ret.push_back(false);
  return ret;
}

int main() {
  size_t N/*, X*/;
  std::cin >> N/* >> X*/;

  for (auto b : Burger(N)) {
    std::cout << (b ? 'P' : 'B');
  }
  std::cout << std::endl;

  return 0;
}
