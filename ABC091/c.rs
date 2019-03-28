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

use std::collections::BTreeSet;

fn main() {
    input! {
        n: usize,
        reds: [(usize, usize); n],
        blues: [(usize, usize); n],
    }

    let reds: BTreeSet<_> = reds.iter().collect();
    let mut blues: BTreeSet<_> = blues.iter().collect();

    let mut ans = 0;

    for &(a, b) in reds.into_iter().rev() {
        let mut tail = blues.split_off(&(a, 0));
        let mut min = (a, 2*n+1);

        for &&(c, d) in &tail {
            if b < d && d < min.1 {
                min = (c, d);
            }
        }

        if tail.remove(&min) {
            ans += 1;
        }
        blues.append(&mut tail);
    }

    println!("{}", ans);
}
