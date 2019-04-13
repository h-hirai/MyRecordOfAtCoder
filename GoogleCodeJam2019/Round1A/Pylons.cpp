#include <iostream>
#include <vector>

std::vector<std::pair<int, int>>
testcase(int R, int C) {
  std::vector<std::pair<int, int>> ret;

  if (R < 3 && C < 5) return ret;
  if (R < 4 && C < 4) return ret;

  const int K = R < 3 ? 3 : 2;

  for (int c=0; c<C; c++) {
    for (int r=0; r<R; r++) {
      int rr = (C == R && c == C-1 && C % 2 == 0) ? (r + 1) % R : r;
      if (rr % 2 == 0) {
        ret.emplace_back(rr, c);
      } else {
        ret.emplace_back(rr, (c + K) % C);
      }
    }
  }

  return ret;
}

#include <iomanip>

// int main() {
//   for (int R=2; R<21; R++) {
//     for (int C=R; C<21; C++) {
//       auto ans = testcase(R, C);
//       if (ans.empty()) continue;
//       for (int i=1; i<R*C; i++) {
//         auto ay = ans[i-1].first;
//         auto ax = ans[i-1].second;
//         auto by = ans[i].first;
//         auto bx = ans[i].second;
//         if (ay == by || ax == bx ||
//             ay - ax == by - bx || ay + ax == by + bx) {
//           std::cerr << "case " << R << ", " << C << " was failed." << std::endl;

//           for (auto const& p: ans) {
//             std::cerr << p.first << ',' << p.second << std::endl;
//           }

//           // std::vector<std::vector<int>> grid(R, std::vector<int>(C));
//           // for (int i=0; i<R*C; i++)
//           //   grid[ans[i].first][ans[i].second] = i;
//           // for (int r=0; r<R; r++) {
//           //   for (int c=0; c<C; c++) {
//           //     std::cerr << std::setw(4) << grid[r][c];
//           //   }
//           //   std::cerr << std::endl;
//           // }

//           // break;
//         }
//       }
//     }
//   }

//   return 0;
// }

#include <iomanip>

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
