#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;

  int ans = 0;

  int has_B_prefix = 0;
  int has_A_postfix = 0;
  int has_Both = 0;

  for (int i=0; i<N; i++) {
    std::string s;
    std::cin >> s;

    for (int j=1; j<s.size(); j++) {
      if (s[j-1] == 'A' && s[j] == 'B') ans++;
    }

    if (s.front() == 'B') {
      if (s.back() == 'A') {
        has_Both++;
      } else {
        has_B_prefix++;
      }
    } else {
      if (s.back() == 'A') {
        has_A_postfix++;
      }
    }
  }

  if (has_Both > 0) {
    ans += has_Both - 1;

    if (has_A_postfix > 0) {
      ans += 1;
      has_A_postfix--;
    }

    if (has_B_prefix) {
      ans += 1;
      has_B_prefix--;
    }
  }

  ans += std::min(has_A_postfix, has_B_prefix);

  std::cout << ans << std::endl;

  return 0;
}
