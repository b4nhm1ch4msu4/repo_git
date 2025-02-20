#include <chrono> // for std::chrono
#include <iostream>
#include <random> // for std::mt19937

int main()
{
  // random devices
  std::mt19937 mt{std::random_device{}()};

  // Seed our Mersenne Twister using steady_clock
  /*std::mt19937 mt{static_cast<std::mt19937::result_type>(*/
  /*    std::chrono::steady_clock::now().time_since_epoch().count())};*/

  // Create a reusable random number generator that generates uniform numbers
  // between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count)
  {
    std::cout << die6(mt) << '\t'; // generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  return 0;
}
