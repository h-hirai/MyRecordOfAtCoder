#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int whites = 0;
  int blacks = 0;

  int blacks_of_right = 0;

  for (int i=0; i<N; i++) {
    char c;
    std::cin >> c;

    if (c == '.') {
      whites++;
      blacks += blacks_of_right;
      blacks_of_right = 0;
    } else {
      blacks_of_right++;
    }
  }

  int ans = std::min(whites, blacks);

  std::cout << ans << '\n';

  return 0;
}
