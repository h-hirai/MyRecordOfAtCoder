#include <iostream>
#include <vector>
#include <algorithm>

int solv(std::vector<int> const& A,
         std::vector<int> const& B) {
  std::vector<int> diff(A.size());
  long long int det = 0;

  for (size_t i=0; i<A.size(); i++) {
    diff[i] = A[i] - B[i];
    det += diff[i];
  }

  if (det < 0) return -1;

  std::sort(diff.begin(), diff.end());

  int ans = 0;
  long long int sum = 0;

  for (size_t i=0; diff[i] < 0; i++) {
    ans++;
    sum += diff[i];
    // std::cerr << ans << ':' << diff[i] << ',' << sum << std::endl;
  }

  for (size_t i=diff.size()-1; sum < 0; i--) {
    ans++;
    sum += diff[i];
    // std::cerr << ans << ':' << diff[i] << ',' << sum << std::endl;
  }

  return ans;
}

int main() {
  size_t N;

  std::cin >> N;

  std::vector<int> A(N);

  for (size_t i=0; i<N; i++) std::cin >> A[i];

  std::vector<int> B(N);

  for (size_t i=0; i<N; i++) std::cin >> B[i];

  std::cout << solv(A, B) << std::endl;

  return 0;
}
