#include <iostream>
#include <vector>

std::vector<std::pair<int, int>>
testcase(int R, int C) {
  std::vector<std::pair<int, int>> ret;

  if (R < 3 && C < 5) return ret;
  if (R < 4 && C < 4) return ret;

  for (int c=0; c<C; c++) {
    for (int r=0; r<R; r++) {
      if (r % 2 == 0) {
        ret.emplace_back(r, c);
      } else {
        ret.emplace_back(r, (c + 2) % C);
      }
    }
  }

  return ret;
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++){
    int R, C;
    std::cin >> R >> C;
    auto const ans = R < C ? testcase(R, C) : testcase(C, R);

    std::cout << "Case #" << t << ": ";
    if (ans.empty()) {
      std::cout << "IMPOSSIBLE\n";
    } else {
      std::cout << "POSSIBLE\n";
      for (auto const& p: ans) {
        if (R < C)
          std::cout << (p.first + 1) << ' '
                    << (p.second + 1) << '\n';
        else
          std::cout << (p.second + 1) << ' '
                    << (p.first + 1) << '\n';
      }
    }
  }

  return 0;
}
