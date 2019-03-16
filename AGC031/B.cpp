#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  size_t N;

  std::cin >> N;

  std::unordered_map<size_t, size_t> color_pos;
  size_t prev = 0;

  std::vector<size_t> ans;
  ans.reserve(N+1);
  ans.push_back(1);

  for (size_t i=1; i<N+1; i++) {
    size_t C;
    std::cin >> C;

    if (C == prev) {
      ans.push_back(ans[i-1]);
    } else if (color_pos.count(C) == 0) {
      ans.push_back(ans[i-1]);
    } else {
      auto a = ans[i-1] + ans[color_pos.at(C)];
      a %= 1000000007;
      ans.push_back(a);
    }

    prev = C;
    color_pos[C] = i;
  }

  std::cout << ans[N] << std::endl;

  return 0;
}
