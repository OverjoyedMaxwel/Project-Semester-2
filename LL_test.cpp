#include <iostream>
#include<cstdlib>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
//#include"STD_NODE.h"
//#include "student.h"
//#include"LL.h"
//#include "student.h"
//#include "Time.h"
//#include "Data.h"
#include "Choice.h"
using namespace std;
void main_menu();
int main(int argc, char *argv[])
{  main_menu();
    while(true){
   char choice;
   gotoxy(36,12);
   cout << "Type \"0\" = Write to file[argv]" << endl; 
   gotoxy(36,13);
   cout << "\"1\" = Write to file[cin]" << endl;
   gotoxy(36,14); 
   cout << "\"2\" = Read to file" << endl;
   gotoxy(36,15);
   cout << "\"3\" = Delete file Data" << endl;
   gotoxy(36,16);
   cout << "\"4\" = BubbleSort Descending" << endl;
   gotoxy(36,17);
   cout << "\"5\" = Homework Reminder" <<endl ;
   gotoxy(36,18);
   cin >> choice ;
   
   processChoice(choice, argc, argv);
    if(choice=='x')
        {
            break;
        }
    }
    
    return 0;
}
void main_menu()
{
    char x;
    gotoxy(1,3);
    cout << R"(
  _   _                                         _                         _           _       
 | | | | ___  _ __ ___   _____      _____  _ __| | __  _ __ ___ _ __ ___ (_)_ __   __| | ___ _ __ 
 | |_| |/ _ \| '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ / | '__/ _ \ '_ ` _ \| | '_ \ / _` |/ _ \ '__
 |  _  | (_) | | | | | |  __/\ V  V / (_) | |  |   <  | | |  __/ | | | | | | | | | (_| |  __/ | 
 |_| |_|\___/|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\ |_|  \___|_| |_| |_|_|_| |_|\__,_|\___|_| 
                                                                                                  
    )" << endl;
}