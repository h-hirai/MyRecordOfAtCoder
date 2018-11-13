#include <iostream>

int main() {
  long n, k;

  std::cin >> n;
  std::cin >> k;

  long ans=0;
  for (int b=k+1; b<n+1; b++) {
    ans += (b-k)*(n/b);

    if (k==0) {
      ans += n%b;
    } else if (n%b >= k-1) {
      ans += n%b-(k-1);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
