static T : usize = 1000;
static N : usize = 10;
static M : usize = 30000;

enum Command {
    Work,
    Training(usize),
    GetOrder(usize),
}

struct GameStatus {
    turn: usize,
    money: usize,
    skills: Vec<usize>,
    orders: Vec<bool>,
}

impl GameStatus {
    fn new() -> GameStatus {
        GameStatus {
            turn: 0,
            money: 1000,
            skills: vec![0; N],
            orders: vec![false; M],
        }
    }
}

fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let _t : usize = sc.next();
    let _n : usize = sc.next();
    let _m : usize = sc.next();

    let mut start_turn : Vec<usize> = Vec::with_capacity(M);
    let mut end_turn : Vec<usize> = Vec::with_capacity(M);
    let mut pay : Vec<usize> = Vec::with_capacity(M);
    let mut requirement : Vec<Vec<usize>> = Vec::with_capacity(M);

    for _i in 0..M {
        start_turn.push(sc.next());
        end_turn.push(sc.next());
        pay.push(sc.next());
        let mut reqs = Vec::with_capacity(N);
        for _j in 0..N {
            reqs.push(sc.next());
        }
        requirement.push(reqs);
    }

    for _i in 0..T {
        println!("{}", 3);
    }
}

// 以下、たなこふ先生からぱくったやつ (´･_･`)

struct Scanner<'a> {
    iter: std::str::SplitWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    fn new(s: &str) -> Scanner {
        Scanner {
            iter: s.split_whitespace(),
        }
    }

    fn next<T>(&mut self) -> T
        where T: std::str::FromStr,
              <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        let s = self.iter.next().unwrap();
        s.parse().unwrap()
    }
}

fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    buf
}
