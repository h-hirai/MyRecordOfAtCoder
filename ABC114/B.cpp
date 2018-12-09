#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
  std::string S;

  std::cin >> S;

  std::string que;

  int ans = 999;

  for (auto c : S) {
    que.push_back(c);
    if (que.size() > 3) {
      que.erase(0, 1);
    }
    ans = std::min(ans, std::abs(753 - std::stoi(que)));
  }

  std::cout << ans << std::endl;

  return 0;
}
