#include <iostream>
#include <map>

std::map<unsigned int, size_t> memo;

size_t solv(unsigned int n) {
  if (n < 6) {
    return n;
  }

  if (memo.count(n) == 1) {
    return memo.at(n);
  }

  size_t ans = solv(n-6);
  for (unsigned m=6*6; m<=n; m*=6) {
    size_t r = solv(n-m);
    if (r < ans) ans = r;
  }

  for (unsigned m=9; m<=n; m*=9) {
    size_t r = solv(n-m);
    if (r < ans) ans = r;
  }

  memo.insert(std::make_pair(n, ans+1));

  return ans+1;
}


int main() {
  unsigned int n;

  std::cin >> n;

  std::cout << solv(n) << std::endl;

  return 0;
}
