#pragma once


auto GenerateWords(size_t word_amount, bool caps, bool number) -> void;

auto GenerateRandomPassword(size_t length, const bool allowSymbols) -> void;

auto GeneratePIN(size_t length) -> void;
