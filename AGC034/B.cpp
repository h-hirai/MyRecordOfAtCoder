#include <iostream>
#include <string>

using ll = long long;

ll count_a(std::string const& S, int i,
           ll ret, ll cnt_a, bool flg_abc);

ll look_bc(std::string const& S, int i,
           ll ret, ll cnt_a, bool flg_abc);

ll neutral(std::string const& S, int i,
           ll ret) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, 1, false);
    } else {
      return neutral(S, i+1, ret);
    }
  } else {
    return ret;
  }
}

ll count_a(std::string const& S, int i,
           ll ret, ll cnt_a, bool flg_abc) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, cnt_a+1, flg_abc);
    } else if (S[i] == 'B' && S[i+1] == 'C') {
      if (flg_abc) ret+=1;
      return look_bc(S, i+2, ret+cnt_a, cnt_a, true);
    } else {
      return neutral(S, i+1, ret);
    }
  } else {
    return ret;
  }
}

ll look_bc(std::string const& S, int i,
           ll ret, ll cnt_a, bool flg_abc) {
  if (i < S.size()-1) {
    if (S[i] == 'A') {
      return count_a(S, i+1, ret, 1, true);
    } else if (S[i] == 'B' && S[i+1] == 'C') {
      return look_bc(S, i+2, ret+cnt_a, cnt_a, true);
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
