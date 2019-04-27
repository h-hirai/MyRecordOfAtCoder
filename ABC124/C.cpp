#include <iostream>
#include <string>

int main() {
  std::string S;

  std::cin >> S;

  int const N = S.size();

  int even_black = 0;
  int even_white = 0;
  int odd_black = 0;
  int odd_white = 0;

  for (int i=0; i<N; i++) {
    if (i%2 == 0) {
      if (S[i] == '0') {
        even_black++;
      } else {
        even_white++;
      }
    } else {
      if (S[i] == '0') {
        odd_black++;
      } else {
        odd_white++;
      }
    }
  }

  auto ans = std::min(even_white+odd_black, even_black+odd_white);

  std::cout << ans << std::endl;

  return 0;
}
