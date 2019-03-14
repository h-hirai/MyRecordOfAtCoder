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

fn dist(n: usize, i: usize, accs_l: &Vec<usize>, accs_r: &Vec<usize>) -> usize {
    accs_l[i] - accs_l[i-1] +
        accs_l[(n+i  )/2] - accs_l[i  ] +
        accs_l[(n+i-1)/2] - accs_l[i-1] +
        accs_r[(n-i+1)/2] - accs_r[0  ] +
        accs_r[(n-i  )/2] - accs_r[0  ]
}

fn solv(n: usize, accs_l: &Vec<usize>, accs_r: &Vec<usize>) -> usize {
    let ans_l = (1..n+1).map(|i| dist(n, i, &accs_l, &accs_r)).max().unwrap();
    let ans_r = (1..n+1).map(|i| dist(n, i, &accs_r, &accs_l)).max().unwrap();
    std::cmp::max(ans_l, ans_r)
}

fn accum(n: usize, xs: &Vec<usize>) -> Vec<usize> {
    let mut accs = Vec::with_capacity(n+1);
    let mut sum = 0;
    accs.push(sum);
    for &x in xs {
        sum += x;
        accs.push(sum);
    }
    accs
}

fn main() {
    input! {
        l: usize,
        n: usize,
        xs: [usize; n],
    }

    let accs_l = accum(n, &xs);
    let accs_r = accum(n, &xs.iter().rev().map(|x| l-x).collect());

    println!("{}", solv(n, &accs_l, &accs_r));
}
