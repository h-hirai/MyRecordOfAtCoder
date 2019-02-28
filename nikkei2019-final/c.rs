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

fn dist(x: usize, y: usize) -> usize {
    (x as isize - y as isize).abs() as usize
}

fn calc_cost(x: usize, pcs: &Vec<usize>) -> usize {
    let mut ans = 0;

    for i in 0..pcs.len() {
        ans += pcs[i]*dist(x, i);
    }

    ans
}

fn solv_main(lb: usize, ub: usize, lc: usize, uc: usize,
             pcs: &Vec<usize>) -> usize {
    use std::cmp::min;

    if ub-lb < 2 {
        return min(lc, uc);
    }

    let x = lb + (ub+1 - lb)/2;
    let c = calc_cost(x, pcs);

    if lc >= c && c > uc {
        solv_main(x, ub, c, uc, pcs)
    } else if lc < c && c <= uc {
        solv_main(lb, x, lc, c, pcs)
    } else {
        let c0 = solv_main(x, ub, c, uc, pcs);
        let c1 = solv_main(lb, x, lc, c, pcs);
        min(c0, c1)
    }
}

fn solv(pieces: &Vec<usize>) -> usize {
    let lc = calc_cost(0, pieces);
    let uc = calc_cost(pieces.len()-1, pieces);
    solv_main(0, pieces.len()-1, lc, uc, pieces)
}

fn main() {
    input! {
        h: usize,
        w: usize,
        k: usize,
        blanks: [(usize1, usize1); k],
    }

    let (ps_r, ps_c) = {
        let mut ps_r = vec![w; h];
        let mut ps_c = vec![h; w];

        for (r, c) in blanks {
            ps_r[r] -= 1;
            ps_c[c] -= 1;
        }

        (ps_r, ps_c)
    };

    println!("{}", solv(&ps_r) + solv(&ps_c));
}
