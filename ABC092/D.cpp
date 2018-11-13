#include <iostream>
#include <vector>

long max(long v, long w) {
  return (v > w) ? v : w;
}

long abs(long v) {
  return (v < 0) ? -v : v;
}

int main() {
  long A, B;

  std::cin >> A;
  std::cin >> B;

  long differ = abs(A - B);
  long common = max(A, B) - differ;

  long w;

  if (common > differ) {
    if (common > 50) {
      w = 50;
    } else {
      

  return 0;
}


