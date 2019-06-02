#include <iostream>
#include <vector>

int main() {
  int N, A, B, C, D;

  std::cin >> N >> A >> B >> C >> D;
  A--; B--; C--; D--;

  std::vector<bool> rocks(N);

  for (int i=0; i<N; i++) {
    char c;
    std::cin >> c;
    rocks[i] = c == '#';
  }

  for (int i=A+1; i<std::max(C, D); i++) {
    if (rocks[i-1] && rocks[i]) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  bool ans = false;

  if (C < D) {
    // C < D なら追い抜きはいらない
    ans = true;
  } else {
    // D < C なら A はとちゅうで B を追い抜くスペースがいる
    int avail = 0;
    for (int i=B+1; i<D; i++) {
      if (rocks[i]) {
        avail = 0;
      } else {
        avail++;
        if (avail > 2) {
          ans = true;
          break;
        }
      }
    }
  }

  std::cout << (ans?"Yes":"No") << std::endl;

  return 0;
}
