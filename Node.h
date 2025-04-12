#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


class NODE{
protected:    
    int id;
    NODE* next;
public:
      NODE(int=111);
      virtual void display();
      void insert(NODE*&);
      NODE* move_next();
      virtual ~NODE();
    };

NODE::NODE(int x){
        id=x;
        next=NULL;
        cout<<"adding "<< x<<endl;
  }
NODE:: ~NODE(){
        cout<<"Node "<<id<<" is being deleted"<<endl;
        cout<<"-------"<<endl;
  }
NODE* NODE::move_next(){
        return next;
  }
void  NODE:: display(){
           cout<<"Node data:"<<id<<endl;
   }
void NODE::insert(NODE*& x){
       x->next=this;
  
       }

#endif