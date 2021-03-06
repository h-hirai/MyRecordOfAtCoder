// たなこふ先生の input マクロ (´･_･`)
// https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8

#[allow(unused_macros)]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};

    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

const COST: [usize; 10] = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6];

use std::collections::HashMap;

struct Solver {
    cache: HashMap<usize, Option<Vec<usize>>>,
}

impl Solver {
    fn new() -> Solver {
        Solver{cache: HashMap::new()}
    }

    fn solv(&mut self,
            n: usize, digits: &Vec<usize>) -> Option<Vec<usize>> {
        if ! self.cache.contains_key(&n) {
            let ans = if n == 0 {
                Some(Vec::new())
            } else if n == 1 {
                None
            } else {
                digits.iter().filter_map(|&d| {
                    if COST[d] > n {
                        None
                    } else {
                        self.solv(n-COST[d], digits).map(|v| {
                            let mut v = v;
                            v.push(d);
                            v.sort_by(|a, b| b.cmp(a));
                            v
                        })
                    }
                }).max_by(|a, b| {
                    let blen = b.len();
                    if a.len() == blen {
                        a.cmp(&b)
                    } else {
                        a.len().cmp(&blen)
                    }
                })
            };
            self.cache.insert(n, ans);
        }

        self.cache.get(&n).unwrap().clone()
    }
}

fn main() {
    input! {
        n: usize,
        m: usize,
        digits: [usize; m],
    }

    for d in Solver::new().solv(n, &digits).unwrap() {
        print!("{:?}", d);
    }
    print!("\n");
}
