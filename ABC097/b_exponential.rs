fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let x: usize = sc.next();

    let mut a = vec![false; x+1];

    a[1] = true;

    for b in 2..x+1 {
        let mut v = b*b;
        while v<=x {
            a[v] = true;
            v = v*b;
        }
    }

    for i in (1..x+1).rev() {
        if a[i] {
            println!("{}", i);
            break;
        }
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
}

fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    buf
}
