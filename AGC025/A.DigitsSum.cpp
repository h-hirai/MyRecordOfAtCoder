#include <iostream>

int main() {
  long N;

  std::cin >> N;

  int ans=0;

  if (N==10 || N==100 ||N==1000 ||N==10000 || N==100000) {
    ans = 10;
  } else {
    for (int i=0; i<5; i++) {
      ans += N%10;
      N /=10;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
