#include <iostream>

int solv(int A, int B, int K) {
  int k=0;

  for (int i=std::max(A, B); i>0; i--) {
    if (A%i == 0 && B%i ==0) k++;
    if (k == K) return i;
  }

  return 100;
}

int main() {
  int A, B, K;

  std::cin >> A >> B >> K;

  std::cout << solv(A, B, K) << std::endl;

  return 0;
}
