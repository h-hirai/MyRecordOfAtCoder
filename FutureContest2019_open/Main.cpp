#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <random>
#include <chrono>

static constexpr size_t T = 1000;
static constexpr size_t N = 10;
static constexpr size_t M = 30000;

using ull = unsigned long long;

struct Command {
  size_t tag;
  size_t num;
};

bool operator!=(Command const& lhs, Command const& rhs) {
  if (lhs.tag != rhs.tag) return true;
  if (lhs.tag != 3) return false;
  return lhs.num != rhs.num;
}

std::ostream& operator<<(std::ostream& os, Command const& cmd) {
  switch (cmd.tag) {
  case 3:
    os << cmd.tag;
    break;
  case 1:
  case 2:
    os << cmd.tag << ' ' << (cmd.num+1);
    break;
  }
  return os;
}

struct Order {
  size_t const start_turn;
  size_t const end_turn;
  ull const pay;
  std::vector<size_t> const requirement;

  Order(size_t start_turn,
        size_t end_turn,
        ull pay,
        std::vector<size_t>&& requirement)
    : start_turn(start_turn)
    , end_turn(end_turn)
    , pay(pay)
    , requirement(requirement) {}
};

std::ostream& operator<<(std::ostream& os, Order const& order) {
  os << order.start_turn
     << ' ' << order.end_turn
     << ' ' << order.pay;

  for (auto r : order.requirement)
    std::cout << ' ' << r;

  os << std::endl;

  return os;
}

struct GameStatus {
  size_t const turn;
  ull const money;
  std::vector<size_t> const skill_set;
  std::vector<size_t> const experience;
  std::vector<bool> const orders_finished;

  GameStatus()
    : turn(1)
    , money(1000)
    , skill_set(N, 0)
    , experience(N, 0)
    , orders_finished(M, false) {}

  GameStatus(size_t const turn,
             ull const money,
             std::vector<size_t> const& skill_set,
             std::vector<size_t> const& experience,
             std::vector<bool> const& orders_finished)
    : turn(turn)
    , money(money)
    , skill_set(skill_set)
    , experience(experience)
    , orders_finished(orders_finished) {}

  ull calc_pay(Order const& order) const {
    double AddMoney = order.pay;
    AddMoney *= (1 + 9 * static_cast<double>(turn - order.start_turn) /
                 (order.end_turn - order.start_turn));
    int SkillLack = 0;
    for (int j = 0; j < N; j++) {
      int lack =
        static_cast<int>(order.requirement[j]) -
        static_cast<int>(skill_set[j]);
      SkillLack += std::max(0, lack);
    }

    if (SkillLack == 0) {
      AddMoney *= 10;
    } else {
      AddMoney *= std::pow(0.5, SkillLack);
      AddMoney += 1e-9;
    }
    return static_cast<ull>(AddMoney);
  }

  bool is_effectable_command(std::vector<Order> const & orders,
                             Command const& command) const {
    if (command.tag == 3) {
      return true;
    }
    if (command.tag == 1) {
      size_t skill = command.num;
      size_t next_level = skill_set[skill] + 1;
      if (next_level > 10) return false;

      ull cost = 10000*(1<<next_level);
      if (cost > money) return false;

      return true;
    }
    if (command.tag == 2) {
      size_t order_num = command.num;
      if (orders_finished[order_num]) return false;

      Order const& order = orders[order_num];
      if (turn < order.start_turn) return false;
      if (turn > order.end_turn) return false;

      return true;
    }
    assert(false);
  }

