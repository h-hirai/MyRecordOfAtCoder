#include <iostream>
#include <vector>

size_t
dist(std::pair<ssize_t, ssize_t> a, std::pair<ssize_t, ssize_t> b) {
  return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

int main() {
  size_t H, W, D;
  std::cin >> H >> W >> D;

  std::vector<std::pair<size_t, size_t>> coords(H*W);

  for (size_t y=0; y<H; y++) {
    for (size_t x=0; x<W; x++) {
      int a;
      std::cin >> a;
      coords[a-1] = std::make_pair(y-1, x-1);
    }
  }

  std::vector<size_t> accs(H*W);

  for (size_t i=0; i<H*W; i++) {
    if (i<D) {
      accs[i] = 0;
    } else {
      accs[i] = accs[i-D] + dist(coords[i-D], coords[i]);
    }
  }

  size_t Q;
  std::cin >> Q;

  for (int i=0; i<Q; i++) {
    int L;
    int R;
    std::cin >> L;
    std::cin >> R;
    L--; R--;

    std::cout << (accs[R] - accs[L]) << std::endl;
  }

  return 0;
}
