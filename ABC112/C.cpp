#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
  int x;
  int y;
  int h;

  Point (int x, int y, int h) : x(x), y(y), h(h) {}
};

size_t distance(Point const& p1, Point const& p2) {
  return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

bool judge(Point const& c, std::vector<Point> const& ps) {
  return std::all_of
    (ps.cbegin(), ps.cend(),
     [&](Point const& p) {
      if (p.h == 0) {
        return c.h <= distance(c, p);
      } else {
        return c.h == p.h + distance(c, p);
      }
    });
}

Point scan(std::vector<Point> const& ps) {
  Point const p =
    *std::find_if(ps.begin(), ps.end(),
                  [](Point p){return p.h > 0;});

  for (size_t y=0; y<101; y++) {
    for (size_t x=0; x<101; x++) {
      Point c(x, y, 0);
      c.h = p.h + distance(c, p);
      if (judge(c, ps)) return c;
    }
  }
}

int main() {
  size_t N;

  std::cin >> N;

  std::vector<Point> ps;
  ps.reserve(N);

  for (size_t i=0; i<N; i++) {
    int x;
    int y;
    int h;

    std::cin >> x >> y >> h;

    ps.push_back(Point(x, y, h));
  }

  Point ans = scan(ps);

  std::cout << ans.x << ' '
            << ans.y << ' '
            << ans.h << std::endl;

  return 0;
}
