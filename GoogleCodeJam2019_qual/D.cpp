#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

// std::ofstream ofs;

std::string gen_query(std::vector<size_t> const& sections) {
  std::string ret;

  for (auto n: sections) {
    if (n == 32) {
      ret.append("00000000000000001111111111111111");
    } else if (n == 16) {
      ret.append("0000000011111111");
    } else if (n == 8) {
      ret.append("00001111");
    } else if (n == 4) {
      ret.append("0011");
    } else if (n == 2) {
      ret.append("01");
    } else if (n == 1) {
      ret.append("0");
    }
  }

  return ret;
}

std::vector<size_t>
gen_sections(size_t N, size_t const max) {
  std::vector<size_t> ret;

  while (N>0) {
    if (std::min(N, max) >= 32) {
      ret.push_back(32);
      N -= 32;
    } else if (std::min(N, max) >= 16) {
      ret.push_back(16);
      N -= 16;
    } else if (std::min(N, max) >= 8) {
      ret.push_back(8);
      N -= 8;
    } else if (std::min(N, max) >= 4) {
      ret.push_back(4);
      N -= 4;
    } else if (std::min(N, max) >= 2) {
      ret.push_back(2);
      N -= 2;
    } else if (std::min(N, max) >= 1) {
      ret.push_back(1);
      N -= 1;
    }
  }

  return ret;
}

std::pair<size_t, size_t>
count(std::string const& S, size_t i, size_t sec, size_t brk) {
  // ofs << "count: i=" << i << std::endl;
  // ofs << "count: S.size()=" << S.size() << std::endl;

  if (sec == brk) return std::make_pair(sec/2, sec/2);

  size_t j = 0;
  for (; j<sec/2 && i+j<S.size() && S[i+j]=='0'; j++);
  auto a = sec / 2 - j;

  size_t k = 0;
  for (; j+k<sec-brk && i+j+k<S.size() && S[i+j+k]=='1'; k++);
  return std::make_pair(a, sec / 2 - k);
}

void
update(std::string const& S,
       std::vector<size_t>& sections,
       std::vector<size_t>& brokens) {
  std::vector<size_t> ret_sec;
  std::vector<size_t> ret_bro;
  size_t j=0;

  for (size_t i=0; i<sections.size(); i++) {
    if (sections[i] > 1) {
      size_t a, b;
      std::tie(a, b) = count(S, j, sections[i], brokens[i]);
      ret_sec.push_back(sections[i]/2);
      ret_sec.push_back(sections[i]/2);
      ret_bro.push_back(a);
      ret_bro.push_back(b);
      j += sections[i]-a-b;
    } else {
      ret_sec.push_back(1);
      if (j == S.size())
        ret_bro.push_back(1);
      else
        ret_bro.push_back(brokens[i]);
      j+=1;
    }
  }

  std::swap(sections, ret_sec);
  std::swap(brokens, ret_bro);
}

void testcase() {
  size_t N, B, F;
  std::cin >> N >> B >> F;

  // ofs << N << ' ' << B << ' ' << F << std::endl;

  auto sections = gen_sections(N, 32);
  std::vector<size_t> brokens(sections.size(), 0);

  for (size_t i=0; i<F; i++) {
    auto Q = gen_query(sections);
    // ofs << "Q: " << Q << std::endl;
    std::cout << Q << std::endl;
    std::string reply;
    std::cin >> reply;
    // ofs << "R: " << reply << std::endl;
    if (reply == "-1") std::exit(-1);
    update(reply, sections, brokens);
    // for (auto b: brokens) ofs << ' ' << b;
    // ofs << std::endl;
  }

  for (size_t i=0; i<brokens.size() && B > 0; i++) {
    if (brokens[i] == 1) {
      std::cout << ' ' << i;
      // ofs << ' ' << i;
      B--;
    }
  }
  std::cout << std::endl;
  // ofs << std::endl;

  int result;
  std::cin >> result;
  // ofs << result << std::endl;
  if (result == -1) std::exit(-1);
}

int main() {
  // ofs.open("d.log");

  size_t T;
  std::cin >> T;

  // ofs << T << std::endl;

  for (size_t t=1; t<T+1; t++){
    testcase();
  }

  return 0;
}