  GameStatus update(std::vector<Order> const & orders,
                    Command const& command) const {
    if (command.tag == 3) {
      return
        GameStatus{
          turn+1,
          money+1000,
          skill_set,
          experience,
          orders_finished
        };
    }
    if (command.tag == 1) {
      size_t skill = command.num;
      size_t next_level = skill_set[skill] + 1;
      ull cost = 10000*(1<<next_level);

      std::vector<size_t> exp_new;
      std::copy(experience.begin(), experience.end(),
                std::back_inserter(exp_new));
      if (experience[skill]+1 < next_level) {
        exp_new[skill]++;
        return
          GameStatus{
            turn+1,
            money-cost,
            skill_set,
            exp_new,
            orders_finished
          };
      } else {
        exp_new[skill]=0;
        std::vector<size_t> skill_new;
        std::copy(skill_set.begin(), skill_set.end(),
                  std::back_inserter(skill_new));
        skill_new[skill] = next_level;
        return
          GameStatus{
            turn+1,
            money-cost,
            skill_new,
            exp_new,
            orders_finished
          };
      }
    }
    if (command.tag == 2) {
      size_t order_num = command.num;
      Order const& order = orders[order_num];

      std::vector<bool> orders_new;
      std::copy(orders_finished.begin(), orders_finished.end(),
                std::back_inserter(orders_new));
      orders_new[order_num] = true;

      return
        GameStatus{
          turn+1,
          money + calc_pay(order),
          skill_set,
          experience,
          orders_new
        };
    }
    assert(false);
  }
};

std::ostream& operator<<(std::ostream& os, GameStatus const& stat) {
  std::ios::fmtflags flagsSaved = os.flags();

  os << "T:" << std::setw(5) << stat.turn
     << " M:" << std::setw(10) << stat.money << std::endl;

  os << "S:";
  for (size_t i=0; i<N; i++) {
    os << std::setw(3) << stat.skill_set[i];
  }
  os << std::endl;

  os << "E:";
  for (size_t i=0; i<N; i++) {
    os << std::setw(3) << stat.experience[i];
  }
  os << std::endl;

  os.flags(flagsSaved);

  return os;
}

Command random_command(std::default_random_engine& engine) {
  std::uniform_int_distribution<size_t> dist_c(1, 3);
  switch (dist_c(engine)) {
  case 1: {
    std::uniform_int_distribution<size_t> dist_t(0, N-1);
    return Command{1, dist_t(engine)};
  }
  case 2: {
    std::uniform_int_distribution<size_t> dist_g(0, M-1);
    return Command{2, dist_g(engine)};
  }
  case 3:
    return Command{3, 0};
  }

  assert(false);
}

std::vector<GameStatus>
simulate(std::vector<Order> const& orders,
         std::vector<Command> const& cmd_seq,
         std::vector<GameStatus> const& stats,
         size_t idx) {
  std::vector<GameStatus> ret;
  ret.reserve(T);
  std::copy(stats.begin(), std::next(stats.begin(), idx+1),
            std::back_inserter(ret));
  for (size_t i=idx; i<T; i++) {
    auto cmd = cmd_seq[i];
    ret.push_back(ret[i].update(orders, cmd));
  }
  return ret;
}

int main() {
  auto start = std::chrono::system_clock::now();

  size_t _t, _n, _m;
  std::cin >> _t >> _n >> _m;

  std::vector<Order> orders;
  orders.reserve(M);

  for (size_t i=0; i<M; i++) {
    size_t a, b, c;
    std::cin >> a >> b >> c;

    std::vector<size_t> s(N);
    for (size_t j=0; j<N; j++) {
      std::cin >> s[j];
    }

    orders.push_back(Order(a, b, c, std::move(s)));
  }

  std::vector<Command> command_seq(T, Command{3, 0});
  std::vector<GameStatus> stat_seq =
    simulate(orders, command_seq, std::vector<GameStatus>(1, GameStatus()), 0);
  ull max_score = stat_seq[T-1].money;

  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::uniform_int_distribution<size_t> dist(0, T-1);

  auto limit = start + std::chrono::milliseconds(2900);
  size_t count = 0;
  while (std::chrono::system_clock::now() < limit) {
    auto idx = dist(engine);
    auto cmd = random_command(engine);

    if (command_seq[idx] != cmd &&
        stat_seq[idx].is_effectable_command(orders, cmd)) {
      std::swap(command_seq[idx], cmd);
      auto new_stat_seq =
        simulate(orders, command_seq, stat_seq, idx);
      ull score = new_stat_seq[T-1].money;

      if (score > max_score) {
        max_score = score;
        std::swap(stat_seq, new_stat_seq);
      } else {
        std::swap(command_seq[idx], cmd);
      }
      count++;
    }
  }

  for (auto cmd : command_seq) {
    std::cout << cmd << std::endl;
  }
  std::cerr << count << std::endl;

  return 0;
}
