#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <random>

static constexpr size_t T = 1000;
static constexpr size_t N = 10;
static constexpr size_t M = 30000;

using ull = unsigned long long;

struct Work {
  size_t const tag;
  Work() : tag(3) {}
};

struct Training {
  size_t const tag;
  size_t const skill_num;
  Training(size_t skill_num) : tag(1), skill_num(skill_num) {}
};

struct GetOrder {
  size_t const tag;
  size_t const order_num;
  GetOrder(size_t order_num) : tag(2), order_num(order_num) {}
};

std::ostream& operator<<(std::ostream& os, Work const& w) {
  os << w.tag;
  return os;
}

std::ostream& operator<<(std::ostream& os, Training const& t) {
  os << t.tag << ' ' << (t.skill_num+1);
  return os;
}

std::ostream& operator<<(std::ostream& os, GetOrder const& g) {
  os << g.tag << ' ' << (g.order_num+1);
  return os;
}

union Command {
  Work w;
  Training t;
  GetOrder g;

  Command(Work&& w) : w(w) {};
  Command(Training&& t) : t(t) {};
  Command(GetOrder&& g) : g(g) {};
};

std::ostream& operator<<(std::ostream& os, Command const& cmd) {
  switch (cmd.w.tag) {
  case 3:
    os << cmd.w;
    break;
  case 1:
    os << cmd.t;
    break;
  case 2:
    os << cmd.g;
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
    if (command.w.tag == 3) {
      return true;
    }
    if (command.t.tag == 1) {
      size_t skill = command.t.skill_num;
      size_t next_level = skill_set[skill] + 1;
      if (next_level > 10) return false;

      ull cost = 10000*(1<<next_level);
      if (cost > money) return false;

      return true;
    }
    if (command.g.tag == 2) {
      size_t order_num = command.g.order_num;
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
    if (command.w.tag == 3) {
      money += 1000;
      return;
    }
    if (command.t.tag == 1) {
      size_t skill = command.t.skill_num;
      size_t next_level = skill_set[skill] + 1;
      ull cost = 10000*(1<<next_level);

      money -= cost;
      experience[skill]++;
      if (experience[skill] < next_level) return;

      experience[skill] = 0;
      skill_set[skill] = next_level;

      return;
    }
    if (command.g.tag == 2) {
      size_t order_num = command.g.order_num;
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
    return Command(Training(dist_t(engine)));
  }
  case 2: {
    std::uniform_int_distribution<size_t> dist_g(0, M-1);
    return Command(GetOrder(dist_g(engine)));
  }
  case 3:
    return Command(Work());
  }

  assert(false);
}

int main() {
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

  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  GameStatus stat;
  std::cerr << stat << std::endl;

  while (stat.turn < T) {
    auto cmd = random_command(engine);
    if (stat.is_effectable_command(orders, cmd)) {
      std::cout << cmd << std::endl;
      stat.update(orders, cmd);
      std::cerr << stat << std::endl;
    }
  }

  return 0;
}
