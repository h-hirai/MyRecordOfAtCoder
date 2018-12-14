#include <iostream>
#include <vector>
#include <set>

struct S {
  std::multiset<size_t> set;
  std::multiset<size_t>::const_iterator it;

  S(size_t a)
    : set({a})
    , it(set.cbegin()) {}

  void insert(size_t a) {
    set.insert(a);

    if (set.size() % 2 == 0) {
      if (a >= *it)
        std::advance(it, 1);
    } else {
      if (a < *it)
        std::advance(it, -1);
    }
  }

  size_t median() const {
    return *it;
  }
};

int main() {
  size_t N;

  std::cin >> N;

  std::vector<S> Sets;
  Sets.reserve(N);

  size_t a;
  std::cin >> a;

  Sets.push_back(S(a));

  S Meds(a);

  for (size_t i=1; i<N; i++) {
    std::cin >> a;
    for (auto& s: Sets) {
      s.insert(a);
      Meds.insert(s.median());
    }

    Sets.push_back(S(a));
    Meds.insert(a);
  }

  std::cout << Meds.median() << std::endl;

  return 0;
}
