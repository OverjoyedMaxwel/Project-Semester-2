//#include "Thai_person.h"
#include "Node.h"

class Month:public NODE{
private: 
  long month;
	//string name;
  
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
Month::Month(long n1,long x,string n):NODE(n1){
   	  // Set up all MU_Person values
      //cout<<NODE::id;
      month = x;
      name = n;   
      cout<<"MONTH constructor "<<month<<endl;
}

void Month::display(){
      //display_thai();
      //show_node();
      cout<<"NAME:"<<name<<endl;
      cout<<"YEAR:";
      cout<<NODE::year<<endl;
      cout<<"MONTH:"<<month<<endl;
      
}
