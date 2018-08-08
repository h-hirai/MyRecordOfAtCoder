#include <iostream>
#include <string>

int main() {
  size_t A;
  std::string S;
  std::cin >> A;
  std::cin >> S;

  bool ans = false;

  for (auto const c : S) {
    if (A == 0) {
      ans = true;
      break;
    }
    if (c == '+') A++;
    else if (c == '-') {
      A--;
    }
  }

  if (A == 0) {
    ans = true;
  }

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}
