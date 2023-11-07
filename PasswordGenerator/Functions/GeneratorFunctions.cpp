#include "GeneratorFunctions.h"
#include "../UIEnhancements/UIColours.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <windows.h>

std::string GenerateWords(int word_amount, const bool caps, const bool number) {
    const std::string filePath = "words.txt";
    
    std::ifstream file(filePath);
    std::vector<std::string> words;
    std::string word;
    
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return "";
    }
    
    while (file >> word) {
        if (caps && !word.empty()) {
            word[0] = toupper(word[0]); 
        }
        words.push_back(word);
    }
    
    file.close();
    
    if (words.empty()) {
        std::cerr << "The file is empty." << std::endl;
        return "";
    }
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::string result;
    int randomNumberPosition = number ? std::rand() % word_amount : -1;

    for (int i = 0; i < word_amount; ++i) {
        if (i > 0 && i != randomNumberPosition) {
            result += "-";
        }
        if (i == randomNumberPosition) {
            result += std::to_string(std::rand() % 10); // Ensure number is 0-9
        } else {
            result += words[std::rand() % words.size()];
        }
    }

    return result;
}

std::string GenerateRandomPassword(const int length, const bool allowSymbols) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const std::string symbols = "!\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~";
    const std::string allowedChars = allowSymbols ? chars + symbols : chars;
    
    // Create a random device and seed it to the random number generator.
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, allowedChars.size() - 1);
    
    std::string password;

    for (int i = 0; i < length; ++i) {
        char nextChar = allowedChars[distribution(generator)];
        password += nextChar;
        
        // Check if the character is a symbol and print in red if it is
        if (allowSymbols && symbols.find(nextChar) != std::string::npos) {
            AddColourV2(FOREGROUND_RED, std::string(1, nextChar)); // print symbols in red
        } else {
            AddColourV2(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, std::string(1, nextChar)); // print other characters normally
        }
    }

    std::cout << std::endl; // end the line after printing the password
    
    return password;
}
