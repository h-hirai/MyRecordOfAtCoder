#include <iostream>
#include <vector>

// http://tsutaj.hatenablog.com/entry/2017/03/29/204841
struct SegmentTree {
private:
  int n;
  std::vector<int> node;

public:
  SegmentTree(std::vector<int> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, -1);

    for(int i=0; i<sz; i++) node[i+n-1] = v[i];
    for(int i=n-2; i>=0; i--) node[i] = std::max(node[2*i+1], node[2*i+2]);
  }

  int getmax(int a, int b, int k=0, int l=0, int r=-1) const {
    if(r < 0) r = n;

    if(r <= a || b <= l) return -1;

    if(a <= l && r <= b) return node[k];

    int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
    int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
    return std::max(vl, vr);
  }
};

bool
is_fair(int K,
        int l, int r,
        SegmentTree const& C,
        SegmentTree const& D) {
  auto maxC = C.getmax(l, r);
  auto maxD = D.getmax(l, r);
  // std::cerr << l << ',' << r << ':' << maxC << '-' << maxD << std::endl;

  return std::abs(maxC-maxD) <= K;
}

long long
testcase(int N, int K,
         std::vector<int> const& C,
         std::vector<int> const& D) {
  SegmentTree segtree_C(C);
  SegmentTree segtree_D(D);

  long long ans = 0;

  for (int l=0; l<N; l++) {
    for (int r=l+1; r<N+1; r++) {
      if (is_fair(K, l, r, segtree_C, segtree_D)) ans++;
    }
  }

  return ans;
}

int main() {
  int T;
  std::cin >> T;

  for (int t=1; t<T+1; t++){
    int N, K;
    std::cin >> N >> K;

    std::vector<int> C(N);
    for (int i=0; i<N; i++)
      std::cin >> C[i];

    std::vector<int> D(N);
    for (int i=0; i<N; i++)
      std::cin >> D[i];

    std::cout << "Case #" << t << ": " << testcase(N, K, C, D) << std::endl;
  }

  return 0;
}
