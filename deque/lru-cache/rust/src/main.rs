use std::collections::VecDeque;

const CACHE_CAPACITY: usize = 5;

fn print_cache(cache: &VecDeque<i32>) {
    for elem in cache {
        print!("{}", elem);
    }
    println!();
}

fn lru_cache_write(cache: &mut VecDeque<i32>, val: i32) {
    if cache.len() >= CACHE_CAPACITY {
        cache.pop_front();
    }

    cache.push_back(val);
    print_cache(cache);
}

fn lru_cache_read(cache: &mut VecDeque<i32>, val: &mut i32) -> bool {
    let mut ret = true;

    match cache.pop_back() {
        Some(val) => {
            println!("Read {}", val);
        }
        None => {
            println!("Cache is empty");
            ret = false;
        }
    }
    print_cache(cache);
    ret
}

fn main() {
    let mut cache: VecDeque<i32> = VecDeque::with_capacity(CACHE_CAPACITY);

    for i in 0..10 {
        lru_cache_write(&mut cache, i);
    }

    for j in 0..10 {
        let mut val: i32 = 0;
        lru_cache_read(&mut cache, &mut val);
    }
}
