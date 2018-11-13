#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <cassert>

std::tuple<ssize_t, ssize_t>
search(ssize_t N,
       std::vector<ssize_t> const& A,
       std::vector<ssize_t> const& Differs,
       size_t start_lower,
       size_t start_upper) {
  ssize_t v = 0;

  ssize_t minSub=A[start_lower];
  ssize_t minAdd=N-A[start_upper];
  ssize_t maxD=std::max(Differs[start_lower], Differs[start_upper]);
  ssize_t minD=std::max(Differs[start_lower], Differs[start_upper]);

  ssize_t i = 1;
  for (; start_lower+i < start_upper-i; i++) {
    ssize_t new_v = std::abs(maxD - minD) / 2;

    if (new_v > minSub || new_v > minAdd)
      return std::make_tuple(i-1, v);

    v = new_v;

    minSub = std::min(minSub, A[start_lower+i]);
    minAdd = std::min(minAdd, N-A[start_upper-i]);
    maxD = std::max({maxD, Differs[start_lower+i], Differs[start_upper-i]});
    minD = std::min({minD, Differs[start_lower+i], Differs[start_upper-i]});
  }

  return std::make_tuple(i-1, v);
}

void
update(ssize_t N,
       std::vector<ssize_t> & A,
       std::vector<ssize_t> & Differs,
       ssize_t i, ssize_t j, ssize_t k, ssize_t l, ssize_t v) {
  for(; i<j+1; i++) {
    A[i] += v;
    Differs[i] += v;
    assert(1<=A[i] && A[i]<=N);
  }

  for(; k<l+1; k++) {
    A[k] -= v;
    Differs[k] -= v;
    assert(1<=A[k] && A[k]<=N);
  }
}

int main() {
  size_t N, K;
  std::cin >> N >> K;

  std::vector<ssize_t> A(N);
  std::vector<ssize_t> Differs(N);

  for (size_t i=0; i<N; i++) {
    std::cin >> A[i];
    Differs[i] = A[i] - i;
  }

  ssize_t i = 0;
  ssize_t l = N-1;

  size_t iterate_k=0;
  while (iterate_k < K) {
    ssize_t width;
    ssize_t v;
    std::tie(width, v) = search(N, A, Differs, i, l);
    ssize_t j = i + width;
    ssize_t k = l - width;

    // for (auto a : A)
    //   std::cout << ' ' << a;
    // std::cout << std::endl;

    // for (auto d : Differs) {
    //   std::cout << ' ' << d;
    // }
    // std::cout << std::endl;

    // size_t sum=0;
    // for (auto d : Differs) {
    //   sum += std::abs(d);
    // }
    // std::cout << sum << std::endl;

    if (v > 0) {
      std::cout << i+1 << ' '
                << j+1 << ' '
                << k+1 << ' '
                << l+1 << ' '
                << v << std::endl;
      update(N, A, Differs, i, j, k, l, v);
      iterate_k++;
    }

    if (j<k) {
      i = j+1;
      l = k-1;
    } else {
      i = 0;
      l = N-1;
    }
  }

  // for (size_t i=0; i<K; i++) {
  //   std::cout << 1 << ' '
  //             << 15000 << ' '
  //             << 15001 << ' '
  //             << 30000 << ' '
  //             << 0 << std::endl;
  // }

  return 0;
}
