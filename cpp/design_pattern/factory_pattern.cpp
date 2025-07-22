#include <iostream>
#include <string>

class Vehicle {
  std::string type;
};

class Car : public Vehicle {
public:
  Car() { std::cout << "Car constructor" << "\n"; };
  void drive() { std::cout << "Car is running..." << "\n"; }
};

class Bike : public Vehicle {
public:
  Bike() { std::cout << "Bike constructor"; };
  void drive() { std::cout << "Bike is running..." << "\n"; }
};

class Bus : public Vehicle {
public:
  Bus() { std::cout << "Bus constructor"; };
  void drive() { std::cout << "Bus is running..." << "\n"; }
};

class Factory {
public:
  Vehicle *CreateVehicle(std::string &type) {
    if (type == "car") {
      return new Car();
    } else if (type == "bike") {
      return new Bike();
    } else {
      return new Bus();
    }
  }
};

int main(int argc, char *argv[]) {
  Factory *fac = new Factory();
  Vehicle *car = fac->CreateVehicle("car");
  return 0;
}
