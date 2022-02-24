// Cricket.cpp : Defines the entry point for the application.
//
//===============================HEADER FILES==============================//



#include "Cricket.h"
#include<process.h>
#include<fstream>
#include<Windows.h>
#include<windows.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<random>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<ctype.h>
#include <chrono>
#include <thread>



#define STD_OUTPUT_HANDLE (DWORD) -11

using namespace std;

//==============================turbo Alternatives ========================//

COORD coord = { 0,0 }; // this is global variable 
                                  
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int random(int max) {
    srand((unsigned)time(0));
    return (rand() % max);
}
//============================== HOME PAGE ================================//

void Design() {
    int i;
    for (i = 1; i <= 78; i++) {
        gotoxy(i, 1);
        cout << '*';
        delay(12);
    }
    for (i = 1; i <= 24; i++) {
        gotoxy(78, i);
        cout << '*';
        delay(12);
    }
    for (i = 78; i >= 1; i--) {
        gotoxy(i, 24);
        cout << '*';
        delay(12);
    }
    for (i = 24; i >= 1; i--) {
        gotoxy(1, i);
        cout << '*';
        delay(12);
    }
    gotoxy(15, 5);
    cout << "WELCOME TO";
    delay(700);
    gotoxy(30, 8);
    cout << "THE HALL OF FAME OF";
    delay(700);
    gotoxy(53, 10);
    cout << "CRICKET";
    delay(700);
    gotoxy(40, 13);
    cout << "PROJECT PREPARED BY:-";
    delay(700);
    gotoxy(40, 15);
    cout << "1) SHARAN KUMAR";
    delay(700);
    gotoxy(40, 17);
    cout << "2) PRANJAL BHARDWAJ";
    delay(700);
    gotoxy(40, 19);
    cout << "OF CLASS XII- G";
    delay(700);
    for (int k = 1; k <= 3; k++) {
        gotoxy(21, k + 10);
        cout << '|';
        delay(38);
        gotoxy(22, k + 10);
        cout << '|';
    }
    gotoxy(20, 13);
    cout << '_';
    gotoxy(23, 13);
    cout << '_';
    gotoxy(15, 10);
    for (int l = 1; l <= 9; l++) {
        gotoxy(19, 13 + l);
        cout << '|';
        gotoxy(24, 13 + l);
        cout << '|';
        delay(38);
    }
    for (int m = 1; m <= 4; m++) {
        gotoxy(19 + m, 22);
        cout << '_';
    }
    delay(38);
    gotoxy(29, 17);
    cout << "(_)";
    gotoxy(30, 16);
    cout << '_';
    gotoxy(32, 21);
    cout << "Press any key to continue...";
}

//=============================== MAIN MENU ================================//

int Choice() {
    system("cls");
    int c = 0;
    gotoxy(1, 5);
    cout << "    WELCOME TO THE OFFICIAL HOME PAGE OF BCCI  \n";
    cout << endl;
    cout << "        1. Add a Player in Fame\n";
    cout << "        2. Update a Player\n";
    cout << "        3. Modify a Player \n";
    cout << "        4. Remove a Player from Fame \n";
    cout << "        5. Performance Comparing Analysis\n";
    cout << "        6. Search by Test Jersey Number\n";
    cout << "        7. Search by Name of Player\n";
    cout << "        8. Ranking of top 3 Batsmen\n";
    cout << "        9. Ranking of top 3 Bowlers\n";
    cout << "       10. Latest News of your favourite Player\n";
    cout << "       11. Play a Cricket Quizz..\n";
    cout << "       12. Show proflile of each player\n";
    cout << "       13. Play a Cricket Game ;-) \n";
    cout << "       14. Exit The Hall of Fame \n";
    delay(30);
    cout << endl;
    cout << "        * Choose the desired Alternative by pressing corresponding Numbers... *\n";
    cin >> c;
    return c;
}

//============================= CLASS PLAY ================================//

class Play {
    int jn, match, inn, run, wkts, totr, totw, k, runt, wn;
    char name[50], facts[150], agnst[20];
    float avg;
    float calcavg() {
        avg = (float)(run + runt) / (inn + k);
        return(avg);
    }
    int Runs() {
        totr = run + runt;
        return(totr);
    }
    int Wickts() {
        totw = wkts + wn;
        return(totw);
    }
public:

    void newplay() {
        gotoxy(10, 4);
        cout << "Enter Indian Test Jersey number:\n";
        gotoxy(10, 5);
        cin >> jn;
        gotoxy(10, 7);
        cout << "Enter Name:\n";
        gotoxy(10, 8);
        gets_s(name);
        gotoxy(10, 10);
        cout << "Enter the number of International Matches Played:\n";
        gotoxy(10, 11);
        cin >> match;
        gotoxy(10, 13);
        cout << "Enter the number of Innings Played:\n";
        gotoxy(10, 14);
        cin >> inn;
        gotoxy(10, 16);
        cout << "Enter International Runs Scored:\n";
        gotoxy(10, 17);
        cin >> run;
        gotoxy(10, 19);
        cout << "Enter No. of International Wickets:\n";
        gotoxy(10, 20);
        cin >> wkts;
        calcavg();
        Runs();
        Wickts();
    }
    Play() {
        runt = 0;
        wn = 0;
        strcpy(facts, "----");
        k = 0;
        strcpy(agnst, "opponents");
    }
    void edition() {
        cout << "Enter the Runs Scored by the Player in Last Match" << endl;
        cin >> runt;
        cout << endl;
        cout << "Enter the Wickets taken by the Batsman in Last Match" << endl;
        cin >> wn;
        cout << endl;
        cout << "Enter the team against which the Player Played" << endl;
        gets_s(agnst);
        cout << endl;
        cout << "Any intresting fact in the Last Match...." << endl;
        gets_s(facts);
        k++;
        Runs();
        Wickts();
    }
    void showedition() {
        system("cls");
        cout << endl;
        cout << endl;
        cout << "                            N E W S                         " << endl;
        cout << endl;
        cout << endl;
        cout << "  The well known Cricketer who is already a household name for" << endl;
        cout << endl;
        cout << "   all the cricket fans " << name << " has scored " << runt << " runs in his last match. " << endl;
        cout << endl;
        cout << endl;
        cout << "  This last match was played against " << agnst << " which is a stronger side as" << endl;
        cout << endl;
        cout << "   far as the batting strength is concerned.";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "  Player also took " << wn << " wickets. ";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "  Now see the intresting fact about last match - ";
        cout << endl;
        cout << endl;
        cout << "		       * " << facts;
        cout << endl;
    }
    void show() {
        cout << "Test Jersey no.: " << jn << endl;
        cout << endl;
        cout << "Name: " << name << endl;
        cout << endl;
        cout << "Runs: " << run + runt << endl;
        cout << endl;
        cout << "Matches: " << match + k << endl;
        cout << endl;
        cout << "Innings Played: " << inn + k << endl;
        cout << endl;
        cout << "Wickets: " << wkts + wn << endl;
        cout << endl;
        cout << "Batting Average: " << avg << endl;
    }
    char* retname() {
        return(name);
    }
    int retjn() {
        return(jn);
    }
    int retrun() {
        return(totr);
    }
    int retwick(){
        return(totw);
    }
    float retavg(){
        return(avg);
    }
};

//=============================== FUNCTIONS ===============================//

void Add();
void profilebyname();
void profilebyjn();
void analysis();
void rankingbywickts();
void rankingbyruns();
void Delete();
void Quiz();
void edit();
void ufn();
void news();
void showall();

//=================================== ADD =================================//

void Add() {
    system("cls");
    char pwd[8];
    int i = 0;
    gotoxy(10, 5);
    cout << "*** You can only Add Player if you are an Associate Member of BCCI ***" << endl;
    gotoxy(25, 7);
    cout << "Enter the seven digit PASSWORD" << endl;
    gotoxy(32, 9);
    while (i < 8) {
        pwd[i] = getch();
        if (pwd[i] == 13) {
            pwd[i] = '\0'; break;
        }
        else {
            cout << '*' << " ";
        }
        i++;
    }
    if (strcmp(pwd, "cricket") == 0) {
        system("cls");
        ofstream f("play.dat", ios::binary | ios::app);
        Play p;
        p.newplay();
        f.write((char*)&p, sizeof(p));
        f.close();
        cout << endl;
        cout << "* * * BCCI congratulates the Player for their addition in The Hall of Fame * * * ";
        getch();
    }
    else{
        gotoxy(20, 20);
        cout << "Enter the correct PASSWORD";
    }
}

