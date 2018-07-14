#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

bool cmp(std::tuple<long, long, long>l,
         std::tuple<long, long, long>r) {
  long sum_l =
    std::get<0>(l) + std::get<1>(l) + std::get<2>(l);
  long sum_r =
    std::get<0>(r) + std::get<1>(r) + std::get<2>(r);

  return sum_l < sum_r;
}

long
sum(std::vector<std::tuple<long, long, long>> const& v,
    size_t m) {
  long x=0;
  long y=0;
  long z=0;
  for (size_t i=0; i<m; i++) {
    x+=std::get<0>(v[i]);
    y+=std::get<1>(v[i]);
    z+=std::get<2>(v[i]);
  }

  return std::abs(x) + std::abs(y) + std::abs(z);
}

int main() {
  size_t N, M;

  std::cin >> N;
  std::cin >> M;

  std::vector<std::tuple<long, long, long>> ppp(N);
  std::vector<std::tuple<long, long, long>> ppm(N);
  std::vector<std::tuple<long, long, long>> pmp(N);
  std::vector<std::tuple<long, long, long>> pmm(N);
  std::vector<std::tuple<long, long, long>> mpp(N);
  std::vector<std::tuple<long, long, long>> mpm(N);
  std::vector<std::tuple<long, long, long>> mmp(N);
  std::vector<std::tuple<long, long, long>> mmm(N);

  for (size_t i=0; i<N; i++) {
    long x, y, z;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    ppp[i] = std::make_tuple( x,  y,  z);
    ppm[i] = std::make_tuple( x,  y, -z);
    pmp[i] = std::make_tuple( x, -y,  z);
    pmm[i] = std::make_tuple( x, -y, -z);
    mpp[i] = std::make_tuple(-x,  y,  z);
    mpm[i] = std::make_tuple(-x,  y, -z);
    mmp[i] = std::make_tuple(-x, -y,  z);
    mmm[i] = std::make_tuple(-x, -y, -z);
  }

  std::sort(ppp.begin(), ppp.end(), cmp);
  std::sort(ppm.begin(), ppm.end(), cmp);
  std::sort(pmp.begin(), pmp.end(), cmp);
  std::sort(pmm.begin(), pmm.end(), cmp);
  std::sort(mpp.begin(), mpp.end(), cmp);
  std::sort(mpm.begin(), mpm.end(), cmp);
  std::sort(mmp.begin(), mmp.end(), cmp);
  std::sort(mmm.begin(), mmm.end(), cmp);

  long ans =
    std::max({sum(ppp, M),
          sum(ppm, M),
          sum(pmp, M),
          sum(pmm, M),
          sum(mpp, M),
          sum(mpm, M),
          sum(mmp, M),
          sum(mmm, M)});

  std::cout << ans << std::endl;

  return 0;
}
