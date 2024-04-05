use std::mem;

fn min_bitwise(a: i32, b: i32) -> i32 {
    let mut _a = a as i64;
    let mut _b = b as i64;

    _a -= _b;
    _a &= _a >> (mem::size_of::<i64>() * 8 - 1);
    return (_a + _b) as i32;
}

fn main() {
    println!("min(-1, -2) = {}", min_bitwise(-1, -2));
    println!("min(-2, -1) = {}", min_bitwise(-2, -1));
    println!("min(5, 2) = {}", min_bitwise(5, 2));
    println!("min(2, 5) = {}", min_bitwise(2, 5));
    println!("min(5, 0) = {}", min_bitwise(5, 0));
    println!("min(0, 5) = {}", min_bitwise(0, 5));
    println!("min(-5, 0) = {}", min_bitwise(-5, 0));
    println!("min(0, -5) = {}", min_bitwise(0, -5));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_min() {
        assert_eq!(min_bitwise(-1, -2), -2);
        assert_eq!(min_bitwise(-2, -1), -2);
        assert_eq!(min_bitwise(5, 2), 2);
        assert_eq!(min_bitwise(2, 5), 2);
        assert_eq!(min_bitwise(5, 0), 0);
        assert_eq!(min_bitwise(0, 5), 0);
        assert_eq!(min_bitwise(-5, 0), -5);
        assert_eq!(min_bitwise(0, -5), -5);
    }
}
