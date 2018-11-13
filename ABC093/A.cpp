#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  if (S == "abc" |
      S == "acb" |
      S == "bac" |
      S == "bca" |
      S == "cab" |
      S == "cba")
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
