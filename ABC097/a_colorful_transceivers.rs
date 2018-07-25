fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let a: i8 = sc.next();
    let b: i8 = sc.next();
    let c: i8 = sc.next();
    let d: i8 = sc.next();

    if (a-c).abs() <= d {
        println!("Yes");
    } else if (a-b).abs() <= d && (b-c).abs() <= d {
        println!("Yes");
    } else {
        println!("No");
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
