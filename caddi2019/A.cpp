#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <list>
#include <tuple>
#include <chrono>

constexpr int L = 1000;
constexpr size_t N = 1000;
constexpr size_t M = 100000;

using Coord_t = std::tuple<int, int, int>;
using Zones1_t = std::vector<std::list<size_t>>;
using Zones2_t = std::vector<Zones1_t>;
using Zones_t = std::vector<Zones2_t>;

std::ostream&
operator<<(std::ostream& os, Coord_t const& c) {
  return os << '('
            << std::get<0>(c) << ','
            << std::get<1>(c) << ','
            << std::get<2>(c) << ')';
}

Coord_t sparse_zone(Zones_t const& zones) {
  size_t min = N;
  size_t min_x = 5;
  size_t min_y = 5;
  size_t min_z = 5;

  for (size_t x=0; x<5; x++) {
    for (size_t y=0; y<5; y++) {
      for (size_t z=0; z<5; z++) {
        auto s = zones[x][y][z].size();
        if (s == 0) return std::make_tuple(x, y, z);
        if (s < min) {
          min = s;
          min_x = x;
          min_y = y;
          min_z = z;
        }
      }
    }
  }

  return std::make_tuple(min_x, min_y, min_z);
}

Coord_t sparse_zone2(Zones_t const& zones) {
  size_t min = N;
  size_t min_x = 5;
  size_t min_y = 5;
  size_t min_z = 5;

  for (size_t x=1; x<4; x++) {
    for (size_t y=1; y<4; y++) {
      for (size_t z=1; z<4; z++) {
        auto s = zones[x][y][z].size();
        if (s == 0) return std::make_tuple(x, y, z);
        if (s < min) {
          min = s;
          min_x = x;
          min_y = y;
          min_z = z;
        }
      }
    }
  }

  return std::make_tuple(min_x, min_y, min_z);
}

Coord_t random_coord(std::default_random_engine engine,
                     int lx, int ux,
                     int ly, int uy,
                     int lz, int uz) {
  using dist_t = std::uniform_int_distribution<int>;
  return std::make_tuple(dist_t(lx, ux)(engine),
                         dist_t(ly, uy)(engine),
                         dist_t(lz, uz)(engine));
}

bool collision(Coord_t const& ca, int ra,
               Coord_t const& cb, int rb) {
  auto dx = std::get<0>(ca) - std::get<0>(cb);
  auto dy = std::get<1>(ca) - std::get<1>(cb);
  auto dz = std::get<2>(ca) - std::get<2>(cb);

  return (ra+rb)*(ra+rb) > dx*dx + dy*dy + dz*dz;
}

bool can_put(Coord_t c, int r,
             std::vector<int> const& R,
             std::vector<Coord_t> const& centers,
             Zones_t const& z) {
  ssize_t ix = std::get<0>(c) / 200;
  ssize_t iy = std::get<1>(c) / 200;
  ssize_t iz = std::get<2>(c) / 200;

  for (auto i=ix-1; i<=ix+1; i++) {
    if (i<0 || i>=5) continue;
    for (auto j=iy-1; j<=iy+1; j++) {
      if (j<0 || j>=5) continue;
      for (auto k=iz-1; k<=iz+1; k++) {
        if (k<0 || k>=5) continue;
        auto const& lst = z[i][j][k];
        for (auto l: lst)
          if (collision(c, r, centers[l], R[l])) {
            // std::cerr << "collision: " << c << r << centers[l] << R[l] << std::endl;
            return false;
          }
      }
    }
  }

  return true;
}

int main() {
  auto start = std::chrono::system_clock::now();
  auto limit = start + std::chrono::milliseconds(2900);

  int trush;
  std::cin >> trush >> trush >> trush;

  std::vector<int> R(N);
  std::vector<size_t> P(N);

  std::vector<size_t> Porder(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> R[i] >> P[i];
    Porder[i]=i;
  }

  std::sort(Porder.begin(), Porder.end(),
            [&](auto a, auto b){return P[b] < P[a];});

  std::vector<size_t> A(M);
  std::vector<size_t> B(M);
  std::vector<int> C(M);
  std::vector<size_t> D(M);

  for (size_t i=0; i<M; i++) {
    std::cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    std::cin >> C[i];
    std::cin >> D[i];
  }

  std::default_random_engine engine(std::random_device{}());

  std::vector<Coord_t> centers(N, std::make_tuple(-1, -1, -1));
  Zones_t zones(5, Zones2_t(5, Zones1_t(5)));

  size_t loops = 0;

  while (std::chrono::system_clock::now() < limit) {
    for (auto i: Porder) {
      if (centers[i] != std::make_tuple(-1, -1, -1)) continue;
      // if (P[i]*100 < R[i]*R[i]) continue;

      ssize_t ix, iy, iz;
      int lx, ly, lz, ux, uy, uz;

      if (R[i] < 100) {
        auto z = sparse_zone(zones);
        ix = std::get<0>(z);
        iy = std::get<1>(z);
        iz = std::get<2>(z);
        lx = ix * 200 + R[i];
        ly = iy * 200 + R[i];
        lz = iz * 200 + R[i];
        ux = (ix+1) * 200 - R[i];
        uy = (iy+1) * 200 - R[i];
        uz = (iz+1) * 200 - R[i];
      } else {
        auto z = sparse_zone2(zones);
        ix = std::get<0>(z);
        iy = std::get<1>(z);
        iz = std::get<2>(z);
        lx = ix * 200;
        ly = iy * 200;
        lz = iz * 200;
        ux = (ix+1) * 200;
        uy = (iy+1) * 200;
        uz = (iz+1) * 200;
      }

      auto c = random_coord(engine, lx, ux, ly, uy, lz, uz);

      if (can_put(c, R[i], R, centers, zones)) {
        centers[i] = c;
        zones[ix][iy][iz].push_back(i);
      }
    }

    loops++;
  }

  for (auto c: centers) {
    std::cout << std::get<0>(c) << ' '
              << std::get<1>(c) << ' '
              << std::get<2>(c) << '\n';
  }

  std::cerr << loops << std::endl;

  return 0;
}
