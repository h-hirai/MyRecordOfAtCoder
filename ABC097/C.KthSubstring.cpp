#include <iostream>
#include <string>
#include <set>

int main() {
  std::string S;
  long K;

  std::cin >> S;
  std::cin >> K;

  std::string substrbufs[5];
  size_t buf_idx=0;

  std::set<std::string> words;

  for (auto const& c : S) {
    if (buf_idx<5) {
      for (size_t i=0; i<buf_idx+1; i++) {
        substrbufs[i].push_back(c);
      }
    } else {
      substrbufs[buf_idx%5].erase();
      for (size_t i=buf_idx; i<buf_idx+5; i++) {
        substrbufs[i%5].push_back(c);
      }
    }

    for (size_t i=0; i<5; i++) {
      words.insert(substrbufs[i]);
    }

    buf_idx++;
  }

  size_t count=0;
  for (auto const& w : words) {
    if (count == K) {
      std::cout << w << std::endl;
      break;
    }
    count++;
  }

  return 0;
}
