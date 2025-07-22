
// fn main() {
//     let mut v: Vec<i32> = Vec::new();
//     v.push(5);
//     v.push(6);
//     v.push(7);
//     v.push(8);
//     // let x = vec![1, 2, 3];
//     // for idx in 0..x.len() {
//     //     println!("value of {idx} is : {}",x[idx])
//     // }
//     // println!("value of 2 is : {}",x[2]);
//     let leng = v.len();
//     for idx in 0..leng {
//         // let value = v.get(idx);
//         // if let Some(i) = value {
//         //     println!("the {idx} item has value: {}", i);
//         // }
//         let value: Option<&i32> = v.get(idx);
//         match value{
//             Some(value) => println!("the value is {value}"),
//             None => println!("No value")
//         }
//     }
//
//     // let does_not_exist = v.get(100);
//     let does_not_exist = &v[100];
// }

fn main() {
    let mut v = vec![1,2,3,4,5];
    for item in &mut v{
        *item += 1;
    }

    print!("{}",v[0]);
}
