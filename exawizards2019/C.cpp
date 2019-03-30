#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using commands_t = std::unordered_map<char, std::map<size_t, bool>>;

int simulate(int N, int i, int j,
             std::string const& S, commands_t const& td) {
  if (i < 0) return -1;
  if (i >= N) return N;

  auto const& cmds = td.at(S[i]);
  auto it = cmds.lower_bound(j);

  if (it == cmds.end()) return i;

  j = it->first;

  if (it->second)
    return simulate(N, i-1, j+1, S, td);
  else
    return simulate(N, i+1, j+1, S, td);
}

int main() {
  size_t N, Q;
  std::string S;

  std::cin >> N >> Q >> S;

  commands_t td;

  for (size_t i=0; i<Q; i++) {
    char t, d;
    std::cin >> t >> d;

    td[t].emplace(i, d=='L');
  }

  auto ans = N;

  {
    size_t first = 0;
    size_t last = N;

    for (auto len = last-first; len != 0; ) {
      auto half = len / 2;
      auto mid = first + half;
      if (simulate(N, mid, 0, S, td) < 0) {
        len -= half + 1;
        first = mid + 1;
      } else {
        len = half;
      }
    }

    ans -= first;
  }

  {
    size_t first = 0;
    size_t last = N;

    for (auto len = last-first; len != 0; ) {
      auto half = len / 2;
      auto mid = first + half;
      if (simulate(N, mid, 0, S, td) < static_cast<int>(N)) {
        len -= half + 1;
        first = mid + 1;
      } else {
        len = half;
      }
    }

    ans -= N-first;
  }

  std::cout << ans << std::endl;

  return 0;
}
