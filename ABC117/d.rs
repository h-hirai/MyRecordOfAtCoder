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

fn main() {
    input! {
        n: usize,
        k: usize,
        an: [usize; n],
    }

    let k_width: usize = if k > 0 {
        ((k as f32).log2() as usize) + 1
    } else {
        0
    };


    let bit_counter = {
        let mut bit_counter: Vec<usize> = vec![0; k_width];

        for mut a in an.iter().cloned() {
            for i in 0..k_width {
                if a % 2 == 1 {
                    bit_counter[i] += 1;
                }
                a /= 2;
            }
        }

        bit_counter
    };

    let x = (0..k_width).rev().fold(0, |acc, i| {
        let d = 1<<i;
        if k & d > 0 && n > bit_counter[i] * 2 {
            if acc + d > k {
                acc
            } else {
                acc + d
            }
        } else {
            acc
        }
    });

    let ans: usize = an.iter().map(|a| x ^ *a).sum();

    println!("{}", ans);
}
