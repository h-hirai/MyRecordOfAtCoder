#include <iostream>
#include <vector>

using SpaceMap = std::vector<std::vector<size_t>>;

size_t
right_down(size_t N, size_t M,
           SpaceMap const& right,
           SpaceMap const& down) {
  size_t res = 0;

  for (size_t i=0; i<N; i++) {
    std::vector<size_t> memo(M, 0);
    for (ssize_t j=M-1; j>=0; j--) {
      if (right[i][j] > 0) {
        memo[j] = memo[j+1] + down[i][j+1];
        res += memo[j];
      }
    }
  }

  return res;
}

size_t
down_left(size_t N, size_t M,
          SpaceMap const& down,
          SpaceMap const& left) {
  size_t res = 0;

  for (size_t j=0; j<M; j++) {
    std::vector<size_t> memo(N, 0);
    for (ssize_t i=N-1; i>=0; i--) {
      if (down[i][j] > 0) {
        memo[i] = memo[i+1] + left[i+1][j];
        res += memo[i];
      }
    }
  }

  return res;
}

size_t
left_up(size_t N, size_t M,
        SpaceMap const& left,
        SpaceMap const& up) {
  size_t res = 0;

  for (size_t i=0; i<N; i++) {
    std::vector<size_t> memo(M, 0);
    for (size_t j=0; j<M; j++) {
      if (left[i][j] > 0) {
        memo[j] = memo[j-1] + up[i][j-1];
        res += memo[j];
      }
    }
  }

  return res;
}

size_t
up_right(size_t N, size_t M,
         SpaceMap const& up,
         SpaceMap const& right) {
  size_t res = 0;

  for (size_t j=0; j<M; j++) {
    std::vector<size_t> memo(N, 0);
    for (size_t i=0; i<N; i++) {
      if (up[i][j] > 0) {
        memo[i] = memo[i-1] + right[i-1][j];
        res += memo[i];
      }
    }
  }

  return res;
}

int main() {
  size_t N, M;
  std::cin >> N;
  std::cin >> M;

  std::vector<std::vector<bool>>
    grids(N, std::vector<bool>(M, false));

  for (size_t i=0; i<N; i++) {
    for (size_t j=0; j<M; j++) {
      char c;
      std::cin >> c;
      grids[i][j] = c == '#';
    }
  }

  SpaceMap left_spaces(N, std::vector<size_t>(M, 0));
  SpaceMap right_spaces(N, std::vector<size_t>(M, 0));
  SpaceMap up_spaces(N, std::vector<size_t>(M, 0));
  SpaceMap down_spaces(N, std::vector<size_t>(M, 0));

  for (size_t i=0; i<N; i++) {
    for (size_t j=0; j<M; j++) {
      if (j==0)
        left_spaces[i][j] = 0;
      else if (grids[i][j] || grids[i][j-1])
        left_spaces[i][j] = 0;
      else
        left_spaces[i][j] = left_spaces[i][j-1] + 1;
    }
  }

  for (size_t i=0; i<N; i++) {
    for (ssize_t j=M-1; j>=0; j--) {
      if (j==M-1)
        right_spaces[i][j] = 0;
      else if (grids[i][j] || grids[i][j+1])
        right_spaces[i][j] = 0;
      else
        right_spaces[i][j] = right_spaces[i][j+1] + 1;
    }
  }

  for (size_t j=0; j<M; j++) {
    for (size_t i=0; i<N; i++) {
      if (i==0)
        up_spaces[i][j] = 0;
      else if (grids[i][j] || grids[i-1][j])
        up_spaces[i][j] = 0;
      else
        up_spaces[i][j] = up_spaces[i-1][j] + 1;
    }
  }

  for (size_t j=0; j<M; j++) {
    for (ssize_t i=N-1; i>=0; i--) {
      if (i==N-1)
        down_spaces[i][j] = 0;
      else if (grids[i][j] || grids[i+1][j])
        down_spaces[i][j] = 0;
      else
        down_spaces[i][j] = down_spaces[i+1][j] + 1;
    }
  }

  size_t ans = 0;

  ans += right_down(N, M, right_spaces, down_spaces);
  ans += down_left(N, M, down_spaces, left_spaces);
  ans += left_up(N, M, left_spaces, up_spaces);
  ans += up_right(N, M, up_spaces, right_spaces);

  std::cout << ans << std::endl;

  return 0;
}
