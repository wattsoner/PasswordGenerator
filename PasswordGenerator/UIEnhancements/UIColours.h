#pragma once
#include <string>
#include <windows.h>


void AddColour(int colour, const std::string& text);

inline void AddColourV2(WORD color, const std::string& text);
