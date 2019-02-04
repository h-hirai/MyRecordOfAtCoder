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

use std::collections::BTreeSet;
use std::collections::VecDeque;

fn topological_sort(n: usize,
                    mut incoming_edges: Vec<BTreeSet<usize>>,
                    outgoing_edges: Vec<BTreeSet<usize>>,) -> Vec<usize> {
    let mut roots = VecDeque::new();

    roots.push_back(0);

    while let Some(par) = incoming_edges[roots[0]].iter().nth(0) {
        roots[0] = *par;
    }

    let mut topological_sort = vec![n; n];
    let mut idx = 0;

    while let Some(node) = roots.pop_front() {
        for e in outgoing_edges[node].iter() {
            incoming_edges[*e].remove(&node);
            if incoming_edges[*e].is_empty() {
                roots.push_back(*e);
            }
        }
        topological_sort[node] = idx;
        idx += 1;
    }

    topological_sort
}


fn main() {
    input! {
        n: usize,
        m: usize,
        edges: [(usize1, usize1); n - 1 + m],
    }

    let (incoming_edges, outgoing_edges) = {
        let mut incoming_edges = vec![BTreeSet::<usize>::new(); n];
        let mut outgoing_edges = vec![BTreeSet::<usize>::new(); n];

        for (a, b) in edges {
            incoming_edges[b].insert(a);
            outgoing_edges[a].insert(b);
        }

        (incoming_edges, outgoing_edges)
    };

    let tsort = topological_sort(n,
                                 incoming_edges.clone(),
                                 outgoing_edges);

    for s in incoming_edges {
        if let Some(p) = s.iter().max_by(|&a, &b| tsort[*a].cmp(&tsort[*b])) {
            println!("{}", p + 1);
        } else {
            println!("0");
        }
    }
}
