#pragma once
#include <string>
#include <windows.h>


auto AddColour(int colour, const std::string& text) -> void;

inline auto AddColourV2(WORD color, const std::string& text) -> void;
