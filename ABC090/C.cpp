#include <iostream>

int main() {
  long n, m;

  std::cin >> n;
  std::cin >> m;

  long ans=0;

  if (n==1) {
    if (m==1) {
      ans = 1;
    } else {
      ans = m - 2;
    }
  } else if (m==1) {
    ans = n - 2;
  } else {
    ans = (n-2) * (m-2);
  }

  std::cout << ans << std::endl;

  return 0;
}
