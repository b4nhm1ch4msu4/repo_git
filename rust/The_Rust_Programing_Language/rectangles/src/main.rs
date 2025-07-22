// fn main() {
//     // let width1 = 30;
//     // let height1 = 50;
//     // let rectangle1 = (30,50);
//     let scale = 2;
//     let rectangle2 = Rectangle{
//         width: dbg!(40 * scale),
//         height: 60,
//     };
//     // dbg!(rectangle2);
//     println!("the area of rectangle is {}", rectangle2.area());
//     // println!(
//     //     "the area of the {rectangle2:?} is {} square pixels.",
//     //     // area(width1, height1)
//     //     // area(rectangle1)
//     //     area(&rectangle2)
//     // );
// }

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    let square1 = Rectangle::square(30);
    println!("Square area: {}", square1.area())
}
//
// fn area(width: u32, height: u32) -> u32 {
//     width * height
// }

// fn area(dimemsions: (u32,u32)) ->u32{
//     dimemsions.0 * dimemsions.1
// }

// fn area (rect: &Rectangle) ->u32{
//     rect.width * rect.height
// }
#[derive(Debug)]
struct Rectangle{
    height: u32,
    width: u32,
}

impl Rectangle {
    fn square(size: u32) ->Self{
        Self {
            width: size,
            height: size,
        }
    }
    fn area(&self) ->u32{
        self.height * self.width
    }

    fn can_hold(&self, other: &Rectangle) ->bool{
        if(self.height >= other.height && self.width >= other.width){
            true
        }else{
            false
        }
    }
}
