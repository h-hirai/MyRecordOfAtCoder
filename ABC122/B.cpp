#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  std::string T;
  std::string ans;

  for (auto c: S) {
    if (c == 'A' ||
        c == 'T' ||
        c == 'C' ||
        c == 'G') {
      T.push_back(c);
    } else {
      if (T.size() > ans.size()) {
        std::swap(T, ans);
        T.clear();
      }
    }
  }

  if (T.size() > ans.size())
    std::swap(T, ans);

  std::cout << ans.size() << std::endl;

  return 0;
}
