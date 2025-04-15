#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


class NODE{
protected:    
    int year;
    NODE* next;
public:
      NODE(int=111);
      virtual void display();
      void insert(NODE*&);
      NODE* move_next();
      virtual ~NODE();
    };

NODE::NODE(int x){
        year=x;
        next=NULL;
        cout<<"adding "<< x<<endl;
  }
NODE:: ~NODE(){
        cout<<"Node "<<year<<" is being deleted"<<endl;
        cout<<"-------"<<endl;
  }
NODE* NODE::move_next(){
        return next;
  }
void  NODE:: display(){
           cout<<"Node data:"<<year<<endl;
   }
void NODE::insert(NODE*& x){
       x->next=this;
  
       }

#endif