fn main() {
    let user1: User = User {
        name: String::from("Tien"),
        active: true,
        email: String::from("tienpham@gmail.com"),
        sign_in_cont: 10,
    };

    let user2 = build_user(String::from("tienpham@linux.com"), String::from("pham"));

    let user3 = User {
        name: user1.name,
        active: user1.active,
        email: String::from("another@dotcom"),
        sign_in_cont: user1.sign_in_cont,
    };

    // let name  = user2.name;
    println!("{}", user2.name);

    let black = Color(0, 0, 0);
    let origin = Point(0, 0);

    print!("{}",black.0);
}

// Tuple struct
struct Color(i32, i32, i32);
struct Point(i32, i32);

struct User {
    name: String,
    active: bool,
    email: String,
    sign_in_cont: u32,
}

fn build_user(email: String, name: String) -> User {
    User {
        active: true,
        name,
        email,
        sign_in_cont: 32,
    }
}
