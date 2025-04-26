#include <algorithm> // for transform
#include <cctype>    // for tolower
#include <iostream>
#include <string>

int main() {
  std::string input1, input2;

  std::getline(std::cin, input1);
  std::getline(std::cin, input2);

  // Convert to lowercase
  std::transform(input1.begin(), input1.end(), input1.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  std::transform(input2.begin(), input2.end(), input2.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  // Compare the strings
  if (input1 == input2)
    std::cout << "0\n";
  else if (input1 < input2)
    std::cout << "-1\n";
  else
    std::cout << "1\n";

  // Output the result

  return 0;
}
