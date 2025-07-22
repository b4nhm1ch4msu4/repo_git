// fn main() {
//     println!("Hello, world!");
//
//     let mut outer_loop_count = 10;
//     'outer: loop {
//         println!("outer : {outer_loop_count}");
//         let mut inner_loop_count = 5;
//         loop {
//             if inner_loop_count == 2 {
//                 break;
//             }
//             if outer_loop_count == 5 {
//                 break 'outer;
//             }
//             println!("inner: {inner_loop_count}");
//             inner_loop_count-= 1;
//         }
//         outer_loop_count -= 1;
//     }
//
//     println!("end of nested loop");
// }
//
//
// fn main() {
//     let mut iter = 3;
//     while iter > 0 {
//         println!("iter: {iter}");
//         iter -= 1;
//     }
// }
//
//
// fn main() {
//     let arr = [1,2,3,4,5,6];
//     for item in arr{
//         println!("{item}")
//     }
//     println!("hello world")
// }
//
//
fn main() {
    for idex in (0..5).rev() {
        println!("index: {idex}");
    }
}
