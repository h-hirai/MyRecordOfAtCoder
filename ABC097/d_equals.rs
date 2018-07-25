struct UnionFindTree {
    par: Vec<usize>,
}

impl UnionFindTree {
    fn new(n: usize) -> UnionFindTree {
        UnionFindTree {
            par: (0..n).collect(),
        }
    }

    fn root(&mut self, x: usize) -> usize {
        let p = self.par[x];
        if p == x {
            x
        } else {
            let r = self.root(p);
            self.par[x] = r;
            r
        }
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        self.root(x) == self.root(y)
    }

    fn unite(&mut self, x: usize, y: usize) {
        let rootx = self.root(x);
        let rooty = self.root(y);
        if rootx == rooty {
            ;
        } else {
            self.par[rootx] = rooty;
        }
    }
}

fn main() {
    let s = read_string();
    let mut sc = Scanner::new(&s);

    let n: usize = sc.next();
    let m: usize = sc.next();

    let mut ps = Vec::with_capacity(n);

    for _i in 0..n {
        let p: usize = sc.next();
        ps.push(p-1);
    }

    let mut uf = UnionFindTree::new(n);

    for _i in 0..m {
        let x: usize = sc.next();
        let y: usize = sc.next();
        uf.unite(x-1, y-1);
    }

    let mut ans = 0;

    for i in 0..n {
        if uf.same(ps[i], i) {
            ans += 1;
        }
    }

    println!("{}", ans);
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