//============================ VIEW BY NAME ===============================//

void profilebyname() {
    system("cls"); char n[30];
    Play p;
    ifstream f("play.dat", ios::binary);
    int t = 0, c = 0;
    for (int i = 1; i <= 69; i++) {
        gotoxy(6 + i, 4);
        cout << '*';
        delay(11);
    }
    delay(100);
    gotoxy(7, 3);
    cout << " Please enter the Name of the Cricketer whose Profile you want to see. " << endl;
    cout << endl;
    gets_s(n);
    cout << endl;
    cout << endl;
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (!f.eof() && strcmpi(n, p.retname()) == 0) {
            p.show();
            c = 1;
            t++;
        }
    }
    cout << endl;
    if (c == 0) {
        cout << "Sorry, Hall of Fame does not have such a Player." << endl;
    }
    f.close();
    cout << "There are " << t << " Players with Name '" << n << "'" << endl;
}

//======================== VIEW BY JERSEY NUMBER ===========================//

void profilebyjn() {
    system("cls");
    int n, c = 0;
    ifstream f("play.dat", ios::binary);
    for (int i = 1; i <= 64; i++) {
        gotoxy(6 + i, 4);
        cout << '*';
        delay(11);
    }
    delay(100);
    gotoxy(7, 3);
    cout << "Enter the jersey number of the Player whose Profile you want to see" << endl;
    cout << endl;
    cin >> n;
    Play p;
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (n == p.retjn()) {
            p.show();
            c = 1;
        }
    }
    if (c == 0) {
        cout << "Sorry, The Hall of Fame does not have such a Player. " << endl;
    }
    f.close();
}

//=========================== PLAYER ANALYSIS =============================//

void analysis() {
    system("cls");
    char n[30];
    Play p;
    ifstream f("play.dat", ios::binary);
    int t = 0, c = 0;
    for (int i = 1; i <= 69; i++) {
        gotoxy(6 + i, 4);
        cout << '*';
        delay(11);
    }
    delay(100);
    gotoxy(7, 3);
    cout << "Please enter the Name of the Cricketer whose Analysis you want to see" << endl;
    cout << endl;
    gets_s(n);
    cout << endl;
    cout << endl;
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (!f.eof() && strcmpi(n, p.retname()) == 0) {
            int a, r, w, j;
            char ch = 219;
            a = p.retavg();
            r = p.retrun();
            w = p.retwick();
            int Hr;
            Hr = (r / 2000);
            int Ha = (a / 10);
            int Hw = (w / 60);
            for (j = -1; j <= 10; j++) {
                gotoxy(17, j + 9);
                cout << '|';
            }
            for (j = -1; j <= 10; j++) {
                gotoxy(37, j + 9);
                cout << '|';
            }
            for (j = -1; j <= 10; j++) {
                gotoxy(57, j + 9);
                cout << '|';
            }
            gotoxy(20, 21);
            cout << "RUNS";
            gotoxy(40, 21);
            cout << "WICKETS";
            gotoxy(60, 21);
            cout << "BATTING AVERAGE";
            cout << endl;
            gotoxy(12, 9);
            cout << "20000";
            gotoxy(34, 9);
            cout << "600";
            gotoxy(54, 9);
            cout << "100";
            for (int i = 0; i <= Hr; i++) {        ////loop for height of runs
                gotoxy(20, 19 - i);
                cout << ch;
                gotoxy(21, 19 - i);
                cout << ch;
                gotoxy(22, 19 - i);
                cout << ch;
                gotoxy(23, 19 - i);
                cout << ch;
                delay(100);
            }
            for (int k = 0; k <= Hw; k++) {        ////loop fot hight of wickets
                gotoxy(40, 19 - k);
                cout << ch;
                gotoxy(41, 19 - k);
                cout << ch;
                gotoxy(42, 19 - k);
                cout << ch;
                gotoxy(43, 19 - k);
                cout << ch;
                delay(100);
            }
            for (int m = 0; m <= Ha; m++) {        ////loop fot hight of average
                gotoxy(60, 19 - m);
                cout << ch;
                gotoxy(61, 19 - m);
                cout << ch;
                gotoxy(62, 19 - m);
                cout << ch;
                gotoxy(63, 19 - m);
                cout << ch;
                delay(100);
            }
            if (a + r >= 15100 || w >= 500) {
                gotoxy(25, 6);
                cout << "STAR RATINGS   *  *  *  *  *";
            }
            else if (a + r >= 10100 || w >= 400) {
                gotoxy(25, 6);
                cout << "STAR RATINGS   *  *  *  *  ";
            }
            else if (a + r >= 7100 || w >= 250) {
                gotoxy(25, 6);
                cout << "STAR RATINGS   *  *  *  ";
            }
            else if (a + r >= 5100 || w >= 150) {
                gotoxy(25, 6);
                cout << "STAR RATINGS   *  *  ";
            }
            else {
                gotoxy(25, 6);
                cout << "STAR RATINGS  *";
            }
            c = 1;
            t++;
        }
    }
    cout << endl;
    if (c == 0) {
        cout << "Sorry, The Hall of Fame does not have such a Player." << endl;
    }
    f.close();
}

//===================== RANKING BY WICKETS ================================//

void rankingbywickts() {
    system("cls");
    ifstream f("play.dat", ios::binary);
    int k[] = { 0,0,0 };
    Play p;
    gotoxy(30, 4);
    cout << "LIST OF TOP 3 BOWLERS";
    gotoxy(24, 8);
    cout << " * NAMES *                  * WICKETS *";
    for (int s = 1; s <= 21; s++) {
        gotoxy(s + 29, 5);
        cout << '~';
    }
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (k[0] < p.retwick())
            k[0] = p.retwick();
    }
    f.close();
    ifstream f1("play.dat", ios::binary);
    while (!f1.eof()) {
        f1.read((char*)&p, sizeof(p));
        if ((k[1] < p.retwick()) && (p.retwick() != k[0]))
            k[1] = p.retwick();
    }
    f1.close();
    ifstream f2("play.dat", ios::binary);
    while (!f2.eof()) {
        f2.read((char*)&p, sizeof(p));
        if ((k[2] < p.retwick()) && (p.retwick() != k[1]) && (p.retwick() != k[0]))
            k[2] = p.retwick();
    }
    f2.close();
    ifstream f3("play.dat", ios::binary);
    gotoxy(52, 10);
    cout << k[0] << endl;
    gotoxy(52, 12);
    cout << k[1] << endl;
    gotoxy(52, 14);
    cout << k[2] << endl;
    while (!f3.eof()) {
        f3.read((char*)&p, sizeof(p));
        if (k[0] == p.retwick()) {
            gotoxy(23, 10);
            cout << "1. " << p.retname() << endl;
        }
    }
    f3.close();
    ifstream f4("play.dat", ios::binary);
    while (!f4.eof()) {
        f4.read((char*)&p, sizeof(p));
        if (k[1] == p.retwick()) {
            gotoxy(23, 12);
            cout << "2. " << p.retname() << endl;
        }
    }
    f4.close();
    ifstream f5("play.dat", ios::binary);
    while (!f5.eof()) {
        f5.read((char*)&p, sizeof(p));
        if (k[2] == p.retwick()) {
            gotoxy(23, 14);
            cout << "3. " << p.retname() << endl;
        }
    }
    f5.close();
}

//========================= RANKING BY RUNS ================================//

