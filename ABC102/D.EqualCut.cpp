#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using vec = std::vector<unsigned long>;

unsigned long
differ(unsigned long begin,
       unsigned long cut,
       unsigned long  end) {
  unsigned long sum_l = cut - begin;
  unsigned long sum_r = end - cut;
  long diff = sum_r - sum_l;

  return std::abs(diff);
}

int main() {
  size_t N;
  std::cin >> N;

  vec Sum(N+1);

  unsigned long sum = 0;
  Sum[0] = sum;

  for (size_t i=1; i<N+1; i++) {
    unsigned long a;
    std::cin >> a;

    sum += a;

    Sum[i] = sum;
  }

  std::vector<vec::const_iterator> splits_l(N+1);
  vec::const_iterator cut_l = Sum.cbegin() + 1;

  for (auto end=Sum.cbegin()+2;
       end != Sum.cend()-2;
       std::advance(end, 1)) {
    unsigned long prediff = differ(*Sum.cbegin(), *cut_l, *end);
    for (;
         cut_l != end;
         std::advance(cut_l, 1)) {
      unsigned long diff = differ(*Sum.cbegin(), *cut_l, *end);
      if (prediff < diff) break;
      prediff = diff;
    }

    std::advance(cut_l, -1);
    splits_l[std::distance(Sum.cbegin(), end)] = cut_l;
  }

  std::vector<vec::const_iterator> splits_r(N+1);
  auto cut_r = Sum.crbegin() + 1;

  for (auto begin=Sum.crbegin()+2;
       begin != Sum.crend()-2;
       std::advance(begin, 1)) {
    unsigned long prediff = differ(*begin, *cut_r, *Sum.crbegin());
    for (;
         cut_r != begin;
         std::advance(cut_r, 1)) {
      unsigned long diff = differ(*begin, *cut_r, *Sum.crbegin());
      if (prediff < diff) break;
      prediff = diff;
    }

    std::advance(cut_r, -1);
    splits_r[std::distance(Sum.cbegin(), begin.base())-1] =
      cut_r.base() - 1;
  }

  unsigned long ans = sum;

  for (size_t i=2; i<N-1; i++) {
    unsigned long p = *splits_l[i];
    unsigned long q = Sum[i] - p;
    unsigned long r = *splits_r[i] - Sum[i];
    unsigned long s = sum - *splits_r[i];

    ans = std::min(ans,
                   std::max({p, q, r, s}) - std::min({p, q, r, s}));
  }

  std::cout << ans << std::endl;

  return 0;
}
