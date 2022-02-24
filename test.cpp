#include <iostream>
#include <windows.h>

#define cursor (DWORD) -11
HANDLE hConsole = GetStdHandle(cursor);

int main(int argc, char const *argv[])
{
    int k = 12;
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, 0+15*16);
    std::cout << "foo" <<"\033[0m";
    return 0;
}
