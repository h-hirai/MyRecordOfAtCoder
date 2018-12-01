fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let _t : usize = sc.next();
    let _n : usize = sc.next();
    let _m : usize = sc.next();

    let t : usize = 1000;
    let n : usize = 10;
    let m : usize = 30000;

    let mut start_turn : Vec<usize> = Vec::with_capacity(m);
    let mut end_turn : Vec<usize> = Vec::with_capacity(m);
    let mut pay : Vec<usize> = Vec::with_capacity(m);
    let mut requirement : Vec<Vec<usize>> = Vec::with_capacity(m);

    for _i in 0..m {
        start_turn.push(sc.next());
        end_turn.push(sc.next());
        pay.push(sc.next());
        let mut reqs = Vec::with_capacity(n);
        for _j in 0..n {
            reqs.push(sc.next());
        }
        requirement.push(reqs);
    }

    for _i in 0..t {
        println!("{}", 3);
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
