#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int>
testcase(int Q,
         std::unordered_map<int, int>& n_people,
         std::unordered_map<int, int>& s_people,
         std::unordered_map<int, int>& e_people,
         std::unordered_map<int, int>& w_people) {
  std::vector<int> acc_n_people(Q);
  for (int i=1; i<Q; i++) {
    acc_n_people[i] = acc_n_people[i-1] + n_people[i-1];
  }

  std::vector<int> acc_s_people(Q);
  for (int i=Q-2; i>=0; i--) {
    acc_s_people[i] = acc_s_people[i+1] + s_people[i+1];
  }

  std::vector<int> acc_e_people(Q);
  for (int i=1; i<Q; i++) {
    acc_e_people[i] = acc_e_people[i-1] + e_people[i-1];
  }

  std::vector<int> acc_w_people(Q);
  for (int i=Q-2; i>=0; i--) {
    acc_w_people[i] = acc_w_people[i+1] + w_people[i+1];
  }

  int y=0;
  int max_v=0;

  for (int i=0; i<Q; i++) {
    auto s = acc_n_people[i] + acc_s_people[i];
    // std::cerr << ' ' << s;
    if (s > max_v) {
      y = i;
      max_v = s;
    }
  }
  // std::cerr << std::endl;

  int x=0;
  int max_h=0;

  for (int i=0; i<Q; i++) {
    auto s = acc_e_people[i] + acc_w_people[i];
    // std::cerr << ' ' << s;
    if (s > max_h) {
      x = i;
      max_h = s;
    }
  }
  // std::cerr << std::endl;

  return std::make_pair(x, y);
}

int main() {
  int T;
  std::cin >> T;

  for (int t=1; t<T+1; t++){
    int P, Q;
    std::cin >> P >> Q;

    std::unordered_map<int, int> n_people;
    std::unordered_map<int, int> s_people;
    std::unordered_map<int, int> e_people;
    std::unordered_map<int, int> w_people;

    for (int i=0; i<P; i++) {
      int x, y;
      char d;
      std::cin >> x >> y >> d;
      switch (d) {
      case 'N': n_people[y]++; break;
      case 'S': s_people[y]++; break;
      case 'E': e_people[x]++; break;
      case 'W': w_people[x]++; break;
      }
    }

    int x, y;
    std::tie(x, y) = testcase(Q, n_people, s_people, e_people, w_people);

    std::cout << "Case #" << t << ": " << x << ' ' << y << std::endl;
  }

  return 0;
}
