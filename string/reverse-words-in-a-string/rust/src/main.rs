fn reverse_words_in_a_string(input: String) -> String {
    let mut v: Vec<String> = Vec::new();
    for i in input.split_whitespace() {
        v.push(i.to_string());
    }
    v.reverse();
    v.join(" ")
}

fn main() {
    let output1 = reverse_words_in_a_string("Hello, world!".to_string());
    println!("{}", output1);

    let output2 =
        reverse_words_in_a_string("bashful doc dopey grumpy happy sleepy sneezy".to_string());
    println!("{}", output2);
}
