#include <iostream>
#include <string>

bool judge(std::string const& S) {
  static std::string const T("keyence");

  if (S.substr(0, 7) == T) return true;
  if (S.substr(S.size()-7, 7) == T) return true;

  size_t i=0;

  for (; S[i] == T[i]; i++);

  std::cerr << i << std::endl;

  if (i==0) return false;

  size_t j=0;
  for (; S[S.size()-j-1] == T[7-j-1]; j++);

  std::cerr << j << std::endl;

  return i+j>=7;
}

int main() {
  std::string S;
  std::cin >> S;

  std::cout << (judge(S) ? "YES" : "NO") << std::endl;

  return 0;
}
