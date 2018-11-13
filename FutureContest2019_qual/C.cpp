#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

static size_t const N = 500;
static size_t const M = 29;
static size_t const L = 300;

enum class Floor {N, W, D, T, L, R};

using Point = size_t;

Point up(Point p)    {return p - M;}
Point down(Point p)  {return p + M;}
Point left(Point p)  {return p - 1;}
Point right(Point p) {return p + 1;}

enum class Direction {Up, Down, Left, Right};

Direction turn_left(Direction dir) {
  switch (dir) {
  case Direction::Up:    return Direction::Left;
  case Direction::Left:  return Direction::Down;
  case Direction::Down:  return Direction::Right;
  case Direction::Right: return Direction::Up;
  }
}

Direction turn_right(Direction dir) {
  switch (dir) {
  case Direction::Up:    return Direction::Right;
  case Direction::Right: return Direction::Down;
  case Direction::Down:  return Direction::Left;
  case Direction::Left:  return Direction::Up;
  }
}

using Map = std::vector<Floor>;

Map empty_map() {
  Map map(M*M, Floor::N);
  for (size_t y=0; y<M; y++) {
    for (size_t x=0; x<M; x++) {
      if (y==0 || y==M-1) {
        map[y*M+x] = Floor::W;
      } else {
        if (x==0 || x==M-1) {
          map[y*M+x] = Floor::W;
        }
      }
    }
  }
  return map;
}

void perform_command(Map const& map, char const cmd,
                     Point& pos, Direction& dir,
                     size_t const cnt=1) {
  switch (cmd) {
  case 'S':
    {
      Point new_pos;
      switch (dir) {
      case Direction::Up:    new_pos = up(pos); break;
      case Direction::Down:  new_pos = down(pos); break;
      case Direction::Left:  new_pos = left(pos); break;
      case Direction::Right: new_pos = right(pos); break;
      }
      if (map[new_pos] != Floor::W) pos = new_pos;
    }
    break;
  case 'L':
    if (map[pos] == Floor::R)
      dir = turn_right(dir);
    else
      dir = turn_left(dir);
    break;
  case 'R':
    if (map[pos] == Floor::L)
      dir = turn_left(dir);
    else
      dir = turn_right(dir);
    break;
  }

  if (cnt>1) perform_command(map, cmd, pos, dir, cnt-1);
}

Point simulate(Map const& map, std::string const& commands, std::vector<size_t>& result_path) {
  Point pos(14 * M + 14);
  Direction dir = Direction::Up;

  for (auto const cmd : commands) {
    if (map[pos] == Floor::T) perform_command(map, cmd, pos, dir, 3);
    else if (map[pos] == Floor::D) perform_command(map, cmd, pos, dir, 2);
    else perform_command(map, cmd, pos, dir);

    result_path[pos]++;
  }


  return pos;
}

std::tuple<std::vector<size_t>, std::vector<size_t>>
statistic_simulation(Map const& map, std::vector<std::string> const& commands) {
  std::vector<size_t> result_path(M*M, 0);
  std::vector<size_t> result_goal(M*M, 0);

  for (auto const &cmds : commands) {
    Point p = simulate(map, cmds, result_path);
    result_goal[p] += 1;
  }

  return make_tuple(result_goal, result_path);
}

size_t score(std::vector<size_t> const& statistics) {
  size_t res = 0;
  for (auto const c : statistics) {
    if (c == 1) res += 10;
    else if (c == 2) res += 3;
    else if (c == 3) res += 1;
  }
  return res;
}


std::ostream& operator<<(std::ostream& os, const Floor& fl) {
  switch (fl) {
  case Floor::N: os << '.'; break;
  case Floor::W: os << '#'; break;
  case Floor::D: os << 'D'; break;
  case Floor::T: os << 'T'; break;
  case Floor::L: os << 'L'; break;
  case Floor::R: os << 'R'; break;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
  for (size_t y=0; y<M; y++) {
    for (size_t x=0; x<M; x++) {
      std::cout << map[y*M+x];
    }
    std::cout << '\r' << std::endl;
  }

  return os;
}

std::random_device seed_gen;
std::default_random_engine engine(seed_gen());

Floor random_floor() {
  std::uniform_int_distribution<size_t> dist(0, 5);
  switch (dist(engine)) {
  case 0: return Floor::N; break;
  case 1: return Floor::N; break;
  case 2: return Floor::D; break;
  case 3: return Floor::T; break;
  case 4: return Floor::L; break;
  case 5: return Floor::R; break;
  }
}

static size_t const NumChildren = 80;
Map mutate_and_selection_map(Map const& map, std::vector<std::string> cmds) {
  std::vector<size_t> stats_goal;
  std::vector<size_t> stats_path;
  std::tie(stats_goal, stats_path) = statistic_simulation(map, cmds);
  size_t max_score = score(stats_goal);

  Map res = map;

  for (size_t i=0; i<NumChildren; i++) {
    Point p;
    do {
      auto imax = std::max_element(stats_path.begin(), stats_path.end());
      p = std::distance(stats_path.begin(), imax);
      stats_path[p] = 0;
    } while (map[p] != Floor::N);

    Map child(M*M);
    std::copy(map.begin(), map.end(), child.begin());
    child[p] = random_floor();

    size_t child_score = score(std::get<0>(statistic_simulation(child, cmds)));

    if (child_score > max_score) {
      max_score = child_score;
      res = std::move(child);
    }
  }

  return res;
}

int main() {
  size_t _N, _M, _L;
  std::cin >> _N >> _M >> _L;

  std::vector<std::string> S(N);

  for (size_t i=0; i<N; i++)
    std::cin >> S[i];

  constexpr size_t Generation = 20;
  Map ans = empty_map();
  ans = mutate_and_selection_map(ans, S);
  for (size_t i=0; i<Generation; i++) {
    ans = std::move(mutate_and_selection_map(ans, S));
    // std::cout << ans;
    // std::cout << score(std::get<0>(statistic_simulation(ans, S))) << std::endl;
  }

  std::cout << ans;
  // std::cout << score(std::get<0>(statistic_simulation(ans, S))) << std::endl;

  return 0;
}
