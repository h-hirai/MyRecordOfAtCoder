#include <iostream>
#include <iomanip>

unsigned long S(unsigned long N) {
  unsigned long ret=0;
  for (unsigned long n=N; n>0; n/=10)
    ret += n%10;
  return ret;
}

int main() {
  // unsigned long N=1000000000000000;
  unsigned long N=1000000000;
  double min = double(N)/double(S(N));

  for (; N>0; N--) {
    double s = double(N)/double(S(N));
    if (s<=min) {
      std::cout << std::setw(15) << N
                << std::setw(5) << S(N)
                << std::setw(10) << s
                << std::endl;
      min = s;
    }
  }

  return 0;
}
