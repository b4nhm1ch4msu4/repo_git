pub struct Dog {
    feets: u8,
    name: String,
}
impl Sound for Dog {
    fn sound(&self) -> String {
        String::from("Gou Gou !!")
    }
}

pub struct Chicken {
    feets: u8,
    name: String,
}
impl Sound for Chicken {
    fn sound(&self) -> String {
        String::from("Kak Kak!!")
    }
}

pub trait Sound {
    fn sound(&self) -> String;
}
