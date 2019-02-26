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

fn search(x: i64, v: &Vec<i64>) -> (i64, i64) {
    match v.binary_search(&x) {
        Ok(i) => (v[i], v[i]),
        Err(i) => if i == 0 {
            (v[i], v[i])
        } else if i == v.len() {
            (v[i-1], v[i-1])
        } else {
            (v[i-1], v[i])
        }
    }
}

fn solv(x: i64, ss: &Vec<i64>, ts: &Vec<i64>) -> i64 {
    let (s0, s1) = search(x, ss);
    let (t0, t1) = search(x, ts);

    [(s0, t0), (s0, t1), (s1, t0), (s1, t1)].into_iter().map(|&(t, s)| {
        std::cmp::min((x - s).abs(), (x - t).abs()) + (s - t).abs()
    }).min().unwrap()
}

fn main() {
    input! {
        a: usize,
        b: usize,
        q: usize,
        ss: [i64; a],
        ts: [i64; b],
        xs: [i64; q],
    }

    for x in xs {
        println!("{:?}", solv(x, &ss, &ts));
    }
}
