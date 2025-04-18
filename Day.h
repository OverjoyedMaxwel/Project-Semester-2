
#include "Month.h"


class Day:public Month{
protected:
          long day; 
	
public:
    Day(long=0,long=0 ,long=0,string="Math");
    ~Day();
    void display(); // display_person
   
};

Day::Day(long year,long mon, long d,string s):Month(year,mon,s){
    day= d;         
    cout<<"DAY constructor "<<day<<endl;

}
Day::~Day(){

     cout<<"DAY destructor "<<day<<endl; 

}


void Day::display(){
    Month::display();
    cout<<"DAY:"<<day<<endl;
}

