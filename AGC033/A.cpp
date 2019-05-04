#include <iostream>
#include <vector>

// #include <iomanip>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::vector<bool>> A(H, std::vector<bool>(W));
  std::vector<std::vector<int>> dist(H, std::vector<int>(W, 3000));

  for (int y=0; y<H; y++) {
    for (int x=0; x<W; x++) {
      char a;
      std::cin >> a;
      A[y][x] = (a == '#');
      if (A[y][x]) dist[y][x] = 0;
    }
  }


  // for (int y=0; y<H; y++) {
  //   for (int x=0; x<W; x++) {
  //     std::cerr << std::setw(5) << dist[y][x];
  //   }
  //   std::cerr << std::endl;
  // }
  // std::cerr << std::endl;

  for (int y=0; y<H; y++) {
    for (int x=1; x<W; x++) {
      if (! A[y][x])
        dist[y][x] = dist[y][x-1] + 1;
    }
  }

  // for (int y=0; y<H; y++) {
  //   for (int x=0; x<W; x++) {
  //     std::cerr << std::setw(5) << dist[y][x];
  //   }
  //   std::cerr << std::endl;
  // }
  // std::cerr << std::endl;

  for (int y=0; y<H; y++) {
    for (int x=W-2; x>=0; x--) {
      if (! A[y][x])
        dist[y][x] = std::min(dist[y][x], dist[y][x+1] + 1);
    }
  }

  // for (int y=0; y<H; y++) {
  //   for (int x=0; x<W; x++) {
  //     std::cerr << std::setw(5) << dist[y][x];
  //   }
  //   std::cerr << std::endl;
  // }
  // std::cerr << std::endl;

  for (int y=1; y<H; y++) {
    for (int x=0; x<W; x++) {
      if (! A[y][x])
        dist[y][x] = std::min(dist[y][x], dist[y-1][x] + 1);
    }
  }

  // for (int y=0; y<H; y++) {
  //   for (int x=0; x<W; x++) {
  //     std::cerr << std::setw(5) << dist[y][x];
  //   }
  //   std::cerr << std::endl;
  // }
  // std::cerr << std::endl;

  for (int y=H-2; y>=0; y--) {
    for (int x=0; x<W; x++) {
      if (! A[y][x])
        dist[y][x] = std::min(dist[y][x], dist[y+1][x] + 1);
    }
  }

  // for (int y=0; y<H; y++) {
  //   for (int x=0; x<W; x++) {
  //     std::cerr << std::setw(5) << dist[y][x];
  //   }
  //   std::cerr << std::endl;
  // }
  // std::cerr << std::endl;

  int ans = 0;

  for (int y=0; y<H; y++) {
    for (int x=0; x<W; x++) {
      ans = std::max(ans, dist[y][x]);
    }
  }

  std::cout << ans;

  return 0;
}
