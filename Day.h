
#include "Month.h"


class Day:public Month{
private:
          long day; 
	
public:
    Day(long=0,long=111 ,long=2,string="Nattawut");
    ~Day();
    void display(); // display_person
   
};

Day::Day(long n1,long i, long g,string s):Month(n1,i,s){
// Finish constructor to set all values
    //id = i;
    //name = s;
    day= g;         
    cout<<"DAY constructor  "<<day<<endl;
    //cout<<"-------"<<endl;
         
  
}
Day::~Day(){
     //cout<<"-------"<<endl;
     cout<<"DAY destructor "<<day<<endl; 
     //cout<<"-------"<<endl;
}


void Day::display(){
  //Finish Display function
    //cout<<"ID:"<<id<<" name:"<<name<<" gpa:"<<gpa<<endl;
    //display_person();
    //display_thai();
    Month::display();
    cout<<"DAY:"<<day<<endl;
    //cout<<"-------"<<endl;
}

