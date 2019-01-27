#include <iostream>
#include <string>
#include <algorithm>

size_t solv(size_t N,
            std::string const& A,
            std::string const& B,
            std::string const& C) {
  size_t ret=0;

  for (size_t i=0; i<N; i++) {
    if (A[i] == B[i])
      if (B[i] == C[i])
        ret+=0;
      else
        ret+=1;
    else
      if (B[i] == C[i])
        ret+=1;
      else if (A[i] == C[i])
        ret+=1;
      else
        ret+=2;
  }


  return ret;
}

int main() {
  size_t N;
  std::string A, B, C;

  std::cin >> N;
  std::cin >> A >> B >> C;

  std::cout << solv(N, A, B, C) << std::endl;

  return 0;
}
