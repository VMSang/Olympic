#include <iostream>
#include <format>

int main() {
    int a = 10;
    double b = 3.14;
    std::string s = "world";

    // Use std::format for string formatting
    std::string result = std::format("Hello, {}! The value of a is {} and b is {:.2f}.", s, a, b);
    
    std::cout << result << "\n";
    return 0;
}
