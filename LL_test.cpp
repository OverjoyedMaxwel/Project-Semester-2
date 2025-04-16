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
   cout << "Type \"0\" = Write to file[argv]" << endl << "\"1\" = Write to file[cin]"
   << endl << "\"2\" = Read to file" << endl << "\"3\" = Delete file Data"
   << endl << "\"4\" = BubbleSort Descending" << endl << "\"5\" = Homework Reminder" <<endl ;
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
    cout << R"(
  _   _                                         _                         _           _       
 | | | | ___  _ __ ___   _____      _____  _ __| | __  _ __ ___ _ __ ___ (_)_ __   __| | ___ _ __ 
 | |_| |/ _ \| '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ / | '__/ _ \ '_ ` _ \| | '_ \ / _` |/ _ \ '__
 |  _  | (_) | | | | | |  __/\ V  V / (_) | |  |   <  | | |  __/ | | | | | | | | | (_| |  __/ | 
 |_| |_|\___/|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\ |_|  \___|_| |_| |_|_|_| |_|\__,_|\___|_| 
                                                                                                  
    )" << endl << "Press enter to continue";
}