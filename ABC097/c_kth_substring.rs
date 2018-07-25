use std::collections::BTreeSet;

fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let s: String = sc.next();
    let k: usize = sc.next();

    let mut set = BTreeSet::new();

    for i in 0..s.len() {
        for j in 1..6 {
            if i+j<=s.len() {
                set.insert(&s[i..i+j]);
            }
        }
    }

    println!("{}", set.iter().nth(k-1).unwrap());
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
