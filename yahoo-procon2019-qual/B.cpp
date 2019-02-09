#include <iostream>
#include <vector>

int main() {
  std::vector<size_t> paths_of_town(4, 0);

  for (size_t i=0; i<3; i++) {
    size_t a, b;
    std::cin >> a >> b;

    paths_of_town[a-1]++;
    paths_of_town[b-1]++;
  }

  size_t ans_1 = 0;
  size_t ans_2 = 0;

  for (size_t i=0; i<4; i++) {
    if (paths_of_town[i] == 1) {
      ans_1++;
    } else if (paths_of_town[i] == 2) {
      ans_2++;
    }
  }

  std::cout << (ans_1 == 2 && ans_2 == 2 ? "YES" : "NO") << std::endl;

  return 0;
}
