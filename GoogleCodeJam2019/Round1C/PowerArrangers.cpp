#include <iostream>
#include <vector>
#include <map>
#include <string>

// #include <fstream>
// std::ofstream ofs;

std::string
testcase() {
  std::string res;

  std::map<char, std::vector<int>> memo;

  for (int i=0; i<119; i++) {
    std::cout << (i*5 + 1) << std::endl;
    char L;
    std::cin >> L;

    memo[L].push_back(i);
  }

  // for (auto r: memo) {
  //   ofs << r.first << ": " << r.second.size() << std::endl;
  // }

  std::pair<char, std::vector<int>> p;

  for (auto const& q: memo) {
    if (q.second.size() == 23) {
      p = q;
    }
  }
  res.push_back(p.first);

  memo.clear();
  for (auto i: p.second) {
    std::cout << (i*5 + 2) << std::endl;
    char L;
    std::cin >> L;

    memo[L].push_back(i);
  }

  // for (auto r: memo) {
  //   ofs << r.first << ": " << r.second.size() << std::endl;
  // }

  for (auto const& q: memo) {
    if (q.second.size() == 5) {
      p = q;
    }
  }
  res.push_back(p.first);

  memo.clear();
  for (auto i: p.second) {
    std::cout << (i*5 + 3) << std::endl;
    char L;
    std::cin >> L;

    memo[L].push_back(i);
  }

  // for (auto r: memo) {
  //   ofs << r.first << ": " << r.second.size() << std::endl;
  // }

  for (auto const& q: memo) {
    if (q.second.size() == 1) {
      p = q;
    }
  }
  res.push_back(p.first);

  for (auto i: p.second) {
    // ofs << (i*5 + 4) << std::endl;
    std::cout << (i*5 + 4) << std::endl;
    char L;
    std::cin >> L;
    // ofs << L << std::endl;
    res.push_back(L);

    // ofs << (i*5 + 5) << std::endl;
    std::cout << (i*5 + 5) << std::endl;
    std::cin >> L;
    // ofs << L << std::endl;
    res.push_back(L);
  }

  std::swap(res[3], res[4]);

  return res;
}

int main() {
  // ofs.open("debug.log");

  int T, _F;
  std::cin >> T >> _F;

  for (int t=1; t<T+1; t++){
    auto ans = testcase();
    // ofs << ans << std::endl;
    std::cout << ans << std::endl;
    char R;
    std::cin >> R;
    // ofs << R << std::endl;
    if (R != 'Y') return -1;
  }

  return 0;
}
