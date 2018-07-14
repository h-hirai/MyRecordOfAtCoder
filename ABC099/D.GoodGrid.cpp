// 良いグリッドは
// 0 1 2 0
// 1 2 0 1
// 2 0 1 2
// 0 1 2 0
// のような斜め縞模様になるから、まず
// 1) 3グループに分ける
// 2) グループごとに色の内訳を作る
// 3) グループごと塗り替え色ごとに違和感の合計を求め、最小値を求める
// 4) 塗り替え色がかぶる場合はどうする?

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main() {
  size_t N, numc;

  std::cin >> N;
  std::cin >> numc;

  std::vector<std::vector<unsigned int>>
    D(numc, std::vector<unsigned int>(numc));

  for (size_t y=0; y<numc; y++) {
    for (size_t x=0; x<numc; x++) {
      std::cin >> D[x][y];
    }
  }

  std::vector<std::vector<unsigned int>>
    cmap(3, std::vector<unsigned int>(numc, 0));

  for (size_t y=0; y<N; y++) {
    for (size_t x=0; x<N; x++) {
      unsigned int c;
      std::cin >> c;
      c--;
      size_t g = (x + y) % 3;
      cmap[g][c]++;
    }
  }

  unsigned int ans =
    std::numeric_limits<decltype(ans)>::max();

  for (size_t x=0; x<numc; x++) {
    for (size_t y=0; y<numc; y++) {
      if (x==y) continue;
      for (size_t z=0; z<numc; z++) {
        if (x==z) continue;
        if (y==z) continue;

        unsigned int cost = 0;

        std::cout << "DEBUG("
                  << x << "," << y << "," << z << ")"
                  << std::endl;
        for (size_t c=0; c<numc; c++) {
          std::cout << "DEBUG  " << c << ": "
                    << cmap[0][c] << '*' << D[x][c];
          std::cout << "+"
                    << cmap[1][c] << '*' << D[y][c];
          std::cout << "+"
                    << cmap[2][c] << '*' << D[z][c];
          std::cout << "="
                    << (cmap[0][c] * D[x][c] +
                        cmap[1][c] * D[y][c] +
                        cmap[2][c] * D[z][c]);

          cost += cmap[0][c] * D[x][c];
          cost += cmap[1][c] * D[y][c];
          cost += cmap[2][c] * D[z][c];

          std::cout << "  ->"
                    << cost
                    << std::endl;
        }

        ans = std::min(ans, cost);
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