void rankingbyruns() {
    system("cls");
    ifstream f("play.dat", ios::binary);
    int k[] = { 0,0,0 };
    Play p;
    gotoxy(30, 4);
    cout << "LIST OF TOP 3 BATSMEN";
    gotoxy(24, 8);
    cout << " * NAMES *                  * RUNS *";
    for (int s = 1; s <= 21; s++) {
        gotoxy(s + 29, 5);
        cout << '~';
    }
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (k[0] < p.retrun())
            k[0] = p.retrun();
    }
    f.close();
    ifstream f1("play.dat", ios::binary);
    while (!f1.eof()) {
        f1.read((char*)&p, sizeof(p));
        if ((k[1] < p.retrun()) && (p.retrun() != k[0]))
            k[1] = p.retrun();
    }
    f1.close();
    ifstream f2("play.dat", ios::binary);
    while (!f2.eof()) {
        f2.read((char*)&p, sizeof(p));
        if ((k[2] < p.retrun()) && (p.retrun() != k[1]) && (p.retrun() != k[0]))
            k[2] = p.retrun();
    }
    f2.close();
    ifstream f3("play.dat", ios::binary);
    gotoxy(52, 10);
    cout << k[0] << endl;
    gotoxy(52, 12);
    cout << k[1] << endl;
    gotoxy(52, 14);
    cout << k[2] << endl;
    while (!f3.eof()) {
        f3.read((char*)&p, sizeof(p));
        if (k[0] == p.retrun()) {
            gotoxy(23, 10);
            cout << "1. " << p.retname() << endl;
        }
    }
    f3.close();
    ifstream f4("play.dat", ios::binary);
    while (!f4.eof()) {
        f4.read((char*)&p, sizeof(p));
        if (k[1] == p.retrun()) {
            gotoxy(23, 12);
            cout << "2. " << p.retname() << endl;
        }
    }
    f4.close();
    ifstream f5("play.dat", ios::binary);
    while (!f5.eof()) {
        f5.read((char*)&p, sizeof(p));
        if (k[2] == p.retrun()) {
            gotoxy(23, 14);
            cout << "3. " << p.retname() << endl;
        }
    }
    f5.close();
}

//================================= DELETE =================================//

void Delete() {
    system("cls");
    char pwd[8]; int i = 0;
    gotoxy(10, 5);
    cout << "*** You can Delete a Player only if you are an Associate Member of BCCI ***" << endl;
    gotoxy(25, 7);
    cout << "Enter the seven digit PASSWORD" << endl;
    gotoxy(32, 9);
    while (i < 8) {
        pwd[i] = getch();
        if (pwd[i] == 13){
            pwd[i] = '\0'; 
            break;
        }
        else
            cout << '*' << " ";
        i++;
    }
    if (strcmp(pwd, "cricket") == 0) {
        system("cls");
        ifstream f("play.dat", ios::binary);
        ofstream f1("temp.dat", ios::binary);
        Play p;
        char no[30]; int t = 0;
        for (int i = 1; i <= 67; i++) {
            gotoxy(6 + i, 4);
            cout << '*';
            delay(11);
        }
        delay(100);
        gotoxy(7, 3);
        cout << "Please enter the Name of the Cricketer you want to remove" << endl;
        cout << endl;
        gets_s(no);
        while (!f.eof()) {
            f.read((char*)&p, sizeof(p));
            if (!f.eof() && strcmp(no, p.retname()) != 0)
                f1.write((char*)&p, sizeof(p));
            else {
                t = 1;
                cout << "PLAYER FOUND ";
                p.show();
                getch();
                break;
            }
        }
        f.close();
        f1.close();
        if (t == 0) {
            cout << "\nPLAYER NOT FOUND !!!\b ";
            getch();
        }
        else {
            remove("play.dat");
            rename("temp.dat", "play.dat");
            cout << "\nPLAYER REMOVED FROM HALL OF FAME !!!";
            getch();
        }
    }
    else {
        gotoxy(20, 20);
        cout << "Enter the correct PASSWORD";
    }
}

//=============================== QUIZ =====================================//

int score = 0;
void Q1() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Which Cricketer has the Record of most no. of International Centuries ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Brain Lara";
    delay(800);
    gotoxy(48, 10);
    cout << "B. Rickey Ponting";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Sachin Tendulkar";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Jacques Kallis";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to Submit your Answer. " << endl;
    cin >> ch;
    if (ch == 'C' || ch == 'c')
        score = score + 10;
    else
        score = score - 5;
}
void Q2() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Which Cricketer won the Award 'Player of The Tournament' in ICC Cricket World Cup 2011 ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Gautam Gambhir";
    delay(800);
    gotoxy(48, 10);
    cout << "B. M.S. Dhoni";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Sachin Tendulkar";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Yuvraj Singh";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to submit your answer. " << endl;
    cin >> ch;
    if (ch == 'D' || ch == 'd')
        score = score + 10;
    else
        score = score - 5;
}
void Q3() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Who is the only Indian Cricketer to won The Bharat Ratna Award ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Sachin Tendulkar";
    delay(800);
    gotoxy(48, 10);
    cout << "B. Kapil Dev";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Sunil Gavaskar";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Lala Amarnath";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to submit your answer. " << endl;
    cin >> ch;
    if (ch == 'A' || ch == 'a')
        score = score + 10;
    else
        score = score - 5;
}
void Q4() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Who was named as The Captain of ICC Women Cricket team of the Tournament ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Heather Knight (England)";
    delay(800);
    gotoxy(48, 10);
    cout << "B. Mithali Raj (India)";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Meg Lanning(Australia)";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Dane van Niekerk(South Africa)";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to submit your answer." << endl;
    cin >> ch;
    if (ch == 'B' || ch == 'b')
        score = score + 10;
    else
        score = score - 5;
}
void Q5() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Which Cricket Stadium is known as the Mecca of Cricket ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Eden Garden (Kolkata)";
    delay(800);
    gotoxy(48, 10);
    cout << "B. Lords Cricket Ground (London)";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Feroz Shah Kotla (Delhi)";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Melbourne Cricket Ground (Melbourne)";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to submit your answer." << endl;
    cin >> ch;
    if (ch == 'B' || ch == 'b')
        score = score + 10;
    else
        score = score - 5;
}
void Q6() {
    char ch;
    system("cls");
    gotoxy(6, 8);
    cout << "Q. Which of following Captain has set of all of the ICC Trophies ?";
    delay(800);
    gotoxy(10, 10);
    cout << "A. Rickey Ponting";
    delay(800);
    gotoxy(48, 10);
    cout << "B. Graeme Smith";
    delay(800);
    gotoxy(10, 13);
    cout << "C. Stephen Fleming";
    delay(800);
    gotoxy(48, 13);
    cout << "D. Mahendra Singh Dhoni";
    gotoxy(10, 18);
    cout << "Press 'A', 'B', 'C' or 'D' to submit your answer." << endl;
    cin >> ch;
    if (ch == 'D' || ch == 'd')
        score = score + 10;
    else
        score = score - 5;
}
void Quiz() {
    int A[6];
    int k, ct = 0;
    int a, b, c, d, e, f;
    while (ct != 6) {
    A:
        k = random(6) + 1;
        if (k != A[0] && k != A[1] && k != A[2] && k != A[3] && k != A[4] && k != A[5]) {
            switch (k) {
            case 1:Q1(); break;
            case 2:Q2(); break;
            case 3:Q3(); break;
            case 4:Q4(); break;
            case 5:Q5(); break;
            case 6:Q6(); break;
            }
        }
        else
            goto A;
        A[ct] = k;
        ct++;
    }
    cout << ct;
}
void Quizscrn() {
    system("cls");
    int m;
    for (m = 1; m <= 78; m++) {
        gotoxy(m, 1);
        cout << '#';
        delay(12);
    }
    for (m = 1; m <= 24; m++) {
        gotoxy(78, m);
        cout << '#';
        delay(12);
    }
    for (m = 78; m >= 1; m--) {
        gotoxy(m, 24);
        cout << '#';
        delay(12);
    }
    for (m = 24; m >= 1; m--) {
        gotoxy(1, m);
        cout << '#';
        delay(12);
    }
    for (int i = 1; i <= 29; i++) {
        gotoxy(24 + i, 4);
        cout << '*';
        delay(65);
    }
    gotoxy(25, 3);
    cout << "WELCOME";
    delay(700);
    gotoxy(34, 3);
    cout << "TO";
    delay(700);
    gotoxy(39, 3);
    cout << "CRICKET";
    delay(700);
    gotoxy(49, 3);
    cout << "QUIZ";
    delay(500);
    gotoxy(18, 6);
    cout << "RULES OF QUIZ" << endl;
    delay(800);
    gotoxy(5, 8);
    cout << "* User will be awarded 10 points for every correct answer. " << endl;
    delay(800);
    gotoxy(5, 10);
    cout << "* 5 points will be deducted for every wrong answer. " << endl;
    delay(800);
    gotoxy(5, 12);
    cout << "* Score will be shown at the end of The Quiz with Star Ratings. ";
    delay(700);
    gotoxy(20, 18);
    cout << "To start Quiz Please Enter any key...";
    getch();
}
void start() {
    Quizscrn();
    Quiz();
    system("cls");
    if (score <= 60 && score > 52) {
        gotoxy(10, 6);
        cout << "Your Score is : " << score << endl;
        cout << endl;
        gotoxy(11, 11);
        cout << "CONGRATULATIONS !!! You have Great Knowledge of Cricket. " << endl;
        cout << endl;
        gotoxy(11, 13);
        cout << "Your Star Ratings:- * * * * *";
    }
    else if (score <= 52 && score > 40) {
        gotoxy(10, 6);
        cout << "Your Score is : " << score << endl;
        cout << endl;
        gotoxy(11, 11);
        cout << "CONGRATULATIONS !!! You have Good Knowledge of Cricket. " << endl;
        cout << endl;
        gotoxy(11, 13);
        cout << "Your Star Ratings:- * * * * ";
    }
    else if (score <= 40 && score > 35) {
        gotoxy(10, 6);
        cout << "Your Score is " << score << endl;
        cout << endl;
        gotoxy(11, 11);
        cout << "You have less Knowledge of Cricket" << endl;
        cout << endl;
        gotoxy(11, 13);
        cout << "Your Star Ratings:- * * *  ";
    }
    else {
        gotoxy(10, 6);
        cout << "Your Score is : " << score << endl;
        cout << endl;
        gotoxy(11, 11);
        cout << "You have less than Sufficient Knowledge of Cricket. " << endl;
        cout << endl;
        gotoxy(11, 13);
        cout << "Your Star Ratings:- * *   ";
    }
    int h = 0; char ch;
    if (h < score) {
        h = score;
        gotoxy(15, 17);
        cout << "WOOHOOOOO!! ITS THE NEW HIGH SCORE";
        ofstream out("Quiz.txt");
        out.seekp(0, ios::beg);
        out << h;
        out.close();
    }

}

