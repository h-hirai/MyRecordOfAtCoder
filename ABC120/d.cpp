#include <iostream>
#include <vector>
#include <unordered_map>

using ull = unsigned long long;

struct UnionFindWithSize {
  std::vector<size_t> par;
  std::unordered_map<size_t, ull> num_conn;

  UnionFindWithSize(size_t N) : par(), num_conn() {
    par.reserve(N);
    for (size_t i=0; i<N; i++) {
      par.push_back(i);
      num_conn.insert(std::make_pair(i, 1));
    }
  }

  size_t root(size_t x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(size_t x, size_t y) {
    return root(x) == root(y);
  }

  ull size(size_t x) {
    return num_conn[root(x)];
  }

  void unite(size_t x, size_t y) {
    size_t root_x = root(x);
    size_t root_y = root(y);
    if (root_x == root_y) return;

    par[root_y] = root_x;
    num_conn[root_x] += num_conn[root_y];
    num_conn.erase(root_y);
  }
};

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<std::pair<size_t, size_t>> Edges;
  Edges.reserve(M);

  for (size_t i=0; i<M; i++) {
    size_t a, b;
    std::cin >> a >> b;
    Edges.push_back(std::make_pair(a-1, b-1));
  }

  UnionFindWithSize uf(N);
  std::vector<ull> ans;
  ans.reserve(M+1);

  ans.push_back(N * (N-1) / 2);

  for (auto i=Edges.crbegin();
       i!=Edges.crend();
       i++) {
    auto a = ans.back();

    auto v0 = i->first;
    auto v1 = i->second;

    if (uf.same(v0, v1)) {
      ans.push_back(a);
    } else {
      auto s0 = uf.size(v0);
      auto s1 = uf.size(v1);

      ans.push_back(a - s0 * s1);
      uf.unite(v0, v1);
    }
  }

  ans.pop_back();

  for (auto i=ans.crbegin(); i != ans.crend(); i++) {
    std::cout << *i << '\n';
  }

  return 0;
}
