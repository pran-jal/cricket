#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <windows.h>

using namespace std;

#define cursor (DWORD) -11
HANDLE hConsole = GetStdHandle(cursor);

void gotoxy(short x, short y) {
    if (y>=0 && y<=28)
        SetConsoleCursorPosition(GetStdHandle(cursor), {x, y});
}
void colorize(int k) {
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, k);
}

int main()
{   
    system("dir /B >> ls.txt");

    char p[100];
    char list[27][100];
    int i = 0;
    ifstream f("ls.txt", ios::in) ;
    while (!f.eof() ) {
        f.getline((char *)&p, 100*sizeof(char));
        strcpy(list[i], p);
        i++;
    }
    f.close();
    system("del ls.txt");
    int n = i-1;
    SetConsoleTextAttribute(hConsole, 15+0*16);
    int pos = n;
    system("cls");
    for ( i = 0; i<n; i++)
        cout << list[i] << endl;

    while (1) {
        unsigned char c = _getch();
        if (c == 27) {
            break;
        }
        else {
            c = _getch();            // arrow key input comes in  two parts 1->0XE0, 2->value
			if (c == 'P') {          // P down 80, 50
                if (pos < n) {
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
