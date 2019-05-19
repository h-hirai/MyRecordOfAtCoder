#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  int f = std::stoi(S.substr(0,2));
  int b = std::stoi(S.substr(2,2));

  if (1 <= f && f <= 12) {
    if (1 <= b && b <= 12) {
      std::cout << "AMBIGUOUS" << std::endl;
    } else {
      std::cout << "MMYY" << std::endl;
    }
  } else {
    if (1 <= b && b <= 12) {
      std::cout << "YYMM" << std::endl;
    } else {
      std::cout << "NA" << std::endl;
    }
  }

  return 0;
}
