#include <iostream>
#include "Functions/GeneratorFunctions.h"
#include "UIEnhancements/UIColours.h"

int main(int argc, char* argv[]) {
    int AMOUNT, CHOICE_TYPE;
    bool CHOICE_CAPS = false, CHOICE_NUMB = false, CHOICE_SYMBOLS = false;
    std::string INPUT;
    
    AddColour(1, "This is a Password Generator, made by wattie :3");

    std::cout << "Please Choose a Password Generation Type (please enter the number)" << std::endl;
    AddColour(2, "Random Password (1)");
    AddColour(3, "Memorable Password (2)");
    AddColour(4, "Pin Password (3)");
    
    std::cin >> CHOICE_TYPE;

    switch (CHOICE_TYPE) {
        
    case 1:
        std::cout << "Allow Symbols? (y/n): ";
        std::cin >> INPUT;
        if (INPUT == "y" || INPUT == "Y") {
            CHOICE_SYMBOLS = true;
        }

        int AMOUNT;
        std::cout << "Enter the amount of characters to generate: ";
        std::cin >> AMOUNT;

       GenerateRandomPassword(AMOUNT, CHOICE_SYMBOLS);
        
        break;
    case 2:
        {
            std::cout << "Capitalize first letter? (y/n): ";
            std::cin >> INPUT;
            if (INPUT == "y" || INPUT == "Y") {
                CHOICE_CAPS = true;
            }

            std::cout << "Include a number? (y/n): ";
            std::cin >> INPUT;
            if (INPUT == "y" || INPUT == "Y") {
                CHOICE_NUMB = true;
            }

            int AMOUNT;
            std::cout << "Enter the amount of words to generate: ";
            std::cin >> AMOUNT;

            std::string result = GenerateWords(AMOUNT, CHOICE_CAPS, CHOICE_NUMB);
            std::cout << "Generated Words: " << result << std::endl;
        }
        
        break;
    case 3:
        std::cout << "3";
        break;
        
    default: std::cout << "This was Invalid, please choose another answer.";
    }
    
    return 0;
}



