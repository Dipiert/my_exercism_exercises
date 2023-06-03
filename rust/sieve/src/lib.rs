pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    let upper_bound = upper_bound as usize;

    let mut sieve = vec![true; upper_bound + 1];
    (sieve[0], sieve[1]) = (false, false);

    for i in 2..=upper_bound {
        if !sieve[i] {
            continue;
        }
        for j in (i+i..=upper_bound).step_by(i) {
            sieve[j] = false;
        }
    }
    sieve
        .into_iter()
        .enumerate()
        .filter(|&(_, is_prime)| is_prime)
        .map(|(index, _)| index as u64)
        .collect()
}
