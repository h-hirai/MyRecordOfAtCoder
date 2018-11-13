#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;

  unsigned long num_m = 0;
  unsigned long num_a = 0;
  unsigned long num_r = 0;
  unsigned long num_c = 0;
  unsigned long num_h = 0;

  for (int i=0; i<n; i++) {
    std::string name;
    std::cin >> name;
    switch (name.front()) {
    case 'M': num_m++; break;
    case 'A': num_a++; break;
    case 'R': num_r++; break;
    case 'C': num_c++; break;
    case 'H': num_h++; break;
    }
  }

  unsigned long ans =
    num_m * num_a * num_r                 +
    num_m * num_a *         num_c         +
    num_m * num_a *                 num_h +
    num_m *         num_r * num_c         +
    num_m *         num_r *         num_h +
    num_m *                 num_c * num_h +

            num_a * num_r * num_c         +
            num_a * num_r *         num_h +
            num_a *         num_c * num_h +

                    num_r * num_c * num_h;

  std::cout << ans << std::endl;

  return 0;
}
