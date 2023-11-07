#include "FileHelper.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::string GenerateWords(int word_amount, const bool caps, bool number) {
    const std::string filePath = "words.txt"; // Removed the reference '&' for the string literal
    
    std::ifstream file(filePath);
    std::vector<std::string> words;
    std::string word;
    
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return "";
    }
    
    // Read words from file into vector
    while (file >> word) {
        if (caps && !word.empty()) {
            word[0] = toupper(word[0]); // Capitalize the first letter if 'caps' is true
        }
        words.push_back(word);
    }
    
    file.close(); // Always close the file when you're done with it
    
    if (words.size() < word_amount) {
        std::cerr << "Not enough words in the file." << std::endl;
        return "";
    }
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::string result;
    int randomNumberPosition = number ? std::rand() % word_amount : -1; // Determine a random position for the number if 'number' is true
    
    for (int i = 0; i < word_amount; ++i) {
        if (i > 0) {
            result += "-";
        }
        if (i == randomNumberPosition) {
            result += std::to_string(std::rand() % 9 + 1); // Insert a random number between 1 and 9
        }
        result += words[std::rand() % words.size()];
    }
    
    return result;
}
