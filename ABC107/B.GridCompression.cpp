#include <iostream>
#include <vector>

using Grid = std::vector<std::vector<bool>>;

int main() {
  size_t H, W;
  std::cin >> H >> W;

  Grid A(H, std::vector<bool>(W));

  for (size_t i=0; i<H; i++) {
    for (size_t j=0; j<W; j++) {
      char c;
      std::cin >> c;
      A[i][j] = c == '#';
    }
  }

  std::vector<bool> flags_row(H, false);
  std::vector<bool> flags_col(W, false);

  for (size_t i=0; i<H; i++) {
    for (size_t j=0; j<W; j++) {
      if (A[i][j]) {
        flags_row[i] = true;
        break;
      }
    }
  }

  for (size_t j=0; j<W; j++) {
    for (size_t i=0; i<H; i++) {
      if (A[i][j]) {
        flags_col[j] = true;
        break;
      }
    }
  }

  for (size_t i=0; i<H; i++) {
    if (! flags_row[i]) continue;
    for (size_t j=0; j<W; j++) {
      if (! flags_col[j]) continue;
      std::cout << (A[i][j] ? '#' : '.');
    }
    std::cout << std::endl;
  }

  return 0;
}
