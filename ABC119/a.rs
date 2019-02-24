fn main() {
    let (_y, m, _d): (usize, usize, usize) = {
        use std::io::Read;
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s.truncate(10);
        let mut iter = s.split('/');
        let y = iter.next().unwrap().parse().unwrap();
        let m = iter.next().unwrap().parse().unwrap();
        let d = iter.next().unwrap().parse().unwrap();
        (y, m, d)
    };

    println!("{}", if m <= 4 {"Heisei"} else {"TBD"});
}
