#include <iostream>
#include <string>
#include <vector>
#include <set>

std::string testcase() {
  size_t N, L;
  std::cin >> N >> L;

  std::vector<size_t> products(L);
  for (size_t i=0; i<L; i++) std::cin >> products[i];

  size_t j=0;
  for (; products[j]==products[j+1]; j++);

  size_t a = 2;
  for (; products[j] % a != 0; a++);
  size_t b = products[j] / a;

  if (products[j+1] % a == 0) std::swap(a, b);

  std::vector<size_t> factos(L+1);

  for (ssize_t i=j; i>=0; i--) {
    factos[i] = a;
    std::swap(a, b);
  }

  for (size_t i=j+1; i<L+1; i++) {
    factos[i] = products[i-1] / factos[i-1];
  }

  std::set<size_t> codebook;
  for (auto f: factos) codebook.insert(f);

  std::string ret;
  for (auto f: factos) {
    auto it = codebook.find(f);
    ret.push_back('A'+std::distance(codebook.begin(), it));
  }

  return ret;
}

int main() {
  size_t T;
  std::cin >> T;

  for (size_t t=1; t<T+1; t++){
    std::cout << "Case #" << t << ": "
              << testcase() << std::endl;
  }

  return 0;
}
