#include <iostream>
#include <vector>

int gcd(int m, int n) {
  if (n == 0) return m;
  else return gcd(n, m%n);
}

int main() {
  int N;

  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> G_ord(N+1);

  std::cin >> A[0];
  G_ord[0] = A[0];
  G_ord[1] = A[0];

  for (int i=1; i<N; i++) {
    std::cin >> A[i];
    G_ord[i+1] = gcd(G_ord[i], A[i]);
  }

  std::vector<int> G_rev(N+1);
  G_rev[N] = A[N-1];
  G_rev[N-1] = A[N-1];

  for (int i=N-2; i>=0; i--) {
    G_rev[i] = gcd(G_rev[i+1], A[i]);
  }

  int ans = G_rev[1];

  for (int i=1; i<N-1; i++) {
    ans = std::max(ans, gcd(G_ord[i], G_rev[i+1]));
  }

  ans = std::max(ans, G_ord[N-1]);

  std::cout << ans << std::endl;

  return 0;
}
