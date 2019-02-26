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

struct SelectionGenerator {
    n: usize,
    curr: usize,
    ubound: usize,
}

impl SelectionGenerator {
    fn new(n: usize) -> SelectionGenerator {
        SelectionGenerator{n: n, curr: 0, ubound: 1<<n*2}
    }
}

impl Iterator for SelectionGenerator {
    type Item = Vec<usize>;

    fn next(&mut self) -> Option<Self::Item> {
        let n = self.n;
        let curr = self.curr;

        if curr < self.ubound {
            let mut ret = Vec::with_capacity(n);

            for i in 0..n {
                ret.push(curr >> i*2 & 0x00000003);
            }

            self.curr += 1;

            Some(ret)
        } else {
            None
        }
    }
}

fn calc(targets: [isize; 3], ls: &Vec<isize>, sels: Vec<usize>)
        -> Option<isize> {
    let mut selected: Vec<Vec<isize>> = vec![Vec::new(); 3];

    for (i, &l) in ls.into_iter().enumerate() {
        let sel = sels[i];
        if sel < 3 {
            selected[sel].push(l);
        }
    };

    if selected.iter().any(|sel| sel.is_empty()) {
        return None;
    }

    let ret = targets.into_iter().zip(selected).map(|(tgt, sel)| {
        let sum: isize = sel.iter().sum();
        (tgt - sum).abs() + (sel.len() as isize - 1) * 10
    }).sum();

    Some(ret)
}

fn main() {
    input! {
        n: usize,
        a: isize,
        b: isize,
        c: isize,
        ls: [isize; n],
    }

    let ans = SelectionGenerator::new(n).filter_map(|sels| {
        calc([a, b, c], &ls, sels)
    }).min().unwrap();

    println!("{}", ans);
}
