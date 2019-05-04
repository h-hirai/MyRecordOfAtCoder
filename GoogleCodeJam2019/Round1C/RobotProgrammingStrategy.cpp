#include <iostream>
#include <vector>
#include <string>

std::string
testcase(std::vector<std::string> const& C) {
  std::string res;
  std::vector<bool> finished(C.size(), false);

  for (int i=0; i<500; i++) {
    bool exist_R = false;
    bool exist_S = false;
    bool exist_P = false;

    for (int j=0; j<C.size(); j++) {
      if (finished[j]) continue;

      switch (C[j][i%C[j].size()]) {
      case 'R': exist_R = true; break;
      case 'S': exist_S = true; break;
      case 'P': exist_P = true; break;
      }
    }

    if (exist_R && exist_S && exist_P) {
      return "IMPOSSIBLE";
    } else if ( exist_R &&  exist_S && !exist_P) {
      res.push_back('R');
      for (int j=0; j<C.size(); j++)
        if (C[j][i%C[j].size()] == 'S') finished[i] = true;
    } else if ( exist_R && !exist_S &&  exist_P) {
      res.push_back('P');
      for (int j=0; j<C.size(); j++)
        if (C[j][i%C[j].size()] == 'R') finished[i] = true;
    } else if (!exist_R &&  exist_S &&  exist_P) {
      res.push_back('S');
      for (int j=0; j<C.size(); j++)
        if (C[j][i%C[j].size()] == 'P') finished[i] = true;
    } else if ( exist_R && !exist_S && !exist_P) {
      res.push_back('P');
      return res;
    } else if (!exist_R &&  exist_S && !exist_P) {
      res.push_back('R');
      return res;
    } else if (!exist_R && !exist_S &&  exist_P) {
      res.push_back('S');
      return res;
    }
  }

  return "IMPOSSIBLE";
}

int main() {
  int T;
  std::cin >> T;

  for (int t=1; t<T+1; t++){
    int A;
    std::cin >> A;

    std::vector<std::string> C(A);

    for (int i=0; i<A; i++) {
      std::cin >> C[i];
    }

    std::cout << "Case #" << t << ": " << testcase(C) << std::endl;
  }

  return 0;
}
