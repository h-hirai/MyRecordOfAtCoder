#include <iostream>
#include <string>
#include <map>

bool judge(std::string const& S,
           std::string const& T) {
  if (S == T) return true;

  std::map<char, char> dict;

  for (size_t i=0; i<S.length(); i++) {
    if (dict.count(S[i]) > 0) {
      if (dict[S[i]] != T[i]) return false;
    } else {
      dict.insert(std::make_pair(S[i], T[i]));
    }
  }

  return dict.size() < 27;
}

int main() {
  std::string S, T;

  std::cin >> S >> T;

  std::cout << (judge(S, T) && judge(T, S) ? "Yes" : "No") << std::endl;

  return 0;
}
