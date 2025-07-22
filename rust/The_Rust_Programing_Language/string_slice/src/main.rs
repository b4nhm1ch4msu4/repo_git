fn main() {
    let mut s1 = String::from("Hello there");
    let mut another_word = &s1[6..];
    let word = &s1[..5];
    s1.clear();
    // println!("{word} {another_word}");
}
