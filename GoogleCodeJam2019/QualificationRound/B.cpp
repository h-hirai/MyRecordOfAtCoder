#include <iostream>
#include <string>

void testcase(size_t t) {
  size_t _N;
  std::string P;
  std::cin >> _N >> P;

  std::cout << "Case #" << t << ": ";

  for (auto const c: P) {
    if (c == 'S') {
      std::cout << 'E';
    } else {
      std::cout << 'S';
    }
  }
  std::cout << std::endl;
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++) testcase(t);

  return 0;
}
