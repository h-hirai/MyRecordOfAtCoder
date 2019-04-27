#include <iostream>

int main() {

  int sum = 0;
  int slack = 0;

  for (int i=0; i<5; i++) {
    int time;
    std::cin >> time;
    int rem = time % 10;

    if (rem == 0) {
      sum += time;
    } else {
      sum += time - rem + 10;
      slack = std::max(slack, 10-rem);
    }
  }

  std::cout << sum-slack << std::endl;

  return 0;
}
