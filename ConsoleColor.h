#ifndef CONSOLECOLOR_H
#define CONSOLECOLOR_H

#include <windows.h>

inline void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Color codes:
// 7 - White (Default)
// 10 - Green
// 12 - Red
// 14 - Yellow
// 11 - Cyan
// 9 - Blue
// 13 - Magenta

#endif