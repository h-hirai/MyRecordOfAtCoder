#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  if (S.substr(0,5) == "MUJIN")
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
