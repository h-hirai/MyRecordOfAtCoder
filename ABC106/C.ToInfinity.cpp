#include <iostream>
#include <string>

int main() {
  std::string S;
  long long K;
  std::cin >> S >> K;

  size_t num1 = 0;
  char first_char = '1';

  for (auto c : S) {
    if (c == '1') {
      num1++;
    } else {
      first_char = c;
      break;
    }
  }

  if (K > num1) {
    std::cout << first_char << std::endl;
  } else {
    std::cout << '1' << std::endl;
  }

  return 0;
}
