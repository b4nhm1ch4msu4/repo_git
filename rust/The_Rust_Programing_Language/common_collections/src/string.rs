fn main() {
    let data = "initial contents";
    let s = data.to_string();
    let mut y = String::from("hello");
    y.push_str(" world");
    println!("{}",y);

    let mut s1 = String::new();
    s1.push_str("hello ");
    let s2 = "world".to_string();
    let s3 = s1 + &s2;
    // let s4 = &s3[0..1];
    for s in s3.chars(){
    println!("{}",s);
    }
}
