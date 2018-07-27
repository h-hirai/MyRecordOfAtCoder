#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long H, W;

  std::cin >> H;
  std::cin >> W;

  std::vector<std::vector<bool>>
    C(H+2, std::vector<bool>(W+2));

  for (size_t x=0; x<W+2; x++) {
    C[0][x] = false;
  }
  for (size_t y=1; y<H+1; y++) {
    C[y][0] = false;
    for (size_t x=1; x<W+1; x++) {
      char c;
      std::cin >> c;
      if (c == '#')
        C[y][x] = true;
      else
        C[y][x] = false;
    }
    C[y][W+1] = false;
  }
  for (size_t x=0; x<W+2; x++) {
    C[H+1][x] = false;
  }

  bool ans = true;

  for (size_t y=1; y<H+1; y++) {
    for (size_t x=1; x<W+1; x++) {
      if (! C[y][x]) continue;
      if (! (C[y-1][x] | C[y+1][x] |
             C[y][x-1] | C[y][x+1])) {
        ans = false;
        break;
      }
    }
    if (! ans) break;
  }

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}
