#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct Rank {
  std::map<size_t, size_t> memo;
  std::map<size_t, std::set<size_t>> const& parents;

  Rank(decltype(parents) const& p)
    : parents(p) {};

  size_t operator()(size_t node) {
    if (memo.count(node) > 0) {
      return memo.at(node);
    } else if (parents.count(node) > 0) {
      size_t ret = 0;
      auto const& ps = parents.at(node);
      for (auto p : ps) {
        ret = std::max(ret, (*this)(p)) + 1;
      }
      memo.insert(std::make_pair(node, ret));
      return ret;
    } else {
      return 0;
    }
  }
};

int main() {
  size_t N, M;

  std::cin >> N >> M;

  size_t const NumEdges = N - 1 + M;
  std::vector<std::pair<size_t, size_t>> Edgeds(NumEdges);
  std::map<size_t, std::set<size_t>> Parents;

  for (size_t i=0; i<NumEdges; i++) {
    size_t A, B;
    std::cin >> A >> B;
    A--; B--;
    Edgeds[i] = std::make_pair(A, B);
    if (Parents.count(B) > 0) {
      Parents.at(B).insert(A);
    } else {
      std::set<size_t> s;
      s.insert(A);
      Parents.insert(std::make_pair(B, s));
    }
  }

  Rank rank(Parents);

  for (size_t i=0; i<N; i++) {
    if (Parents.count(i) > 0) {
      auto const& ps = Parents.at(i);
      auto ans = *std::max_element(ps.begin(), ps.end(),
                                   [&](auto a, auto b){return rank(a) < rank(b);});
      std::cout << (ans + 1) << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }

  return 0;
}
