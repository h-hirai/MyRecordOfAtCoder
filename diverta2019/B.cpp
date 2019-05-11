#include <iostream>

int main() {
  int R, G, B, N;
  std::cin >> R >> G >> B >> N;

  int ans = 0;

  for (int r=0; r*R<=N; r++) {
    for (int g=0; r*R+g*G<=N; g++) {
      if ((N - (r*R+g*G)) % B == 0) {
        ans++;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
