use crate::animals::Chicken;

fn main() {
    let chic = Chicken{
        feets: 2,
        name: "Chicken".to_string(),
    };
    let dog = Dog {
        feets: 4,
        name: "Dog".to_string(),
    };

    println!("Dog sound: {}, Chicken sound: {}", dog.sound(), chic.sound())
}