//======================== MODIFY RECORD OF A PLAYER =======================//

void edit() {
    system("cls");
    char pwd[8]; int i = 0;
    gotoxy(10, 5);
    cout << "*** You can only Edit Player if you are an Associate Member of BCCI ***" << endl;
    gotoxy(25, 7);
    cout << "Enter the seven digit PASSWORD" << endl;
    gotoxy(32, 9);
    while (i < 8) {
        pwd[i] = getch();
        if (pwd[i] == 13) {
            pwd[i] = '\0'; 
            break;
        }
        else
            cout << '*' << " ";

        i++;
    }
    if (strcmp(pwd, "cricket") == 0) {
        system("cls");
        char n[30];
        Play p;
        fstream f("play.dat", ios::binary | ios::in | ios::out);
        int t = 0, c = 0;
        for (int i = 1; i <= 69; i++) {
            gotoxy(6 + i, 4);
            cout << '*';
            delay(11);
        }
        delay(100);
        gotoxy(7, 3);
        cout << "Please enter Name of the Cricketer you Want to Edit. " << endl;
        cout << endl;
        gets_s(n);
        cout << endl;
        cout << endl;
        while (!f.eof()) {
            f.read((char*)&p, sizeof(p));
            t++;
            if (!f.eof() && strcmpi(n, p.retname()) == 0) {
                c = 1;
                cout << "Played Found" << endl;
                getch();
                system("cls");
                p.newplay();
                f.seekg((t - 1) * sizeof(p));
                f.write((char*)&p, sizeof(p));
                cout << "Player Edited" << endl;
            }
        }
        cout << endl;
        if (c == 0)
            cout << "Sorry, The Hall of Fame does not have such a Player." << endl;
        f.close();
    }
    else{
        gotoxy(20, 20);
        cout << "Enter the correct PASSWORD";
    }
}

//========================== UPDATE A PLAYER ================================//

void ufn() {
    system("cls");
    char pwd[8]; int i = 0;
    gotoxy(10, 5);
    cout << "*** You can only Edit Player if you are an Associate Member of BCCI ***" << endl;
    gotoxy(25, 7);
    cout << "Enter the seven digit PASSWORD" << endl;
    gotoxy(32, 9);
    while (i < 8) {
        pwd[i] = getch();
        if (pwd[i] == 13) {
            pwd[i] = '\0'; 
            break;
        }

        else
            cout << '*' << " ";
        i++;
    }
    if (strcmp(pwd, "cricket") == 0) {
        system("cls"); char n[30];
        Play p;
        fstream f("play.dat", ios::binary | ios::in | ios::out);
        int t = 0, c = 0;
        for (int i = 1; i <= 69; i++) {
            gotoxy(6 + i, 4);
            cout << '*';
            delay(11);
        }
        delay(100);
        gotoxy(7, 3);
        cout << "Please enter the Name of the Cricketer you Want to Update. " << endl;
        cout << endl;
        gets_s(n);
        cout << endl;
        cout << endl;
        while (!f.eof()) {
            f.read((char*)&p, sizeof(p));
            t++;
            if (!f.eof() && strcmpi(n, p.retname()) == 0) {
                cout << "Player Found" << endl;
                cout << endl;
                p.edition();
                f.seekg((t - 1) * sizeof(p));
                f.write((char*)&p, sizeof(p));
                cout << endl;
                cout << "Played Updated";
                c = 1;
                break;
            }
        }
        cout << endl;
        if (c == 0)
            cout << "Sorry, Hall of Fame does not have such a Player." << endl;
        f.close();
    }
    else {
        gotoxy(20, 20);
        cout << "Enter the correct PASSWORD";
    }
}

//=============================== NEWS ====================================//

void news() {
    system("cls"); char n[30];
    Play p;
    ifstream f("play.dat", ios::binary);
    int t = 0, c = 0;
    for (int i = 1; i <= 69; i++) {
        gotoxy(6 + i, 4);
        cout << '*';
        delay(11);
    }
    delay(100);
    gotoxy(6, 3);
    cout << "Please enter the Name of the Cricketer who's latest news you want to see. " << endl;
    cout << endl;
    gets_s(n);
    cout << endl;
    cout << endl;
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (!f.eof() && strcmpi(n, p.retname()) == 0) {
            p.showedition();
            c = 1;
            t++;
        }
    }
    cout << endl;
    if (c == 0)
        cout << "Sorry, Hall of Fame does not have such a Player." << endl;
    f.close();
}

//============================== SHOW ALL ==================================//

