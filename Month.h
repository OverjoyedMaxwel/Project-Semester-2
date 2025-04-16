#include "Node.h"

class Month:public NODE{
private: 
  long month;
  
protected:
  //long id;
	string name;

public:
	Month(long=0,long=112 ,string ="Prapaporn");
  void display();
  ~Month();
};



Month::~Month(){
  cout<<"MONTH destructor "<<month<<endl;
}
Month::Month(long year,long mon,string n):NODE(year){
      month = mon;
      name = n;   
      cout<<"MONTH constructor "<<month<<endl;
}

void Month::display(){
      cout<<"NAME:"<<name<<endl;
      cout<<"YEAR:";
      cout<<NODE::year<<endl;
      cout<<"MONTH:"<<month<<endl;
      
}
