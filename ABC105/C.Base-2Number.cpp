#include <iostream>
#include <cmath>
#include <bitset>

std::bitset<35> solv(long n) {
  if (n == 0) {
    return std::bitset<35>(0);
  } else {
    size_t i;
    long a;
    std::bitset<35> ret;
    if (n < 0) {
      i = 1;
      a = -2;
      while (n < a) {
        i += 2;
        a += -(1<<i);
      }
      ret = solv(n + (1<<i));
    } else {
      i = 0;
      a = 1;
      while (n > a) {
        i += 2;
        a += (1<<i);
      }
      ret = solv(n - (1<<i));
    }

    ret.set(i);
    return ret;
  }
}

int main() {
  long n;
  std::cin >> n;

  auto ret = solv(n);

  bool put_flag = false;

  for (ssize_t i=35; i>=0; i--) {
    if (ret[i]) {
      std::cout << '1';
      put_flag = true;
    } else if (put_flag) {
      std::cout << '0';
    }
  }

  if (! put_flag) {
    std::cout << '0';
  }

  std::cout << std::endl;

  return 0;
}
