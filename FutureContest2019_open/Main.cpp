#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

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

union Command {
  Work w;
  Training t;
  GetOrder g;
};

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

  size_t calc_pay(Order const& order) {
    double AddMoney = order.pay;
    AddMoney *= (1 + 9 * static_cast<double>(turn - order.start_turn) /
                 (order.end_turn - order.start_turn));
    int SkillLack = 0;
    for (int j = 0; j < N; j++)
      SkillLack += std::max(0ul, order.requirement[j] - skill_set[j]);

    if (SkillLack == 0) {
      AddMoney *= 10;
    } else {
      AddMoney *= std::pow(0.5, SkillLack);
      AddMoney += 1e-9;
    }
    money += static_cast<ull>(AddMoney);
  }

  void update(std::vector<Order> const & orders,
              Command command) {
    turn++;
    if (command.w.tag == '3') {
      money += 1000;
      return;
    }
    if (command.t.tag == '1') {
      size_t skill = command.t.skill_num;
      size_t next_level = skill_set[skill] + 1;
      if (next_level > 10) return;

      ull cost = 10000*(1<<next_level);
      if (cost > money) return;

      money -= cost;
      experience[skill]++;
      if (experience[skill] < next_level) return;

      experience[skill] = 0;
      skill_set[skill] = next_level;

      return;
    }
    if (command.g.tag == '2') {
      size_t order_num = command.g.order_num;
      if (orders_finished[order_num]) return;

      Order const& order = orders[order_num];
      if (turn < order.start_turn) return;
      if (turn > order.end_turn) return;

      money += calc_pay(order);

      return;
    }
    assert(false);
  }
};

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

  for (size_t i=0; i<T; i++) {
    std::cout << 3 << std::endl;
  }

  return 0;
}
