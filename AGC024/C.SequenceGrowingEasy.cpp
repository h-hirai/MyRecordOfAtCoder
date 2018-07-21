#include <iostream>
#include <cstdlib>

int main() {
  long N;
  std::cin >> N;

  long prev=0;
  long step=0;

  for (size_t i=0; i<N; i++) {
    long a;
    std::cin >> a;

    if (a > i || a > prev+1) {
      std::cout << -1 << std::endl;
      std::exit(EXIT_SUCCESS);
    }

    if (a == prev+1) {
      step+=1;
    } else {
      step+=a;
    }

    prev=a;
  }

  std::cout << step << std::endl;

  return 0;
}
