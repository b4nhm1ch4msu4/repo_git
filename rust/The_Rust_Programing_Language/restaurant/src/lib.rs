mod front_of_house;
pub fn eat_at_restaurant(){
    // absolute path
    crate::front_of_house::hosting::add_to_waitlist();

    // relative path
    front_of_house::hosting::add_to_waitlist();

}

fn deliver_order() {}

