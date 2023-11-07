#include "GeneratorFunctions.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

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

