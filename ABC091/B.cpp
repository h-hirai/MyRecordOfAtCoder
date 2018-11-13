#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> dict;

  long n;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    std::string s;
    std::cin >> s;
    if (dict.find(s) == dict.end()) {
      dict.insert(std::make_pair(s, 1));
    } else {
      dict[s] += 1;
    }
  }

  std::cin >> n;
  for (int i=0; i<n; i++) {
    std::string s;
    std::cin >> s;
    if (dict.find(s) == dict.end()) {
      dict.insert(std::make_pair(s, -1));
    } else {
      dict[s] -= 1;
    }
  }

  int ans=0;

  for (auto const& p : dict) {
    if (p.second > ans)
      ans = p.second;
  }

  std::cout << ans << std::endl;

  return 0;
}
