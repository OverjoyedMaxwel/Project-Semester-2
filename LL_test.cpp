#include <iostream>
#include<cstdlib>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <unistd.h>
#include "Choice.h"
using namespace std;
void gotoxy( short, short);
void main_menu();
void drawFrame(int x, int y, int width, int height);
int main(int argc, char *argv[])
{  //main_menu();
    while(true){
        char choice;
        system("clear");
        cout.flush();     
        
        main_menu();
        cin.get();  
        
        system("clear");  
        cout.flush();
        
        drawFrame(30, 1, 50, 11);
        
        gotoxy(36,2);
        cout << "Type \"0\" = Write to file[argv]" << endl; 
        gotoxy(36,3);
        cout << "\"1\" = Write to file[cin]" << endl;
        gotoxy(36,4); 
        cout << "\"2\" = Read to file" << endl;
        gotoxy(36,5);
        cout << "\"3\" = Delete All files Data" << endl;
        gotoxy(36,6);
        cout << "\"4\" = BubbleSort Descending[vector<Data>]" << endl;
        gotoxy(36,7);
        cout << "\"5\" = Homework Reminder[vector<Data>]" <<endl ;
        gotoxy(36,8);
        cout << "\"6\" = Delete 1 file Data" <<endl ;
        gotoxy(36,9);
        cout << "\"7\" = Homework Reminder[Linklist]" <<endl ;
        gotoxy(36,10);
        cout << "\"8\" = Exit program" <<endl; 
        gotoxy(36,12);
        cout << "Input: " ;
        cin >> choice ;
        
        system("clear");
        cout.flush();
        //sleep(1);

        processChoice(choice, argc, argv);
        cin.ignore();
        cin.get();
        
        //system("clear");
        //cout.flush();
        
         if(choice=='8')
            {
            break;
            }
    }
    
    return 0;
}
void main_menu()
{
    gotoxy(1,1);
    cout << R"(
  _   _                                         _                         _           _       
 | | | | ___  _ __ ___   _____      _____  _ __| | __  _ __ ___ _ __ ___ (_)_ __   __| | ___ _ __ 
 | |_| |/ _ \| '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ / | '__/ _ \ '_ ` _ \| | '_ \ / _` |/ _ \ '__
 |  _  | (_) | | | | | |  __/\ V  V / (_) | |  |   <  | | |  __/ | | | | | | | | | (_| |  __/ | 
 |_| |_|\___/|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\ |_|  \___|_| |_| |_|_|_| |_|\__,_|\___|_| 
                                                                                                  
    )" << endl;
}

void drawFrame(int x, int y, int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // สมมติวาดเส้นขอบ
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

void gotoxy( short x, short y ) 
{ 
    std::cout << "\033[" << y << ";" << x << "H";
    /*HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
    COORD position = { x, y } ; 
     
    SetConsoleCursorPosition( hStdout, position ) ;*/ 
}  