#include <iostream>
#include <list>

int main() {
  size_t N;

  std::cin >> N;

  std::list<size_t> b;

  for (size_t i=0; i<N; i++) {
    size_t a;
    std::cin >> a;

    if (a > i+1) {
      std::cout << -1 << std::endl;
      return 0;
    }

    auto it = std::next(b.begin(), a-1);
    b.insert(it, a);
  }

  for (auto it = b.begin(); it != b.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}