void showall() {
    ifstream f("play.dat", ios::binary);
    Play p;
    while (!f.eof()) {
        f.read((char*)&p, sizeof(p));
        if (!f.eof()) {
            p.show();
            cout << endl;
            cout << endl;
        }
    }
}
//================================GAME=====================================//
void Bscreen() {
    system("cls");
    for (int i = 1; i <= 38; i++) {
        gotoxy(40 + i, 7);
        cout << '-';
        gotoxy(41 - i, 7);
        cout << '-';

        gotoxy(40 + i, 5);
        cout << '_';
        gotoxy(41 - i, 5);
        cout << '_';
        delay(25);
    }
    gotoxy(64, 2);
    cout << " -------------";
    gotoxy(63, 5);
    cout << " |   L I V E   |";
    gotoxy(1, 3); //textbackground(RED);
    cout << "    @   @   @   |[SIX]   @ @  @ @ @ @  @  "; cprintf("            "); cout << "]@     | STAR SPORTS |";
    gotoxy(1, 4); //textbackground(WHITE);
    cout << "   |#| | | | |  |    |  | | |  | | | | | |"; cprintf("            "); cout << " | |   |-------------|";
    gotoxy(43, 5); //textbackground(GREEN);
    cprintf("            "); //textbackground(BLACK);
    gotoxy(1, 6);
    cout << " CRICKET CUP 2017  |  CRICKET CUP 2017  |  CRICKET CUP 2017     ~~~~~~~~~~~~~~ ";
    gotoxy(39, 11);
    cout << '/';
    gotoxy(38, 12);
    cout << '/';
    gotoxy(37, 13);
    cout << '/';
    gotoxy(36, 14);
    cout << '/';
    gotoxy(34, 16);
    cout << '/';
    gotoxy(33, 17);
    cout << '/';
    gotoxy(32, 18);
    cout << '/';
    gotoxy(31, 19);
    cout << '/';
    gotoxy(30, 20);
    cout << '/';
    gotoxy(29, 21);
    cout << '/';

    char sh = 92;
    gotoxy(48, 12);
    cout << sh;
    gotoxy(49, 13);
    cout << sh;
    gotoxy(50, 14);
    cout << sh;
    gotoxy(51, 15);
    cout << sh;
    gotoxy(52, 16);
    cout << sh;
    gotoxy(53, 17);
    cout << sh;
    gotoxy(54, 18);
    cout << sh;
    gotoxy(55, 19);
    cout << sh;
    gotoxy(56, 20);
    cout << sh;
    gotoxy(57, 21);
    cout << sh;
    gotoxy(30, 8);
    cout << '*';
    gotoxy(13, 12);
    cout << '*';
    gotoxy(19, 10);
    cout << '*';
    gotoxy(7, 16);
    cout << '*';
    gotoxy(53, 8);
    cout << '*';
    gotoxy(72, 12);
    cout << '*';
    gotoxy(67, 10);
    cout << '*';
    gotoxy(77, 16);
    cout << '*';
    gotoxy(7, 21);
    cout << '*';
    gotoxy(77, 21);
    cout << '*';
    gotoxy(39, 11);
    cout << "_";
    gotoxy(40, 11);
    cout << "_";
    gotoxy(41, 11);
    cout << "_";
    gotoxy(42, 11);
    cout << "|||";
    gotoxy(45, 11);
    cout << "_";
    gotoxy(46, 11);
    cout << "_";
    gotoxy(42, 10);
    cout << "|||";
    gotoxy(35, 15);
    cout << "(~)_";
    gotoxy(35, 16);
    cout << "/ |";
    gotoxy(34, 17);
    cout << "|   =";
    gotoxy(34, 18);
    cout << "|  | ";
    gotoxy(35, 19);
    cout << "| | ";
    gotoxy(35, 20);
    cout << "| |";
    gotoxy(39, 17);
    cout << "!";
    char ch = 219;
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;
    gotoxy(36, 21);
    cout << "^^";
    gotoxy(41, 19);
    cout << "| | |";
    gotoxy(41, 20);
    cout << "| | |";
    gotoxy(41, 21);
    cout << "| | |";
    gotoxy(41, 18);
    cout << " _ _";
    for (int l = 29; l <= 58; l++) {
        gotoxy(l, 22);
        cout << "-";
    }
    gotoxy(23, 8);                                ////field left far
    cout << "@";
    gotoxy(21, 9);
    cout << "![]!";
    gotoxy(22, 10);
    cout << "||";
    gotoxy(64, 8);                                ////fieldr right far
    cout << "@";
    gotoxy(63, 9);
    cout << "![]!";
    gotoxy(64, 10);
    cout << "||";

    gotoxy(62, 15);                                ////fieldr  right near
    cout << "@";
    gotoxy(61, 16);
    cout << "![]!";
    gotoxy(62, 17);
    cout << "||";

    gotoxy(20, 15);                                ////fieldr left near
    cout << "@";
    gotoxy(18, 16);
    cout << "![]!";
    gotoxy(19, 17);
    cout << "||";
    //runner and umpire
    gotoxy(37, 9);                                ////
    cout << "@";
    gotoxy(36, 10);
    cout << "![]!";
    gotoxy(36, 11);
    cout << "|||";
    gotoxy(48, 9);
    cout << "@";
    gotoxy(46, 10);
    cout << " []!";
    gotoxy(46, 11);
    cout << " ||";

}
void Sbowling() {
    gotoxy(46, 9);
    cout << '!';
    delay(100);
    gotoxy(46, 9);
    cout << " ";
    delay(100);
    gotoxy(46, 10);
    cout << '!';
    for (int i = 11; i <= 17; i++) {
        gotoxy(45, i);
        cout << 'o';
        delay(70);
        gotoxy(45, i);
        cout << " ";
        if (i == 11) {
            gotoxy(45, 11);
            cout << '_';
        }
        delay(70);
    }
}
void Inswing() {
    gotoxy(46, 9);
    cout << '!';
    delay(100);
    gotoxy(46, 9);
    cout << " ";
    delay(100);
    gotoxy(46, 10);
    cout << '!';

    int i;
    for (i = 11; i < 15; i++) {
        gotoxy(45, i);
        cout << 'o';
        delay(70);
        gotoxy(45, i);
        cout << " ";
        if (i == 11) {
            gotoxy(45, 11);
            cout << '_';
        }
        delay(70);
    }
    for (i = 15; i <= 17; i++) {
        gotoxy(59 - i, i);
        cout << 'o';
        delay(70);
        gotoxy(59 - i, i);
        cout << " ";
        delay(70);
    }
}
void Outswing() {
    gotoxy(46, 9);
    cout << '!';
    delay(100);
    gotoxy(46, 9);
    cout << " ";
    delay(100);
    gotoxy(46, 10);
    cout << '!';

    int i;
    for (i = 11; i < 15; i++) {
        gotoxy(45, i);
        cout << 'o';
        delay(70);
        gotoxy(45, i);
        cout << " ";
        if (i == 11) {
            gotoxy(45, 11);
            cout << '_';
        }
        delay(70);
    }
    for (i = 15; i <= 17; i++) {
        gotoxy(31 + i, i);
        cout << 'o';
        delay(70);
        gotoxy(31 + i, i);
        cout << " ";
        delay(70);
    }
    gotoxy(60, 7);
    cout << '-';
    gotoxy(56, 7);
    cout << '-';
    gotoxy(55, 7);
    cout << '-';
}
void fourL() {                                  ////fourr LEFT
    int i;
    for (i = 1; i <= 10; i++) {
        gotoxy(40 - i, 17 - i);
        cout << 'o';
        delay(30);
        gotoxy(40 - i, 17 - i);
        cout << " ";
        delay(30);
        gotoxy(37, 15);
        cout << ')';
    }
    gotoxy(30, 7);
    cout << '-';
}
void sixL() {                                   ////SIX LEFT
    gotoxy(38, 12);
    cout << 'o';
    delay(40);
    gotoxy(38, 12);
    cout << '/';
    delay(40);
    gotoxy(38, 11);
    cout << 'o';
    delay(40);
    gotoxy(38, 11);
    cout << "|";
    delay(40);
    gotoxy(38, 10);
    cout << 'o';
    delay(45);
    gotoxy(38, 10);
    cout << "]";
    delay(45);
    gotoxy(36, 9);
    cout << 'o';
    delay(45);
    gotoxy(36, 9);
    cout << " ";
    delay(55);
    gotoxy(33, 8);
    cout << 'o';
    delay(55);
    gotoxy(33, 8);
    cout << " ";
    delay(55);
    gotoxy(30, 7);
    cout << 'o';
    delay(55);
    gotoxy(30, 7);
    cout << " ";
    delay(55);
    gotoxy(27, 6);
    cout << 'o';
    delay(55);
    gotoxy(27, 6);
    cout << 'K';
    delay(55);
    gotoxy(25, 5);
    cout << 'o';
    delay(55);
    gotoxy(25, 5);
    cout << " ";
    delay(55);
    gotoxy(23, 4);
    cout << 'o';
    delay(55);
    gotoxy(23, 4);
    cout << " ";
    gotoxy(30, 7);
    cout << '-';
    gotoxy(25, 5);
    cout << '_';
    for (int i = 0; i <= 7; i++) {
        //sound(100);
        delay(30);
        //nosound();
        //sound(800 * i);
        delay(50);
        //nosound();
    }
}
void BatL() {                                  //////BAT LEFT
    char ch = 219;
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;
    delay(70);
    gotoxy(39, 18);
    cout << "  ";
    gotoxy(39, 19);
    cout << "  ";
    gotoxy(39, 20);
    cout << "  ";
    delay(70);
    gotoxy(39, 17);
    cout << ch;
    gotoxy(39, 16);
    cout << ch;
    gotoxy(39, 15);
    cout << ch;
    delay(70);
    gotoxy(39, 17);
    cout << "  ";
    gotoxy(39, 16);
    cout << "  ";
    gotoxy(39, 15);
    cout << "  ";
    delay(70);
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;

}
void BatR() {                                  //////////BAT RIGHT
    char ch = 219;
    char c = 220;
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;
    delay(70);
    gotoxy(39, 18);
    cout << "  ";
    gotoxy(39, 19);
    cout << "  ";
    gotoxy(39, 20);
    cout << "  ";
    delay(70);
    gotoxy(39, 17);
    cout << c << c << c << c << c << c;
    delay(100);
    gotoxy(39, 17);
    cout << "      ";
    delay(100);
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;
}
void sixR() {                                     ///////SIX RIGHT
    gotoxy(50, 12);
    cout << 'o';
    delay(40);
    gotoxy(50, 12);
    cout << " ";
    delay(40);
    gotoxy(51, 11);
    cout << 'o';
    delay(40);
    gotoxy(51, 11);
    cout << " ";
    delay(40);
    gotoxy(53, 10);
    cout << 'o';
    delay(40);
    gotoxy(53, 10);
    cout << " ";
    delay(40);
    gotoxy(55, 9);
    cout << 'o';
    delay(35);
    gotoxy(55, 9);
    cout << " ";
    delay(35);
    gotoxy(57, 8);
    cout << 'o';
    delay(30);
    gotoxy(57, 8);
    cout << " ";
    delay(30);
    gotoxy(60, 7);
    cout << 'o';
    delay(25);
    gotoxy(60, 7);
    cout << " ";
    delay(25);
    gotoxy(64, 6);
    cout << 'o';
    delay(25);
    gotoxy(64, 6);
    cout << 'C';
    delay(25);
    gotoxy(66, 5);
    cout << 'o';
    delay(25);
    gotoxy(66, 5);
    cout << " ";
    delay(25);
    gotoxy(68, 4);
    cout << 'o';
    delay(25);
    gotoxy(68, 4);
    cout << " ";
    gotoxy(60, 7);
    cout << '-';
    gotoxy(56, 7);
    cout << '-';
    gotoxy(55, 7);
    cout << '-';
    gotoxy(66, 5);
    cout << '_';
    for (int i = 0; i <= 7; i++) {
        //sound(100);
        delay(30);
        //nosound();
        //sound(800 * i);
        delay(50);
        //nosound();
    }

}
void fourR() {                           //////FOUR  RIGHT
    int i; char ch = 92;
    for (i = 1; i <= 10; i++) {
        gotoxy(45 + i, 17 - i);
        cout << 'o';
        delay(30);
        gotoxy(45 + i, 17 - i);
        cout << " ";
        delay(30);
        gotoxy(37, 15);
        cout << ')';
        if (i == 4) {
            gotoxy(49, 13);
            cout << ch;
        }
    }
    gotoxy(30, 7);
    cout << '-';
}
void bowled() {                                 ///BOWLEDDD
    char c = 92;
    gotoxy(41, 18);
    cout << "     ";
    gotoxy(39, 19);
    cout << c << "   |   /";
    gotoxy(40, 20);
    cout << c << "  |  " << '/';
    gotoxy(41, 21);
    cout << c << " | /";
    delay(1000);
    gotoxy(35, 15);
    cout << "(~)_";
    gotoxy(35, 16);
    cout << "/ |";
    gotoxy(34, 17);
    cout << "|   =";
    gotoxy(34, 18);
    cout << "|  | ";
    gotoxy(35, 19);
    cout << "| | ";
    gotoxy(35, 20);
    cout << "| |";
    gotoxy(39, 17);
    cout << "!";
    char ch = 219;
    gotoxy(39, 18);
    cout << ch;
    gotoxy(39, 19);
    cout << ch;
    gotoxy(39, 20);
    cout << ch;
    gotoxy(36, 21);
    cout << "^^";
    gotoxy(41, 19);
    cout << "| | |";
    gotoxy(47, 19);
    cout << " ";
    gotoxy(41, 20);
    cout << "| | |";
    gotoxy(46, 20);
    cout << " ";
    gotoxy(41, 21);
    cout << "| | |";
    gotoxy(41, 18);
    cout << " _ _";
    gotoxy(40, 20);
    cout << " ";
    for (int i = 0; i <= 100; i++) {
        //sound(500 - 8 * i);
        delay(20);
        //nosound();
    }


}
void caughtSLR() {                                 ////caught SLR
    char ch = 92;
    gotoxy(48, 15);
    cout << 'o';
    delay(40);
    gotoxy(48, 15);
    cout << " ";
    delay(40);
    gotoxy(49, 14);
    cout << 'o';
    delay(40);
    gotoxy(49, 14);
    cout << " ";
    delay(40);
    gotoxy(50, 14);
    cout << ch;
    delay(40);
    for (int i = 1; i <= 8; i++) {
        gotoxy(50 + i, 14);
        cout << 'o';
        delay(10);
        gotoxy(50 + i, 14);
        cout << " ";
    }
    gotoxy(60, 15);
    cout << 'o';
    delay(40);
    gotoxy(60, 16);
    cout << "`-";
    delay(500);
    gotoxy(60, 15);
    cout << " ";
    gotoxy(60, 16);
    cout << "  ";
    gotoxy(61, 16);
    cout << "!";
    for (int k = 0; k <= 100; k++) {
        //sound(500 - 8 * k);
        delay(20);
        //nosound();
    }



}
void caughtSLL() {                             /////caught SLL
    gotoxy(38, 15);
    cout << 'o';
    delay(40);
    gotoxy(38, 15);
    cout << " ";
    delay(30);
    gotoxy(37, 14);
    cout << 'o';
    delay(20);
    gotoxy(37, 14);
    cout << " ";
    for (int i = 0; i <= 19; i++) {
        gotoxy(36 - i, 14);
        cout << 'o';
        delay(7);
        if (i == 0) {
            gotoxy(36, 14);
            cout << '/';
        }
        if (i != 0) {
            gotoxy(36 - i, 14);
            cout << " ";
        }
    }
    gotoxy(17, 15);
    cout << 'o';
    delay(30);
    gotoxy(17, 16);
    cout << "`-";
    delay(500);
    gotoxy(17, 15);
    cout << " ";
    gotoxy(17, 16);
    cout << "  ";
    gotoxy(18, 16);
    cout << "!";
    for (int l = 0; l <= 100; l++) {
        //sound(500 - 8 * l);
        delay(20);
        //nosound();
    }
}


