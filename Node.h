#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


class NODE{
friend void bubbleSortByTimeLL(NODE*& head);
friend void removePastLL(NODE*& head);
protected:    
    int year;
    NODE* next;
public:
      NODE(int=111);
      virtual void display();
      void insert(NODE*&);
      NODE* move_next();
      virtual ~NODE();

      void set_next(NODE* n) { next = n; }
    };

NODE::NODE(int x){
        year=x;
        next=NULL;
        cout<<"NODE constructor "<< x <<endl;
  }
NODE:: ~NODE(){
        cout<<"NODE destructor "<< year <<endl;
        cout<<"-------"<<endl;
  }
NODE* NODE::move_next(){
        return next;
  }
void  NODE:: display(){
           cout<<"NODE:"<<year<<endl;
   }
void NODE::insert(NODE*& x){
       x->next=this;
  
       }

#endif