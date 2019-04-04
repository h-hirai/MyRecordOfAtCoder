#include <iostream>
#include <string>

void testcase() {
  size_t A, B, N;
  std::cin >> A >> B >> N;

  for (size_t i=0; i<N; i++) {
    auto Q = A + (B - A) / 2;
    std::cout << Q << std::endl;

    std::string R;
    std::cin >> R;

    if (R == "TOO_SMALL")
      A = Q;
    else if (R == "TOO_BIG")
      B = Q;
    else
      return;
  }
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t i=0; i<T; i++) testcase();

  return 0;
}
