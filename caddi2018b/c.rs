use std::collections::BTreeMap;

fn get_prime_factors(n: usize) -> BTreeMap<usize, usize> {
    let mut prime_factors = BTreeMap::new();

    if n < 2 {
        prime_factors.insert(n, 1);
        return prime_factors;
    }

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
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let n: usize = sc.next();
    let p: usize = sc.next();

    let mut ans = 1;

    for (f, i) in get_prime_factors(p) {
        for _ in 0..i/n {
            ans = ans * f;
        }
    }

    print!("{}\n", ans);
}

// 以下、たなこふ先生からぱくったやつ (´･_･`)

struct Scanner<'a> {
    iter: std::str::SplitWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    fn new(s: &str) -> Scanner {
        Scanner {
            iter: s.split_whitespace(),
        }
    }

    fn next<T>(&mut self) -> T
        where T: std::str::FromStr,
              <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        let s = self.iter.next().unwrap();
        s.parse().unwrap()
    }
}

fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    buf
}
