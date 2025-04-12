#include "MU_Person.h"


class student:public MU_person{
private:
          double gpa; 
	
public:
    student(long=0,long=111 ,double=2.5,string="Nattawut");
    ~student();
    void display(); // display_person
   
};

student::student(long n1,long i, double g,string s):MU_person(n1,i,s){
// Finish constructor to set all values
    //id = i;
    //name = s;
    gpa= g;         
    cout<<"MU student constructor  "<<gpa<<endl;
         
  
}
student::~student(){
     cout<<"-------"<<endl;
     cout<<"student destructor "<<gpa<<endl; 
}


void student::display(){
  //Finish Display function
    //cout<<"ID:"<<id<<" name:"<<name<<" gpa:"<<gpa<<endl;
    //display_person();
    //display_thai();
    MU_person::display();
    cout<<"GPA:"<<gpa<<endl;
}

