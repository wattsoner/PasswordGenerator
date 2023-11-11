#include <iostream>
#include "Functions/GeneratorFunctions.h"
#include "UIEnhancements/UIColours.h"

auto readInput = [](const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return input == "y" || input == "Y";
};

int main() {
    int choiceType;
    
    size_t amount;
    
    bool choiceCaps;
    bool choiceNumb;
    bool choiceSymbols;
    
    std::string input;

    
    AddColour(1, "This is a Password Generator, made by wattie :3");
    std::cout << "Please Choose a Password Generation Type (please enter the number)" << std::endl;
    AddColour(2, "Random Password (1)");
    AddColour(3, "Memorable Password (2)");
    AddColour(4, "Pin Password (3)");
    
    std::cin >> choiceType;
    
    switch (choiceType) {
    case 1:
        choiceSymbols = readInput("Allow Symbols? (y/n): ");
        std::cout << "Enter the amount of characters to generate: ";
        std::cin >> amount;
        GenerateRandomPassword(amount, choiceSymbols);
        break;
    case 2:
        choiceCaps = readInput("Capitalize first letter? (y/n): ");
        choiceNumb = readInput("Include a number? (y/n): ");
        std::cout << "Enter the amount of words to generate: ";
        std::cin >> amount;
        GenerateWords(amount, choiceCaps, choiceNumb);
        break;
    case 3:
        std::cout << "Enter the amount of numbers to generate: ";
        std::cin >> amount;
        GeneratePIN(amount);
        break;
    default:
        std::cout << "This was Invalid, please choose another answer.";
    }
    
    return 0;
}

