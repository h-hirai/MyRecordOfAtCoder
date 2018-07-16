fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let n: u64 = sc.next();
    let a: u64 = sc.next();
    let b: u64 = sc.next();
    let k: u64 = sc.next();

    let mut ans = 0;

    for numr in 0..n {
        if k >= a * numr && (k - a * numr) % b == 0 {
            let p = 998244353;
            let numb = (k - a * numr) / b;
            ans += mod_comb(n as i64, numr as i64, p) *
                mod_comb(n as i64, numb as i64, p);
            ans %= p;
        }
    }

    println!("{}", ans);
}

// 以下、蟻本より

fn extgcd(a: i64, b: i64) -> (i64, i64, i64) {
    if b != 0 {
        let (d, y, x) = extgcd(b, a % b);
        (d, x, y - (a / b) * x)
    } else {
        (a, 1, 0)
    }
}

fn mod_inverse(a: i64, m: i64) -> i64 {
    let (_, x, _) = extgcd(a, m);
    (m + x % m) % m
}

fn fact(n: i64, p: i64) -> i64 {
    (2..n+1).fold(1, |res, a|{
        let res = res * a;
        res % p
    })
}

fn mod_fact(n: i64, p: i64) -> (i64, i64) {
    if n == 0 {
        (1, 0)
    } else {
        let (res, e) = mod_fact(n / p, p);
        if (n / p) % 2 != 0 {
            (res * (p - fact(n % p, p)) % p, e)
        } else {
            (res * fact(n % p, p) % p, e)
        }
    }
}

fn mod_comb(n: i64, k: i64, p: i64) -> i64 {
    let (a1, e1) = mod_fact(n, p);
    let (a2, e2) = mod_fact(k, p);
    let (a3, e3) = mod_fact(n - k, p);

    if e1 > e2 + e3 {
        0
    } else {
        a1 * mod_inverse(a2 * a3 % p, p) % p
    }
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

    fn next_vec<T>(&mut self, n: usize) -> Vec<T>
        where T: std::str::FromStr,
              <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        (0..n).map(|_| self.next()).collect()
    }
}

fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    buf
}
