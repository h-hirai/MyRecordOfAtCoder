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

use std::collections::HashSet;
use std::collections::VecDeque;

fn judge(d1: usize, d2: usize, t: usize) -> bool {
    let diff_t = t*t - (t-1)*(t-1);
    d1 < d2 && diff_t < d2-d1
}

fn main() {
    input! {
        n : usize,
        k : usize,
        sushis : [(usize, usize); n],
    }

    let mut ss = sushis;
    ss.sort_by(|a, b| b.1.cmp(&a.1));
    let mut ss: VecDeque<_> = ss.into_iter().collect();

    let mut cnt = 0;
    let mut selected_t = HashSet::with_capacity(k);
    let mut selected_d = VecDeque::with_capacity(k);

    ss.retain(|s| {
        if cnt < k {
            if selected_t.contains(&s.0) {
                true
            } else {
                selected_t.insert(s.0);
                selected_d.push_front(s.1);
                cnt+=1;
                false
            }
        } else {
            true
        }
    });

    let mut ts = cnt;

    ss.retain(|s| {
        if cnt < k {
            selected_d.push_back(s.1);
            cnt+=1;
            false
        } else {
            true
        }
    });

    for (_t, d) in ss {
        if judge(*selected_d.front().unwrap(), d, ts) {
            selected_d.pop_front();
            selected_d.push_back(d);
            ts-=1;
        } else {
            break;
        }
    }

    println!("{}", selected_d.iter().sum::<usize>() + ts*ts);
}
