#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long N;
  std::cin >> N;
  std::vector<long> P(N+1, 0);

  for (size_t i=0; i<N; i++) {
    long p;
    std::cin >> p;

    P[p] = P[p-1]+1;
  }

  decltype(P)::const_iterator i=std::max_element(P.begin(), P.end());
  long soted_chunk_size=*i;

  std::cout << (N-soted_chunk_size) << std::endl;

  return 0;
}
