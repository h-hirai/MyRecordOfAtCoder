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
  size_t turn;
  ull money;
  std::vector<size_t> skill_set;
  std::vector<size_t> experience;
  std::vector<bool> orders_finished;

  GameStatus()
    : turn(0)
    , money(1000)
    , skill_set(N, 0)
    , experience(N, 0)
    , orders_finished(M, false) {}

  ull calc_pay(Order const& order) {
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
                             Command const& command) {
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

  void update(std::vector<Order> const & orders,
              Command const& command) {
    turn++;
    if (command.tag == 3) {
      money += 1000;
      return;
    }
    if (command.tag == 1) {
      size_t skill = command.num;
      size_t next_level = skill_set[skill] + 1;
      ull cost = 10000*(1<<next_level);

      money -= cost;
      experience[skill]++;
      if (experience[skill] < next_level) return;

      experience[skill] = 0;
      skill_set[skill] = next_level;

      return;
    }
    if (command.tag == 2) {
      size_t order_num = command.num;
      Order const& order = orders[order_num];

      orders_finished[order_num] = true;
      money += calc_pay(order);

      return;
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

ull simulate(std::vector<Order> const& orders,
             std::vector<Command> const& cmd_seq) {
  GameStatus stat;
  for (auto cmd : cmd_seq) {
    if (stat.is_effectable_command(orders, cmd)) {
      stat.update(orders, cmd);
    }
  }
  return stat.money;
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
  ull max_score = simulate(orders, command_seq);

  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::uniform_int_distribution<size_t> dist(0, T-1);

  auto limit = start + std::chrono::milliseconds(2900);
  size_t count = 0;
  while (std::chrono::system_clock::now() < limit) {
    auto idx = dist(engine);
    auto cmd = random_command(engine);

    if (command_seq[idx] != cmd) {
      std::swap(command_seq[idx], cmd);

      auto score = simulate(orders, command_seq);

      if (score > max_score) {
        max_score = score;
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
