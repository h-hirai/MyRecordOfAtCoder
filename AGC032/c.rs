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

struct UnionFind {
    par: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind {
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

fn solv(nodes: Vec<Vec<usize>>, m: usize) -> bool {
    let mut uf = UnionFind::new(m);
    let mut deg4nodes = Vec::new();
    let mut deg6nodes = 0;

    for i in 0..nodes.len() {
        let ref n = nodes[i];

        if n.len() % 2 == 1 {
            return false;
        } else if n.len() >= 6 {
            deg6nodes += 1;
        } else if n.len() == 4 {
            deg4nodes.push(i);
        } else {
            uf.unite(n[0], n[1]);
        }
    }

    if deg6nodes > 0 { return true; }
    if deg4nodes.len() > 2 { return true; }
    if deg4nodes.len() < 2 { return false; }

    let n = deg4nodes[0];

    return
        uf.same(nodes[n][0], nodes[n][1]) ||
        uf.same(nodes[n][0], nodes[n][2]) ||
        uf.same(nodes[n][0], nodes[n][3]) ||
        uf.same(nodes[n][1], nodes[n][2]) ||
        uf.same(nodes[n][1], nodes[n][3]) ||
        uf.same(nodes[n][2], nodes[n][3]);
}

fn main() {
    input! {
        n: usize,
        m: usize,
        edges: [(usize1, usize1); m],
    }

    let mut nodes = vec![vec![]; n];

    for i in 0..m {
        let (a, b) = edges[i];
        nodes[a].push(i);
        nodes[b].push(i);
    }

    if solv(nodes, m) {
        println!("Yes");
    } else {
        println!("No");
    }
}
