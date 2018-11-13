#include <iostream>

int b[201];
int d[201];

int main() {
  long n;
  std::cin >> n;

  for (int i=0; i<n; i++) {
    int a;
    std::cin >> a;
    std::cin >> b[a];
    b[a] += 1;
  }

  for (int i=0; i<n; i++) {
    int c;
    std::cin >> c;
    std::cin >> d[c];
    d[c] += 1;
  }

  int ans=0;
  for (int c=0; c<201; c++) {
    if (d[c] != 0) {
      int max_b = 0;
      int cand_a = 0;
      for (int a=0; a<c; a++) {
        if (b[a] > max_b && b[a] < d[c]) {
          max_b = b[a];
          cand_a = a;
        }
      }
      if (max_b != 0) {
        b[cand_a] = 0;
        ans++;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
