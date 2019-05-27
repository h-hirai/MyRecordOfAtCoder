#include <iostream>
#include <vector>
#include <bitset>

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<int> S(M);

  for (int i=0; i<M; i++) {
    std::bitset<10> ss(0);

    int k;
    std::cin >> k;

    for (int j=0; j<k; j++) {
      int s;
      std::cin >> s;
      ss.set(s-1);
    }

    S[i] = ss.to_ulong();
  }

  std::vector<int> P(M);
  for (int i=0; i<M; i++) std::cin >> P[i];

  int ans = 0;

  for (int j=0; j<1<<N; j++) {
    int on_M = 0;
    for (int i=0; i<M; i++) {
      auto c = std::bitset<10>(S[i] & j).count();
      if (c % 2 == P[i]) on_M++;
    }
    if (on_M == M) ans++;;
  }

  std::cout << ans << std::endl;

  return 0;
}
