#include <iostream>
#include <iomanip>
#include "Day.h"
using namespace std;

class Time:public Day{
private:	
    int minute,hour,second;

public:
    void set_time(int=0,int=0,int=0);
    void display();
    void get_time();
    Time operator-(Time);
    Time(long=2025, long=12, long=30, string="Math", int=0, int=0, int=0);
    ~Time();
};

Time::Time(long year,long month, long day,string name,int h,int m,int sec):Day(year,month,day,name){
        hour = h;
        minute = m;
        second = sec;         
        cout<<"TIME constructor "<< setfill('0') << setw(2) << hour << ":" 
        << setfill('0') << setw(2) << minute << ":" 
        << setfill('0') << setw(2) << second << endl;
        cout<<"-------"<<endl;
    }

Time::~Time(){
     cout<<"TIME destructor "<< setfill('0') << setw(2) << hour << ":" 
     << setfill('0') << setw(2) << minute << ":" 
     << setfill('0') << setw(2) << second << endl; 
}

void Time::set_time(int a,int b,int c){
    hour=(a>0&&a<24)?a:0;
    minute=(b>0 && b<60)?b:0;
    second=(c>0 && c<60)?c:0;
}

//typedef struct Time* TimePtr;

void Time::get_time() {
    int a,b,c;
    cin >> a >> b >> c;
    set_time(a,b,c);

    cout << "TIME: " 
         << setfill('0') << setw(2) << hour << ":" 
         << setfill('0') << setw(2) << minute<< ":" 
         << setfill('0') << setw(2) << second << endl;
}

void Time::display() {
    Day::display();
    cout << "TIME:" << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << endl;
    cout<<"-------"<<endl;
}

Time Time::operator-(Time x){
    
  
    Time t;

    t.hour=0;
    t.minute=0;
    t.second=0;
    

    
    t.second=this->second - x.second;
    if(t.second<0)
    {
        t.minute=-1;
        t.second+=60;
    }
    t.minute+=this->minute - x.minute;
    
    if(t.minute<0)
    {
        t.hour=-1;
        t.minute+=60;

    }
    
    t.hour+=this->hour - x.hour;
    
    if(t.hour<0)
    {
        
        t.hour+=24;

    }
    
    
    /*
    t.h= h - x.h;
    t.m=this->m - x.m;
    t.s=this->s - x.m;
    */   
        
    return t;
        



}
