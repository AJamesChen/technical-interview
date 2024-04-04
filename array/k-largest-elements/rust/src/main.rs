use std::collections::BTreeSet;

fn print_k_largest_elements(v: &[i32], k: usize) {
    println!("Print {} largest element in: ", k);
    println!("{:?}", v);
    let mut k1 = k;
    if k > v.len() {
        println!("k: {} is greater than array size {}", k, v.len());
        println!("Print all elements");
        k1 = v.len();
    }
    
    if k <= 0 || k1 <= 0 {
        println!("Invalid input k: {}", k);
        println!("Nothing to be printed");
        return;
    }

    let btree_set: BTreeSet<i32> = v.iter().cloned().collect();

    for i in btree_set.iter().rev() {
        if k1 <= 0 {
            break;
        }

        print!("{} ", i);
        k1 -= 1;
    }

    println!("\n");
}

fn main() {
    let v = vec![1, 23, 12, 9, 30, 2, 50];
    print_k_largest_elements(&v, 30);
    print_k_largest_elements(&v, 3);
    print_k_largest_elements(&v, 0);
}
