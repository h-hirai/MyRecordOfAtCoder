#include <iostream>
#include <vector>

unsigned long S(unsigned long N) {
  unsigned long ret=0;
  for (unsigned long n=N; n>0; n/=10)
    ret += n%10;
  return ret;
}

static unsigned long const Ninit = 1000000000000000;

int main() {
  double min = double(Ninit)/double(S(Ninit));
  std::vector<unsigned long> Nums(1000);

  for (unsigned long i=Ninit; i>=1000; i/=10) {
    for (unsigned long j=i; j>i/10; j-=i/1000) {
      unsigned long const n = j-1;
      double const s = double(n)/double(S(n));

      if (s<=min) {
        min = s;
        Nums.push_back(n);
      }
    }
  }

  for (unsigned long n=99; n>10; n-=10) {
    double const s = double(n)/double(S(n));

    if (s<=min) {
      min = s;
      Nums.push_back(n);
    }
  }

  for (unsigned long n=9; n>0; n-=1) {
    double const s = double(n)/double(S(n));

    if (s<=min) {
      min = s;
      Nums.push_back(n);
    }
  }

  size_t k;
  std::cin >> k;

  for (auto i=Nums.crbegin();
       std::distance(Nums.crbegin(), i) < k;
       std::advance(i, 1))
    std::cout << *i << std::endl;

  return 0;
}