void caughtLR() {                                  ////caught long off
    gotoxy(50, 12);
    cout << 'o';
    delay(45);
    gotoxy(50, 12);
    cout << " ";
    delay(45);
    gotoxy(55, 11);
    cout << 'o';
    delay(60);
    gotoxy(55, 11);
    cout << " ";
    delay(60);
    gotoxy(62, 8);
    cout << 'o';
    delay(60);
    gotoxy(62, 9);
    cout << "`-";
    delay(500);
    gotoxy(62, 8);
    cout << " ";
    gotoxy(62, 9);
    cout << "  ";
    gotoxy(63, 9);
    cout << "!";
    for (int i = 0; i <= 100; i++) {
        //sound(500 - 8 * i);
        delay(20);
        //nosound();
    }
}

void caughtLL() {                                 /////caught Long onn
    gotoxy(40, 12);
    cout << 'o';
    delay(70);
    gotoxy(40, 12);
    cout << " ";
    delay(70);
    gotoxy(35, 11);
    cout << 'o';
    delay(70);
    gotoxy(35, 11);
    cout << " ";
    delay(70);
    gotoxy(25, 8);
    cout << 'o';
    delay(70);
    gotoxy(25, 8);
    cout << " ";
    delay(70);
    gotoxy(20, 9);
    cout << "`-";
    gotoxy(20, 8);
    cout << 'o';
    gotoxy(22, 8);
    cout << '@';
    gotoxy(23, 8);
    cout << " ";
    delay(500);
    gotoxy(22, 8);
    cout << " @";
    gotoxy(20, 9);
    cout << "  ";
    gotoxy(21, 9);
    cout << '!';
    gotoxy(20, 8);
    cout << " ";
    for (int i = 0; i <= 100; i++){
        //sound(500 - 8 * i);
        delay(20);
        //nosound();
    }
}

