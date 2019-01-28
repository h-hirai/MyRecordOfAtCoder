fn get_primes(n: usize) -> Vec<usize> {
    let mut primes : Vec<usize> = vec![];
    let mut is_prime : Vec<bool> = vec![true; n+1];
    is_prime[0] = false;
    is_prime[1] = false;

    for i in 2..n+1 {
        if is_prime[i] {
            primes.push(i);
            for j in (i..).take_while(|j| i*j <= n) {
                is_prime[i*j] = false;
            }
        }
    }

    primes
}

use std::collections::BTreeMap;

fn get_prime_factors(n: usize) -> BTreeMap<usize, usize> {
    let mut prime_factors = BTreeMap::new();

    if n < 2 {
        prime_factors.insert(n, 1);
        return prime_factors;
    }

    let mut m = n;

    for f in (2..).take_while(|a| a*a <= n) {
        let mut i = 0;
        while m % f == 0 {
            i = i+1;
            m = m / f;
        }
        if i > 0 {
            prime_factors.insert(f, i);
        }
    }

    if m > 1 {
        prime_factors.insert(m, 1);
    }

    prime_factors
}

use std::collections::BTreeSet;

fn get_factors(n: usize) -> BTreeSet<usize> {
    let mut factors = BTreeSet::new();

    for i in (1..).take_while(|i| i*i <= n) {
        if n%i == 0 {
            factors.insert(i);
            factors.insert(n/i);
        }
    }

    factors
}

fn main() {
    for p in get_primes(50) {
        println!("{}", p);
    }

    for (p, k) in get_prime_factors(138) {
        println!("{}^{}", p, k);
    }

    for f in get_factors(146) {
        println!("{}", f);
    }
}
