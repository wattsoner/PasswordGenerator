#include "GeneratorFunctions.h"
#include "../UIEnhancements/UIColours.h"

#include <fstream>
#include <iostream>
#include <random>


auto GenerateWords(const size_t word_amount, const bool caps, const bool number) -> void {
    const std::string filePath = "words.txt";
    
    std::ifstream file(filePath);
    std::vector<std::string> words;
    std::string word;
    
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
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
    }
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::string result;
    const int randomNumberPosition = number ? std::rand() % word_amount : -1;

    for (int i = 0; i < word_amount; ++i) {
        if (i > 0 && i != randomNumberPosition) {
            result += "-";
        }
        if (i == randomNumberPosition) {
            result += std::to_string(std::rand() % 10);
        } else {
            result += words[std::rand() % words.size()];
        }
    }

    std::cout << result << std::endl;
}

auto GenerateRandomPassword(size_t length, const bool allowSymbols) -> void {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const std::string symbols = "!\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~";
    const std::string allowedChars = allowSymbols ? chars + symbols : chars;
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, allowedChars.size() - 1);
    
    std::string password;

    for (int i = 0; i < length; ++i) {
        char nextChar = allowedChars[distribution(generator)];
        password += nextChar;
        
        if (allowSymbols && symbols.find(nextChar) != std::string::npos) {
            AddColourV2(FOREGROUND_RED, std::string(1, nextChar));
        } else {
            AddColourV2(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, std::string(1, nextChar)); 
        }
    }

    std::cout << password << std::endl;
    
}

auto GeneratePIN(size_t length) -> void {
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<> distr(0, 9);
    
    std::string pin;
    for(size_t i = 0; i < length; ++i) {
        pin += std::to_string(distr(eng));
    }

    std::cout << pin << std::endl;
}