void fourOF() {                                   ////four off
    gotoxy(54, 15);
    cout << 'o';
    delay(50);
    gotoxy(54, 15);
    cout << " ";
    delay(50);
    gotoxy(57, 14);
    cout << 'o';
    delay(50);
    gotoxy(57, 14);
    cout << " ";
    delay(50);
    gotoxy(60, 13);
    cout << 'o';
    delay(50);
    gotoxy(60, 13);
    cout << " ";
    delay(50);
    gotoxy(63, 12);
    cout << 'o';
    delay(50);
    gotoxy(63, 12);
    cout << " ";
    delay(50);
    gotoxy(66, 11);
    cout << 'o';
    delay(50);
    gotoxy(66, 11);
    cout << " ";
    delay(50);
    gotoxy(69, 10);
    cout << 'o';
    delay(50);
    gotoxy(69, 10);
    cout << " ";
    delay(50);
    gotoxy(72, 9);
    cout << 'o';
    delay(50);
    gotoxy(72, 9);
    cout << " ";
    delay(50);
    gotoxy(74, 8);
    cout << 'o';
    delay(50);
    gotoxy(74, 8);
    cout << " ";
    delay(50);
    gotoxy(76, 7);
    cout << 'o';
    delay(50);
    gotoxy(76, 7);
    cout << '-';
    delay(50);
    gotoxy(78, 6);
    cout << 'o';
    delay(50);
    gotoxy(78, 6);
    cout << " ";
}
void TwoOFF() {                          ////////TWO OFF
    gotoxy(54, 15);
    cout << 'o';
    delay(50);
    gotoxy(54, 15);
    cout << " ";
    delay(50);
    gotoxy(57, 14);
    cout << 'o';
    delay(50);
    gotoxy(57, 14);
    cout << " ";
    delay(50);
    gotoxy(60, 13);
    cout << 'o';
    delay(50);
    gotoxy(60, 13);
    cout << " ";
    delay(50);
    gotoxy(63, 12);
    cout << 'o';
    delay(50);
    gotoxy(63, 12);
    cout << " ";
    delay(50);
    gotoxy(66, 11);
    cout << 'o';
    delay(50);
    gotoxy(66, 11);
    cout << " ";
    delay(50);
    gotoxy(69, 10);
    cout << 'o';
    delay(50);
    gotoxy(69, 10);
    cout << " ";
    delay(1000);
}
void OneOFF() {
    gotoxy(54, 15);
    cout << 'o';
    delay(50);
    gotoxy(54, 15);
    cout << " ";
    delay(50);
    gotoxy(57, 14);
    cout << 'o';
    delay(50);
    gotoxy(57, 14);
    cout << " ";
    delay(50);
    gotoxy(60, 13);
    cout << 'o';
    delay(50);
    gotoxy(60, 13);
    cout << " ";
    delay(50);
    gotoxy(63, 12);
    cout << 'o';
    delay(50);
    gotoxy(63, 12);
    cout << " ";
    delay(50);
    gotoxy(66, 11);
    delay(1000);
}
void fourON() {                                     ////FOUR ON side
    gotoxy(37, 15);
    cout << 'o';
    delay(50);
    gotoxy(37, 15);
    cout << ')';
    delay(50);
    gotoxy(34, 14);
    cout << 'o';
    delay(50);
    gotoxy(34, 14);
    cout << " ";
    delay(50);
    gotoxy(31, 13);
    cout << 'o';
    delay(50);
    gotoxy(31, 13);
    cout << " ";
    delay(50);
    gotoxy(28, 12);
    cout << 'o';
    delay(50);
    gotoxy(28, 12);
    cout << " ";
    delay(50);
    gotoxy(25, 11);
    cout << 'o';
    delay(50);
    gotoxy(25, 11);
    cout << " ";
    delay(50);
    gotoxy(21, 10);
    cout << 'o';
    delay(50);
    gotoxy(21, 10);
    cout << " ";
    delay(50);
    gotoxy(17, 9);
    cout << 'o';
    delay(50);
    gotoxy(17, 9);
    cout << " ";
    delay(50);
    gotoxy(16, 8);
    cout << 'o';
    delay(50);
    gotoxy(16, 8);
    cout << " ";
    delay(50);
    gotoxy(12, 7);
    cout << 'o';
    delay(50);
    gotoxy(12, 7);
    cout << '-';
    delay(50);
    gotoxy(9, 6);
    cout << 'o';
    delay(50);
    gotoxy(9, 6);
    cout << " ";
}
void TwoON() {
    gotoxy(37, 15);
    cout << 'o';
    delay(50);
    gotoxy(37, 15);
    cout << ')';
    delay(50);
    gotoxy(34, 14);
    cout << 'o';
    delay(50);
    gotoxy(34, 14);
    cout << " ";
    delay(50);
    gotoxy(31, 13);
    cout << 'o';
    delay(50);
    gotoxy(31, 13);
    cout << " ";
    delay(50);
    gotoxy(28, 12);
    cout << 'o';
    delay(50);
    gotoxy(28, 12);
    cout << " ";
    delay(50);
    gotoxy(25, 11);
    cout << 'o';
    delay(50);
    gotoxy(25, 11);
    cout << " ";
    delay(50);
    gotoxy(21, 10);
    cout << 'o';
    delay(50);
    gotoxy(21, 10);
    cout << " ";
    delay(50);
    gotoxy(17, 9);
    cout << 'o';
    delay(50);
    gotoxy(17, 9);
    cout << " ";
    delay(1000);
}
void OneON() {
    gotoxy(37, 15);
    cout << 'o';
    delay(50);
    gotoxy(37, 15);
    cout << ')';
    delay(50);
    gotoxy(34, 14);
    cout << 'o';
    delay(50);
    gotoxy(34, 14);
    cout << " ";
    delay(50);
    gotoxy(31, 13);
    cout << 'o';
    delay(50);
    gotoxy(31, 13);
    cout << " ";
    delay(50);
    gotoxy(28, 12);
    cout << 'o';
    delay(50);
    gotoxy(28, 12);
    cout << " ";
    delay(1000);
}

