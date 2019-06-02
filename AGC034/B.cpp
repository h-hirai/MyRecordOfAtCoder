#include <iostream>
#include <string>

enum state_t {
  init,
  a,
  ab,
  abc,
  b,
  bc
};

int main() {
  std::string S;

  std::cin >> S;

  state_t stat = init;
  int cnt = 0;

  int ans = 0;

  for (auto c: S) {
    switch (stat) {
    case init:
      cnt = 0;
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "I  ->A:" << cnt << '\n';
        cnt++;
        break;
      default:
        // std::cerr << "I  ->I:" << cnt << '\n';
        break;
      }
      break;
    case a:
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "A  ->A:" << cnt << '\n';
        cnt++;
        break;
      case 'B':
        stat = ab; // std::cerr << "A  ->AB:" << cnt << '\n';
        break;
      case 'C':
        stat = init; // std::cerr << "A  ->I:" << cnt << '\n';
      }
      break;
      break;
    case ab:
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "AB ->A:" << cnt << '\n';
        cnt = 1;
        break;
      case 'B':
        stat = init; // std::cerr << "AB ->I:" << cnt << '\n';
        break;
      case 'C':
        stat = abc; // std::cerr << "AB ->ABC:" << cnt << '\n';
        ans += cnt;
        break;
      }
      break;
    case abc:
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "ABC->A:" << cnt << '\n';
        cnt++;
        break;
      case 'B':
        stat = b; // std::cerr << "ABC->B:" << cnt << '\n';
        break;
      case 'C':
        stat = init; // std::cerr << "ABC->I:" << cnt << '\n';
        break;
      }
      break;
    case b:
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "B  ->A:" << cnt << '\n';
        break;
      case 'B':
        stat = init; // std::cerr << "B  ->I:" << cnt << '\n';
        break;
      case 'C':
        stat = bc; // std::cerr << "B  ->BC:" << cnt << '\n';
        cnt++;
        ans++;
        break;
      }
      break;
    case bc:
      switch (c) {
      case 'A':
        stat = a; // std::cerr << "BC ->A:" << cnt << '\n';
        break;
      case 'B':
        stat = b; // std::cerr << "BC ->B:" << cnt << '\n';
        break;
      case 'C':
        stat = init; // std::cerr << "BC ->I:" << cnt << '\n';
        break;
      }
      break;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
