#include <iostream>
#include <string>
#include <vector>

int main() {
  int N, Q;
  std::cin >> N >> Q;

  std::string S;
  std::cin >> S;

  std::vector<int> acc(N);

  for (int i=1; i<N; i++) {
    acc[i] = acc[i-1];
    if (S[i-1] == 'A' && S[i] == 'C') acc[i]+=1;
  }

  for (int i=0; i<Q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << acc[r-1] - acc[l-1] << '\n';
  }

  return 0;
}
