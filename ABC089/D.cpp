#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

int
find_pos(std::vector<int> const & table,
         int number) {
  return table[number];
}

int
move_piece(int l, int r, int w) {
  int lx = l % w;
  int ly = l / w;
  int rx = r % w;
  int ry = r / w;

  return std::abs(lx - rx) + std::abs(ly - ry);
}

int main() {
  int h;
  int w;
  int d;
  std::cin >> h;
  std::cin >> w;
  std::cin >> d;

  std::vector<int> table(h*w);

  for (int y=0; y<h; y++) {
    for (int x=0; x<w; x++) {
      int a;
      std::cin >> a;
      table[a] = y*w+x;
    }
  }

  int q;
  std::cin >> q;

  std::map<int, int> memo;

  for (int i=0; i<q; i++) {
    int l;
    int r;
    std::cin >> l;
    std::cin >> r;

    int result=0;

    auto l_pos = find_pos(table, l);

    while (l != r) {
      int step;
      step = find_pos(table, l+d);

      result += move_piece(l_pos, step, w);
      l_pos = step;
      l += d;
    }

    std::cout << result << std::endl;
  }

  return 0;
}
