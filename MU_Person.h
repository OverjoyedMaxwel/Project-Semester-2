//#include "Thai_person.h"
#include "Node.h"

class MU_person:public NODE{
private: 
  long id;
	//string name;
  
protected:
  //long id;
	string name;

public:
	MU_person(long=0,long=112 ,string ="Prapaporn");
  void display();
  ~MU_person();
};



MU_person::~MU_person(){
  cout<<"Destructor month="<<id<<endl;
}
MU_person::MU_person(long n1,long x,string n):NODE(n1){
   	  // Set up all MU_Person values
      //cout<<NODE::id;
      id = x;
      name = n;   
      cout<<"MONTH constructor "<<id<<endl;
}

void MU_person::display(){
      //display_thai();
      //show_node();
      cout<<"MONTH:"<<id<<" NAME:"<<name<<endl;
      
      cout<<"YEAR:";
      cout<<NODE::id<<endl;
    
}
