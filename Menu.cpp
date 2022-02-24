// C++ program to illustrate coloring
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define cursor (DWORD) -11
HANDLE hConsole = GetStdHandle(cursor);

using namespace std;

/* COORD coord = { 0,0 }; // this is global variable                                 
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    if (y>=0 && y<=7)
        SetConsoleCursorPosition(GetStdHandle(cursor), coord);
} */


void gotoxy(short x, short y) {
    if (y>=0 && y<=7)
        SetConsoleCursorPosition(GetStdHandle(cursor), {x, y});
}
void colorize(int k) {
    // colorattribute = foreground + background * 16
    // to get red text on yellow use 4 + 14*16 = 228
    // light red on yellow would be 12 + 14*16 = 236
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, k);
}

// Driver Code
int main()
{   
    SetConsoleTextAttribute(hConsole, 15+0*16);
    system("cls");
    int pos = 5, i;
    char list[][12] = { "List Item 1", "List Item 2", "List Item 3", "List Item 4", "List Item 5"};
    
    for ( i = 0; i<5; i++)
        cout << list[i] << endl;

    while (1) {
        unsigned char c = _getch();
        if (c == 27)
            break;

        else {
            c = _getch();            // arrow key input comes in  two parts 1->0XE0, 2->value
			if (c == 'P') {          // P down 80, 50
                if (pos < 4) {
                	gotoxy(0, pos);
                	cout << list[pos];
					pos++;
				}
                gotoxy(0,pos);
				colorize(0+15*16);
				cout << list[pos];
                colorize(15);

            }
            else if (c == 'H') {        // H up, 72, 48
				if (pos > 0) { 
                	gotoxy(0, pos);
                	cout << list[pos];
					pos--;
				}
				gotoxy(0, pos);
				colorize(0+15*16);
				cout << list[pos];
                colorize(15);
        	}
		}
        								// left		75 K 4b
										//right		77 M 4d
    }
    return 0;
}
