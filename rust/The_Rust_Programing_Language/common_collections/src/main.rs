use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);
    scores.entry("Yellow".to_string()).or_insert(20);

    // let first_team = "Blue".to_string();
    // let score = scores.get(&first_team).copied().unwrap_or(0);
    // println!("the first team have score: {}", score);

    for (k,v) in &scores{
        println!("Team {} get score: {}", k, v);
    }

    // println!("{}",scores["Blue"]);
}
