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

fn main() {
    let mut uf = UnionFind::new(10);
    uf.unite(0, 2);
    uf.unite(0, 4);
    uf.unite(0, 6);
    uf.unite(0, 8);

    for i in 0..10 {
        println!("{}", uf.root(i));
    }
}
