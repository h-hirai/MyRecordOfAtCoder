#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int whites = 0;
  int blacks = 0;

  int whites_of_left = 0;
  int blacks_of_right = 0;

  for (int i=0; i<N; i++) {
    char c;
    std::cin >> c;

    if (c == '.') {
      whites++;
      if (blacks == 0) whites_of_left++;

      blacks_of_right = 0;
    } else {
      blacks++;
      blacks_of_right++;
    }
  }

  int ans = std::min(whites-whites_of_left, blacks-blacks_of_right);

  std::cout << ans << '\n';

  return 0;
}
