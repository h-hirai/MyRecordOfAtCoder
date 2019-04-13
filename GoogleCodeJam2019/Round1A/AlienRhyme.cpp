#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

size_t
search(std::vector<std::string> const& Ws,
       std::vector<size_t> const& Selected,
       size_t const Index) {
  // for (auto i: Selected) std::cerr << ' ' << i;
  // std::cerr << std::endl;

  char curr = '0';
  std::vector<std::vector<size_t>> newGroups;

  for (auto const i: Selected) {
    if (Index >= Ws[i].size()) continue;

    if (curr == Ws[i][Index]) {
      newGroups.back().push_back(i);
    } else {
      newGroups.push_back(std::vector<size_t>());
      newGroups.back().push_back(i);
      curr = Ws[i][Index];
    }
  }

  size_t ans = 0;
  for (auto const& g: newGroups) {
    if (g.size() > 1) {
      ans += search(Ws, g, Index+1);
    }
  }

  if (Selected.size() - ans >= 2) ans += 2;

  return ans;
}

size_t
testcase(std::vector<std::string> const& Ws) {
  size_t const Index = 0;

  char curr = '0';
  std::vector<std::vector<size_t>> newGroups;

  for (size_t i=0; i<Ws.size(); i++) {
    if (curr == Ws[i][Index]) {
      newGroups.back().push_back(i);
    } else {
      newGroups.push_back(std::vector<size_t>());
      newGroups.back().push_back(i);
      curr = Ws[i][Index];
    }
  }

  size_t ans = 0;
  for (auto const& g: newGroups) {
    if (g.size() > 1) {
      ans += search(Ws, g, Index+1);
    }
  }

  return ans;
}

#include <iomanip>

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++){
    size_t N;
    std::cin >> N;

    std::vector<std::string> Ws(N);
    for (size_t i=0; i<N; i++) std::cin >> Ws[i];

    std::vector<std::string> R(Ws.size());
    for (size_t i=0; i<R.size(); i++) {
      for (auto it=Ws[i].crbegin(); it != Ws[i].crend(); it++)
        R[i].push_back(*it);
    }

    std::sort(R.begin(), R.end());

    std::cout << "Case #" << t << ": " << testcase(R) << std::endl;
  }

  return 0;
}
