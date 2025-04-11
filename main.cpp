#include <iostream>
using namespace std;
//#include "Thai_person.h"
#include "student.h"
//#include "Thai_person.h"

int main(){
  NODE *t;
  
  MU_person m(111,6713220,"Kanapod");
  m.display();
  m.NODE::display();
  t=&m;
  cout<<"Display t"<<endl;
  t->display();

  student s(222,6713221,2.5,"Naratip");
  s.display();
  s.MU_person::display();
  s.NODE::display();
  t=&s;
  cout<<"Display t"<<endl;
  t->display();

  t=new student(1123456,6713233,1.9,"Tanop");
  t->display();
  delete t;
//student m1(6613121,2,"Vivi"),m2(112),m3;
// student m1(6613118,3.9,"Atom");
//student m2(6613112),m3,*p;
//m1.display(); // id gpa name
  cout<<endl<<"======="<<endl;
//m1.display_person(); //id

//  p=new student(6613265,1.7,"Hok");
 // delete p;
  
  return 0;
   }

// Add constructor --> set name 
// modify display() -->id/name/gpa
