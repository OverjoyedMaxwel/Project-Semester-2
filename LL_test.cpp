#include <iostream>
#include<cstdlib>
//#include"STD_NODE.h"
//#include "student.h"
#include"LL.h"
#include "student.h"
using namespace std;
int main(int argc, char *argv[])
{  LL A;
   int i;
   NODE *t;

   for(i=1;i<argc;i+=4) {
                    string n=argv[i+2];   
                    t=new student(atoi(argv[i]),atoi(argv[i+1]),atof(argv[i+2]),n);
                    A.add_node(t);
                       }
   A.show_all();
   //highestGPA(t);
    return 0;
}