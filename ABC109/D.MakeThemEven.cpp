#include <iostream>
#include <vector>
#include <tuple>

using map_t = std::vector<std::vector<size_t>>;
using ans_t = std::vector<std::tuple<size_t, size_t, size_t, size_t>>;

void move(size_t y1, size_t x1, size_t y2, size_t x2,
          map_t& A, ans_t& ans) {
  A[y1-1][x1-1]--;
  A[y2-1][x2-1]++;
  ans.push_back(std::make_tuple(y1, x1, y2, x2));
}

int main() {
  size_t H, W;
  std::cin >> H >> W;

  map_t A(H, std::vector<size_t>(W));

  for (size_t y=0; y<H; y++) {
    for (size_t x=0; x<W; x++) {
      std::cin >> A[y][x];
    }
  }

  ans_t ans;

  for (size_t y=1; y<H+1; y++) {
    if (y%2==1) {
      for (size_t x=1; x<W+1; x++) {
        if (A[y-1][x-1] % 2 == 1) {
          if (x<W)
            move(y, x, y, x+1, A, ans);
          else if (y<H)
            move(y, x, y+1, x, A, ans);
        }
      }
    } else {
      for (size_t x=W; x>0; x--) {
        if (A[y-1][x-1] % 2 == 1) {
          if (x>0)
            move(y, x, y, x-1, A, ans);
          else if (y<H)
            move(y, x, y+1, x, A, ans);
        }
      }
    }
  }

  std::cout << ans.size() << std::endl;
  for (auto const& a : ans) {
    std::cout << std::get<0>(a) << ' ' << std::get<1>(a) << ' '
              << std::get<2>(a) << ' ' << std::get<3>(a) << std::endl;
  }

  return 0;
}
