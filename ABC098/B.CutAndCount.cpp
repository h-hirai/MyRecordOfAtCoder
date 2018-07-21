#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
  long N;
  std::string S;

  std::cin >> N;
  std::cin >> S;

  std::set<char> chars;

  for (auto const& c : S) chars.insert(c);

  size_t ans = 0;

  for (auto i = S.begin(); i != S.end(); i++) {
    size_t kinds=0;
    for (auto const& c: chars) {
      if (std::count(S.begin(), i, c) > 0 &&
          std::count(i, S.end(), c) > 0) {
        kinds++;
      }
    }
    if (kinds > ans) ans = kinds;
  }

  std::cout << ans << std::endl;

  return 0;
}
