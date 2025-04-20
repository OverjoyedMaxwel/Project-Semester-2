#include <iostream>
using namespace std;
#include"Node.h"

class LL{
      NODE* hol;
      int size;
public:
       void add_node(NODE*&);
       void show_all();
    
       ~LL();
       LL();

       NODE*& getHol() {
        return hol;
      }
      
};

LL::LL(){
    hol=NULL;
    size=0;
}

LL::~LL(){
       
  NODE* t=hol;
  while(hol){
       t=hol;
       hol=hol->move_next();
       delete t;
       size--;
  }
  //clear all nodes
}

void LL::show_all(){
  NODE* t=hol;
  int i;
  for(i=0;i<size;i++){
            t->display();
            t=t->move_next();
            /**
            complete this part
             */
  }
}
void LL::add_node(NODE* &A){

       hol->insert(A);
       hol=A;

    size++;

}
