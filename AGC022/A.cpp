#include <iostream>
#include <string>
#include <cassert>

char search_min_char(std::string const & s) {
  for (char const c : "abcdefghijklmnopqrstuvwxyz") {
    if (s.find(c) < s.size()) {
      continue;
    } else {
      return c;
    }
  }

  assert(false);
}

char carry(std::string const & s, char b) {
  while (s.find(b) < s.size()) b+=1;
  return b;
}

void judge_carry(std::string const & s, char c) {
  if (s == "z") {
    std::cout << "-1" << std::endl;
    return;
  } else {
    std::string const substr(s.substr(0, s.size()-1));
    char b(s.back());
    if (b < c) {
      std::cout << substr << carry(substr, b+1) << std::endl;
    } else {
      judge_carry(substr, b);
    }
  }
}

int main() {
  std::string S;

  std::cin >> S;

  if (S.size() < 26) {
    std::cout << S << search_min_char(S) << std::endl;
  } else {
    judge_carry(S.substr(0, S.size()-1), S.back());
  }

  return 0;
}
