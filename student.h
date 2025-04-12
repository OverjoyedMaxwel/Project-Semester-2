#include "MU_Person.h"


class student:public MU_person{
private:
          long gpa; 
	
public:
    student(long=0,long=111 ,long=2,string="Nattawut");
    ~student();
    void display(); // display_person
   
};

student::student(long n1,long i, long g,string s):MU_person(n1,i,s){
// Finish constructor to set all values
    //id = i;
    //name = s;
    gpa= g;         
    cout<<"DAY constructor  "<<gpa<<endl;
    cout<<"-------"<<endl;
         
  
}
student::~student(){
     //cout<<"-------"<<endl;
     cout<<"DAY destructor "<<gpa<<endl; 
     cout<<"-------"<<endl;
}


void student::display(){
  //Finish Display function
    //cout<<"ID:"<<id<<" name:"<<name<<" gpa:"<<gpa<<endl;
    //display_person();
    //display_thai();
    MU_person::display();
    cout<<"DAY:"<<gpa<<endl;
    cout<<"-------"<<endl;
}

