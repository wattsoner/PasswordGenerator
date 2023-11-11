#pragma once
#include <iostream>
#include <string>

auto readInput = [](const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return input == "y" || input == "Y";
};
    
auto GenerateWords(size_t word_amount, bool caps, bool number) -> void;

auto GenerateRandomPassword(size_t length, const bool allowSymbols) -> void;

auto GeneratePIN(size_t length) -> void;
