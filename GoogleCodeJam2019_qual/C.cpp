#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <exception>

std::string testcase() {
  size_t N, L;
  std::cin >> N >> L;

  std::set<size_t> code;

  std::vector<size_t> decode;
  decode.reserve(L+1);

  size_t cipher, a, b;
  std::cin >> cipher;

  for (size_t n=2; n*n<=cipher; n++) {
    if (cipher % n == 0) {
      a = n;
      b = cipher / n;
      break;
    }
  }

  // if (a == 0 || b == 0 || a*b != cipher) throw std::runtime_error("");

  code.insert(a);
  code.insert(b);

  std::cin >> cipher;

  if (cipher % a == 0) {
    decode.push_back(b);
    decode.push_back(a);
    a = cipher/a;
  } else {
    decode.push_back(a);
    decode.push_back(b);
    a = cipher/b;
  }

  for (size_t i=2; i<L; i++) {
    if (a == 0) throw std::runtime_error("");

    code.insert(a);
    decode.push_back(a);

    std::cin >> cipher;
    a = cipher/a;
  }

  code.insert(a);
  decode.push_back(a);

  std::string ret;

  for (auto const c: decode) {
    ret.push_back('A'+std::distance(code.begin(), code.find(c)));
  }

  return ret;
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++){
    std::cout << "Case #" << t << ": ";
    std::string S;
    try {
      S = testcase();
    } catch (std::runtime_error const& e) {
      S = "RUNTIMEERROR";
    }
    std::cout << S << std::endl;
  }

  return 0;
}
