#include <iostream>

size_t next_quasi753(size_t n) {
  if (n < 357) return 357;

  size_t r = n % 10;

  bool carry = false;

  if (r == 7) {
    carry = true;
    r = 3;
  } else if (r == 5) {
    r = 7;
  } else {
    r = 5;
  }

  size_t digit = 10;
  n /= 10;

  for (; n > 0; n /= 10) {
    auto d = n % 10;
    if (carry) {
      if (d == 7) {
        d = 3;
      } else if (d == 5) {
        carry = false;
        d = 7;
      } else {
        carry = false;
        d = 5;
      }
    }

    r += d * digit;
    digit *= 10;
  }

  if (carry)
    return 3*digit+r;
  else
    return r;
}

bool is_753(size_t n) {
  bool has_7 = false;
  bool has_5 = false;
  bool has_3 = false;

  for (; n > 0; n /= 10) {
    switch (n % 10) {
    case 7:
      has_7 = true;
      break;
    case 5:
      has_5 = true;
      break;
    case 3:
      has_3 = true;
      break;
    default:
      return false;
    }
  }

  return has_7 & has_5 & has_3;
}

int main() {
  size_t N;

  std::cin >> N;

  size_t n = 0;
  size_t ans = 0;

  while (N >= (n = next_quasi753(n))) {
    // std::cerr << n << std::endl;
    if (is_753(n)) ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}
