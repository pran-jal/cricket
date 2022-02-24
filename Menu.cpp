// C++ program to illustrate coloring
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define STD_OUTPUT_HANDLE (DWORD) -11

using namespace std;

/* COORD coord = { 0,0 }; // this is global variable                                 
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    if (y>=0 && y<=7)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/

void gotoxy(short x, short y) {
    if (y>=0 && y<=7)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
}
// Driver Code
int main()
{   
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int def = 15, sel = 12, pos =0 ;

    char a[][12] = { "List Item 1", "List Item 2", "List Item 3", "List Item 4", "List Item 5", "List Item 6", "List Item 7" };
    
    FlushConsoleInputBuffer(hConsole);
    int i;

    for ( i = 0; i<7; i++)
        std::cout << a[i] << endl;
    while (1) {
        unsigned char c = _getch();
        if (c == 27)
            break;
        else {
            c = _getch();            // arrow key input comes in  two parts 1->0XE0, 2->value
            if (c == 'P')            // p down
                gotoxy(0,++pos);

            else if (c == 'H')         // h up
                gotoxy(0,--pos);
        }
    }

    return 0;
}
