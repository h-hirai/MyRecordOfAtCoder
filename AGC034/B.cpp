#include <iostream>
#include <string>

using ll = long long;

ll count_a(std::string const& S, int i, ll ret, ll cnt_a);
ll look_bc(std::string const& S, int i, ll ret, ll cnt_a);

ll neutral(std::string const& S, int i, ll ret) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, 1);
    } else {
      return neutral(S, i+1, ret);
    }
  } else {
    return ret;
  }
}

ll count_a(std::string const& S, int i, ll ret, ll cnt_a) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, cnt_a+1);
    } else if (S[i] == 'B' && S[i+1] == 'C') {
      return look_bc(S, i+2, ret+cnt_a, cnt_a);
    } else {
      return neutral(S, i+1, ret);
    }
  } else {
    return ret;
  }
}

ll look_bc(std::string const& S, int i, ll ret, ll cnt_a) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, cnt_a+1);
    } else if (S[i] == 'B' && S[i+1] == 'C') {
      return look_bc(S, i+2, ret+cnt_a, cnt_a);
    } else {
      return neutral(S, i+1, ret);
    }
  } else {
    return ret;
  }
}

int main() {
  std::string S;

  std::cin >> S;

  ll ans = neutral(S, 0, 0);

  std::cout << ans << std::endl;

  return 0;
}
