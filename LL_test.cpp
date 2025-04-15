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

int main(int argc, char *argv[])
{  
   int choice;
   cout << "Type \"0\" = Write to file[argv]" << endl << "\"1\" = Write to file[cin]"
   << endl << "\"2\" = Read to file" << endl << "\"3\" = Delete file Data"
   << endl << "\"4\" = BubbleSort Descending" << endl << "\"5\" = Homework Reminder" <<endl ;
   cin >> choice ;
   
   processChoice(choice, argc, argv);
    return 0;
}