#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin >> ch; // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    std::cin >> ch; // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
