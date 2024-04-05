use std::mem;

fn max_bitwise(a: i32, b: i32) -> i32
{
    let mut _a = a as i64;
    let mut _b = b as i64;

    _a -= _b;
    _a &= (!_a) >> (mem::size_of::<i64>() * 8 - 1);
    return (_a + _b) as i32;
} 

fn main() {
    println!("max(-1, -2) = {}", max_bitwise(-1, -2));
    println!("max(-2, -1) = {}", max_bitwise(-2, -1));
    println!("max(5, 2) = {}", max_bitwise(5, 2));
    println!("max(2, 5) = {}", max_bitwise(2, 5));
    println!("max(5, 0) = {}", max_bitwise(5, 0));
    println!("max(0, 5) = {}", max_bitwise(0, 5));
    println!("max(-5, 0) = {}", max_bitwise(-5, 0));
    println!("max(0, -5) = {}", max_bitwise(0, -5));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_max() {
        assert_eq!(max_bitwise(-1, -2), -1);
        assert_eq!(max_bitwise(-2, -1), -1);
        assert_eq!(max_bitwise(5, 2), 5);
        assert_eq!(max_bitwise(2, 5), 5);
        assert_eq!(max_bitwise(5, 0), 5);
        assert_eq!(max_bitwise(0, 5), 5);
        assert_eq!(max_bitwise(-5, 0), 0);
        assert_eq!(max_bitwise(0, -5), 0);
    }
}
