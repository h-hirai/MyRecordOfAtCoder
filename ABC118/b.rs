// たなこふ先生の input マクロ (´･_･`)
// https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8

#[allow(unused_macros)]
macro_rules! input {
    (source = $iter:expr, $($r:tt)*) => {
        // let mut iter = $s.split_whitespace();
        input_inner!{$iter, $($r)*}
    };
    // ($($r:tt)*) => {
    //     let s = {
    //         use std::io::Read;
    //         let mut s = String::new();
    //         std::io::stdin().read_to_string(&mut s).unwrap();
    //         s
    //     };
    //     let mut iter = s.split_whitespace();
    //     input_inner!{iter, $($r)*}
    // };
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

fn main() {
    let s = {
        use std::io::Read;
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    };
    let mut iter = s.split_whitespace();

    input! {
        source = iter,
        n: usize,
        m: usize,
    }

    let mut table = vec![vec![false; n]; m];

    for i in 0..n {
        input! {
            source = iter,
            k: usize,
            a: [usize1; k],
        }

        for a in a {
            table[a][i] = true;
        }
    }

    let ans = table.iter().map(|row| row.iter().fold(true, |a, b| a && *b)).
        filter(|&b| b).count();

    println!("{}", ans);
}
