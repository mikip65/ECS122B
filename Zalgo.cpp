#include <iostream>
#include <string>
#include "Zalgo.h"
int main() {
    std::string text, pattern;
    std::cout << "Enter the text: ";
    std::cin >> text;
    std::cout << "Enter the pattern: ";
    std::cin >> pattern;
    patternMatching(pattern, text);
}
