#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long N, C;

  std::cin >> N;
  std::cin >> C;

  std::vector<long> X(N);
  std::vector<long> V(N);

  std::vector<long> sum_cw(N);
  std::vector<long> max_hist_cw(N);
  long max_cw=0;
  {
    long sum = 0;

    for (long i=0; i<N; i++) {
      std::cin >> X[i];
      std::cin >> V[i];

      if (i==0) max_hist_cw[0] = 0;

      sum += V[i];
      sum_cw[i] = sum - X[i];

      if (sum - X[i] > max_cw) max_cw = sum - X[i];
      if (i+1 < N) max_hist_cw[i+1] = max_cw;
    }
  }

  std::vector<long> max_hist_ccw(N);
  long max_ccw=0;
  long max_ccw_cw=0;
  {
    long sum = 0;

    for (long i=0; i<N; i++) {
      long x = C - X[N-1-i];
      long v = V[N-1-i];

      if (i==0) max_hist_ccw[0] = 0;

      sum += v;

      if (sum - x > max_ccw) max_ccw = sum - x;
      if (i+1 < N) max_hist_ccw[i+1] = max_ccw;

      if (max_ccw - x + max_hist_cw[N-1-i] > max_ccw_cw)
        max_ccw_cw = max_ccw - x + max_hist_cw[N-1-i];
    }
  }

  long max_cw_ccw=0;
  for (long i=0; i<N; i++) {
    if (sum_cw[i] - X[i] + max_hist_ccw[N-1-i] > max_cw_ccw)
      max_cw_ccw = sum_cw[i] - X[i] + max_hist_ccw[N-1-i];
  }

  std::cout << std::max({max_cw, max_ccw, max_cw_ccw, max_ccw_cw})
            << std::endl;

  return 0;
}
