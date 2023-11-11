#include <iostream>
#include <windows.h> 
#include <string>

auto AddColour(const int colour, const std::string& text) -> void {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    const WORD saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, colour | FOREGROUND_INTENSITY);
    
    std::cout << text << std::endl;
    
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

auto AddColourV2(WORD color, const std::string& text) -> void {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << text;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
