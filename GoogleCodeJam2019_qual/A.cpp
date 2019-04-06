#include <iostream>
#include <string>

void testcase(size_t t) {
  std::string S;
  std::cin >> S;

  std::string A, B;

  for (auto const c: S) {
    if (c == '0') {
      A.push_back('0');
      B.push_back('0');
    } else if (c == '5') {
      A.push_back('3');
      B.push_back('2');
    } else {
      A.push_back(c - 1);
      B.push_back('1');
    }
  }

  std::cout << "Case #"
            << t << ": "
            << A << " "
            << B << std::endl;
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++) testcase(t);

  return 0;
}
