#include <iostream>
#include <vector>
#include <string>

int main() {
  int H, W, N;
  std::cin >> H >> W >> N;

  int Sr, Sc;
  std::cin >> Sr >> Sc;

  std::string S, T;
  std::cin >> S >> T;

  int SlackL = Sc - 1;
  int SlackR = W - Sc;
  int SlackU = Sr - 1;
  int SlackD = H - Sr;

  bool judge = true;

  // std::cerr << "SlackL: " << SlackL << ", "
  //           << "SlackR: " << SlackR << ", "
  //           << "SlackU: " << SlackU << ", "
  //           << "SlackD: " << SlackD << std::endl;

  for (int i=0; i<N; i++) {
    if (S[i] == 'L') {
      if (SlackL == 0) {
        judge = false;
        break;
      } else if (T[i] != 'R') {
        SlackL--;
      }
    } else if (T[i] == 'R') {
      SlackL = std::min(W-1, SlackL+1);
    }

    if (S[i] == 'R') {
      if (SlackR == 0) {
        judge = false;
        break;
      } else if (T[i] != 'L') {
        SlackR--;
      }
    } else if (T[i] == 'L') {
      SlackR = std::min(W-1, SlackR+1);
    }

    if (S[i] == 'U') {
      if (SlackU == 0) {
        judge = false;
        break;
      } else if (T[i] != 'D') {
        SlackU--;
      }
    } else if (T[i] == 'D') {
      SlackU = std::min(H-1, SlackU+1);
    }

    if (S[i] == 'D') {
      if (SlackD == 0) {
        judge = false;
        break;
      } else if (T[i] != 'U') {
        SlackD--;
      }
    } else if (T[i] == 'U') {
      SlackD = std::min(H-1, SlackD+1);
    }

    // std::cerr << S[i] << "-" << T[i] << '\t'
    //           << "SlackL: " << SlackL << ", "
    //           << "SlackR: " << SlackR << ", "
    //           << "SlackU: " << SlackU << ", "
    //           << "SlackD: " << SlackD << std::endl;
  }

  std::cout << (judge ? "YES" : "NO") << std::endl;

  return 0;
}
