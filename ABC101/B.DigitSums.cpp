#include <iostream>

int main() {
  unsigned int N;

  std::cin >> N;

  unsigned S = 0;

  for (unsigned n=N; n>0; n/=10)
    S += n%10;

  std::cout << (N%S==0?"Yes":"No") << std::endl;

  return 0;
}
