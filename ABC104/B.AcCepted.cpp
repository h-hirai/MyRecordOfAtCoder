#include <iostream>
#include <string>

bool is_lower(char c) {
  return (c >= 'a') && (c <= 'z');
}

bool judge(std::string const& S) {
  size_t const N = S.length();

  if (S[0] != 'A') return false;
  if (! is_lower(S[1])) return false;

  size_t numC = 0;
  for (size_t i=2; i<N-1; i++) {
    if (S[i] == 'C')
      numC++;
    else if (! is_lower(S[i]))
      return false;

    if (numC > 1)
      return false;
  }

  if (numC != 1)
    return false;

  if (! is_lower(S[N-1]))
    return false;

  return true;
}

int main() {
  std::string S;
  std::cin >> S;

  std::cout << (judge(S) ? "AC" : "WA") << std::endl;

  return 0;
}