int Wicket = 0;
int Run = 0;
void PlayA() {
    Inswing();
    //textcolor(YELLOW);
    char m; int a, t = 0;
    t = kbhit();
    if (t != 0) {
        m = getch();
        if (m == 'A' || m == 'a') {
            a = random(5);
            switch (a) {
                case 0: BatL(); sixL();   Run += 6; gotoxy(55, 24); cprintf("SIX RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........."); break;
                case 1: BatL(); fourL();  Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........."); break;
                case 2: BatL(); fourON(); Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........."); break;
                case 3: BatL(); TwoON();  Run += 2; gotoxy(55, 24); cprintf("TWO RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........."); break;
                case 4: BatL(); sixL();   Run += 6; gotoxy(55, 24); cprintf("SIX RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........."); break;
            }
        }
        if (m == 'w' || m == 'W') {
            a = random(5);
            switch (a) {
                case 0: BatL(); bowled();    Wicket++; gotoxy(55, 24); cprintf("BOWLED");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 1: BatL(); TwoON();     Run += 2; gotoxy(55, 24); cprintf("TWO RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 2: BatL(); caughtSLL(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 3: BatL(); caughtLL();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 4: BatL(); OneON();     Run += 1; gotoxy(55, 24); cprintf("ONE RUN");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
        if (m == 'd' || m == 'D') {
            a = random(5);
            switch (a) {
                case 0: BatR(); bowled();    Wicket++; gotoxy(55, 24); cprintf("BOWLED");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 1: BatR(); TwoOFF();    Run += 2; gotoxy(55, 24); cprintf("TWO RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 2: BatR(); caughtSLR(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 3: BatR(); caughtLR();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 4: BatR(); OneOFF();    Run += 1; gotoxy(55, 24); cprintf("ONE RUN");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
    }
    else
        delay(1000);
}

void PlayW() {
    Sbowling();
    char m; int d, t = 0;
    //textcolor(YELLOW);
    t = kbhit();
    if (t != 0) {
        m = getch();
        if (m == 'w' || m == 'W') {
            d = random(4);
            switch (d) {
                case 0:BatL(); sixR();   Run += 6; gotoxy(55, 24); cprintf("SIX RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
                case 1:BatL(); fourR();  Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2:BatL(); fourOF(); Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 3:BatL(); sixL();   Run += 6; gotoxy(55, 24); cprintf("SIX RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
        if (m == 'd' || m == 'D') {
            d = random(5);
            switch (d) {
            	case 0: BatR(); bowled();    Wicket++; gotoxy(55, 24); cprintf("BOWLED");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 1: BatR(); fourOF();    Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2: BatR(); caughtSLR(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 3: BatR(); caughtLR();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 4: BatR(); TwoOFF();    Run += 2; gotoxy(55, 24); cprintf("TWO RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
        if (m == 'a' || m == 'A') {
            d = random(5);
            switch (d) {
            	case 0: BatL(); fourON();    Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 1: BatL(); fourL();     Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2: BatL(); caughtSLL(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 3: BatL(); caughtLL();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 4: BatL(); TwoON();     Run += 2; gotoxy(55, 24); cprintf("TWO RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
    }
    else {
        bowled(); Wicket++;
        delay(1000);
    }
}

void PlayD() {
    Outswing();
    char m; int d, t = 0;
    //textcolor(YELLOW);
    t = kbhit();
    if (t != 0) {
        m = getch();
        if (m == 'd' || m == 'D') {
            d = random(4);
            switch (d) {
            	case 0:BatR(); sixR();   Run += 6; gotoxy(55, 24); cprintf("SIX RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 1:BatR(); fourR();  Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2:BatR(); fourOF(); Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 3:BatR(); TwoOFF(); Run += 2; gotoxy(55, 24); cprintf("TWO RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
        if (m == 'w' || m == 'W') {
            d = random(5);
            switch (d) {
            	case 0: BatL(); bowled();    Wicket++; gotoxy(55, 24); cprintf("BOWLED");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 1: BatL(); fourL();     Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2: BatL(); caughtSLL(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 3: BatL(); caughtLL();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 4: BatL(); TwoON();     Run += 2; gotoxy(55, 24); cprintf("TWO RUNS");  delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
        if (m == 'a' || m == 'A') {
            d = random(5);
            switch (d) {
            	case 0: BatL(); bowled();    Wicket++; gotoxy(55, 24); cprintf("BOWLED");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 1: BatL(); fourON();    Run += 4; gotoxy(55, 24); cprintf("FOUR RUNS"); delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 2: BatL(); caughtSLL(); Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
           		case 3: BatL(); caughtLL();  Wicket++; gotoxy(55, 24); cprintf("CAUGHT");    delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            	case 4: BatL(); OneON();     Run += 1; gotoxy(55, 24); cprintf("ONE RUN");   delay(700); gotoxy(55, 24); /*textcolor(BLACK);*/ cprintf("........"); break;
            }
        }
    }
    else
		delay(1000);
}
void HPT() {
    system("cls");
    int i;
    for (i = 1; i <= 78; i++) {
        gotoxy(i, 1);
        cout << '*';
        delay(12);

    }
    for (i = 1; i <= 24; i++) {
        gotoxy(78, i);
        cout << '*';
        delay(12);
    }
    for (i = 78; i >= 1; i--) {
        gotoxy(i, 24);
        cout << '*';
        delay(12);
    }
    for (i = 24; i >= 1; i--) {
        gotoxy(1, i);
        cout << '*';
        delay(12);
    }
    for (int t = 25; t <= 38; t++) {
        gotoxy(t, 4);
        cout << '~';
        delay(20);
    }
    delay(100);
    gotoxy(25, 3);
    cout << "HOW TO PLAY??";
    delay(700);
    gotoxy(15, 7);
    cout << "-> PRESS W FOR STARIGHT DRIVE";
    delay(700);
    gotoxy(15, 10);
    cout << "-> PRESS A FOR ON DRIVE";
    delay(700);
    gotoxy(15, 13);
    cout << "-> PRESS D FOR OFF DRIVE";
    gotoxy(15, 16);
    cout << "-> PRESS ANY KEY FOR MENU";
    getch();
}
void D() {
    system("cls");
    int i;
    for (i = 1; i <= 78; i++) {
        gotoxy(i, 1);
        cout << '*';
        delay(12);

    }
    for (i = 1; i <= 24; i++) {
        gotoxy(78, i);
        cout << '*';
        delay(12);
    }
    for (i = 78; i >= 1; i--) {
        gotoxy(i, 24);
        cout << '*';
        delay(12);
    }
    for (i = 24; i >= 1; i--) {
        gotoxy(1, i);
        cout << '*';
        delay(12);
    }
    for (int t = 25; t <= 51; t++) {
        gotoxy(t, 4);
        cout << '~';
        delay(20);
    }
    delay(100);
    gotoxy(25, 3);
    cout << "WELCOME TO CRICKET CUP 2017";
    delay(700);
    gotoxy(15, 7);
    cout << "-> QUICK PLAY  (PRESS 'a') ";
    delay(700);
    gotoxy(15, 9);
    cout << "-> HOW TO PLAY??  (PRESS 'b')";
    delay(700);
    gotoxy(15, 11);
    cout << "-> QUIT  (PRESS 'c') ";
    delay(700);
    for (int k = 1; k <= 3; k++) {
        gotoxy(51, k + 10);
        cout << '|';
        delay(38);
        gotoxy(52, k + 10);
        cout << '|';
    }
    gotoxy(50, 13);
    cout << '_';
    gotoxy(53, 13);
    cout << '_';
    gotoxy(45, 10);
    for (int l = 1; l <= 9; l++) {
        gotoxy(49, 13 + l);
        cout << '|';
        gotoxy(54, 13 + l);
        cout << '|';
        delay(38);
    }
    for (int m = 1; m <= 4; m++) {
        gotoxy(49 + m, 22);
        cout << '_';
    }
    delay(38);
    gotoxy(59, 17);
    cout << "(_)";
    gotoxy(60, 16);
    cout << '_';
}
void scoreboard() {
    gotoxy(1, 23);
    cout << "~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~";
    gotoxy(1, 24);
    cout << "            |                                 |                      ";
    gotoxy(1, 25);
    cout << "            |                                 |                      ";

}
void GAME() {
    Bscreen();
    scoreboard();
    int s = 1;
    int k;
    int p = 1;
    gotoxy(8, 24);
    cout << "/ " << Wicket;
    gotoxy(5, 24);
    cout << Run;
    gotoxy(17, 24);
    cout << "OVERS: " << 0 << '.' << 0;
    gotoxy(31, 24);
    cout << "RUN RATE: " << 0;
    while (s <= 12) {                                       //overr set
        if (Wicket == 10)
            break;
        k = random(3);
        switch (k) {
        	case 0:PlayA(); break;
        	case 1:PlayW(); break;
        	case 2:PlayD(); break;
        }
        if (p == 6)
            p = 0;
        gotoxy(8, 24);
        cout << "/ " << Wicket;
        gotoxy(5, 24);
        cout << Run;
        gotoxy(17, 24);
        cout << "OVERS: " << (s / 6) << '.' << p;
        p++;
        if (s % 6 == 0)
            p = 1;
        gotoxy(31, 24);
        cout << "RUN RATE: " << (float)(Run) * (6) / (s);
        s++;
    }
}

void GP() {
A:
    D();
    char C;
    C = getch();
    switch (C) {
    	case 'a': GAME(); break;
    	case 'b': HPT(); goto A;
    	case 'c': exit(0); break;
    }
}

//=============================== MAIN =====================================//

int main() {
    int k;
    char ch = 'H';
    system("cls");
    Design();
    getch();
    while (ch == 'h' || ch == 'H') {
        k = Choice(); {
            if (k == 1)
                Add();
            else if (k == 2)
                ufn();
            else if (k == 3)
                edit();
            else if (k == 4)
                Delete();
            else if (k == 5)
                analysis();
            else if (k == 6)
                profilebyjn();
            else if (k == 7)
                profilebyname();
            else if (k == 8)
                rankingbyruns();
            else if (k == 9)
                rankingbywickts();
            else if (k == 10)
                news();
            else if (k == 11)
                start();
            else if (k == 12)
                showall();
            else if (k == 13)
                GP();
            else if (k == 14)
            {
                cout << "Thanks for visiting Hall of Fame of cricket. ";
                exit(0);
            }
            else
                cout << "Please Enter the Number between 1 to 13 only. ";
        }
        gotoxy(3, 23);
        cout << "If you want to go to Home Page Press H" << endl;
        cin >> ch;
    }
	return 0;
}
