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

use std::collections::BTreeMap;

fn get_prime_factors(n: usize) -> BTreeMap<usize, usize> {
    let mut prime_factors = BTreeMap::new();

    let mut m = n;

    for f in (2..).take_while(|a| a*a <= n) {
        let mut i = 0;
        while m % f == 0 {
            i = i+1;
            m = m / f;
        }
        if i > 0 {
            prime_factors.insert(f, i);
        }
    }

    if m > 1 {
        prime_factors.insert(m, 1);
    }

    prime_factors
}

fn main() {
    input! {
        n: usize,
    }

    let mut count_primes = BTreeMap::<usize, usize>::new();

    for i in 1..n+1 {
        for (p, k) in get_prime_factors(i) {
            *count_primes.entry(p).or_insert(0) += k;
        }
    }

    let mut facts = vec![1];

    let mut fact = |n: usize| -> usize {
        let l = facts.len();
        if n >= l {
            facts.reserve(n + 1 - l);
            for i in l..n+1 {
                let f = facts[i-1];
                facts.push(f*i);
            }
        }
        facts[n]
    };

    let mut comb = |n: usize, r: usize| -> usize {
        if r > n {
            0
        } else {
            fact(n) / (fact(n-r) * fact(r))
        }
    };

    let pf74 = count_primes.iter().filter(|&(_p, k)| *k>=74).count();
    let pf24 = count_primes.iter().filter(|&(_p, k)| *k>=24).count();
    let pf14 = count_primes.iter().filter(|&(_p, k)| *k>=14).count();
    let pf4 = count_primes.iter().filter(|&(_p, k)| *k>=4).count();
    let pf2 = count_primes.iter().filter(|&(_p, k)| *k>=2).count();
    let c25_3 = pf24 * pf2.saturating_sub(1);
    let c15_5 = pf14 * pf4.saturating_sub(1);
    let c5_5 = comb(pf4, 2);
    let c5_5_2 = c5_5 * pf2.saturating_sub(2);

    println!("{}", pf74 + c25_3 + c15_5 + c5_5_2);
}
