#pragma once
#include <string>

std::string GenerateWords(int word_amount, bool caps, bool number);

std::string GenerateRandomPassword(const int length, const bool allowSymbols);
