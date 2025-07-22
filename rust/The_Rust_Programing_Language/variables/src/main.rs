// fn main() {
//     const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
//     let mut x = 5;
//     println!("The value of x is: {x}");
//     x = 6;
//     println!("The value of x is: {x}");
// }
//
// fn main() {
//     let x = 5;
//     let x = x + 1;
//     {
//         let x = x + 1;
//         println!("the value of x is : {x}");
//     }
//     println!("the value of x is : {x}");
// }

fn another_function(){
    println!("this is a function in rust");
}

fn main() {
    // let tup: (u32, i8, char) = (13, 5, 'c');
    // let arr = [1, 2, 3, 4, 5];
    // let arr_2: [u32; 5] = [1, 2, 3, 4, 5];
    // let arr_3: [u32; 10];
    let s1 = String::from("Hello there");
    let s1 = s1.push_str("i am tien");
    let s2 = s1;
    println!("value of s1 is : {s1}");

    // another_function();
}

