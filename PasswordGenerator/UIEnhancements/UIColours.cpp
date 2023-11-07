#include <iostream>
#include <windows.h> 
#include <string>

void AddColour(const int colour, const std::string& text) {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    const WORD saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, colour | FOREGROUND_INTENSITY);
    
    std::cout << text << std::endl;
    
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
