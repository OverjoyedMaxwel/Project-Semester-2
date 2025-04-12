//#include <iostream>
//using namespace std;

//#include "Time.h"
#include <iomanip>
#include "student.h"

class Time:public student{
private:	
    int minute,hour,second;

public:
    void set_time(int=0,int=0,int=0);
    void display();
    void get_time();
    Time operator-(Time);
    Time(long=0,long=111 ,long=2,string="Nattawut",int=0 ,int=0, int=0);
    ~Time();
};

Time::Time(long n1,long i, long g,string s,int h,int m,int sec):student(n1,i,g,s){
    // Finish constructor to set all values
        //id = i;
        //name = s;
        hour = h;
        minute = m;
        second = sec;         
        cout<<"Time constructor  "<< setfill('0') << setw(2) << hour << ":" 
        << setfill('0') << setw(2) << minute << ":" 
        << setfill('0') << setw(2) << second << endl;
        cout<<"-------"<<endl;
             
      
    }

Time::~Time(){
     //cout<<"-------"<<endl;
     cout<<"TIME destructor "<< setfill('0') << setw(2) << hour << ":" 
     << setfill('0') << setw(2) << minute << ":" 
     << setfill('0') << setw(2) << second << endl; 
     
}

void Time::set_time(int a,int b,int c){
    /*
    h = (a>24)?0:a;
    m = (b>60)?0:b;
    s = (c>60)?0:c;
    */
    hour=(a>0&&a<24)?a:0;
    minute=(b>0 && b<60)?b:0;
    second=(c>0 && c<60)?c:0;
}

//typedef struct Time* TimePtr;

void Time::get_time() {
    int a,b,c;
    //cout << "\nEnter hours: ";
    cin >> a >> b >> c;
    
    //cout << "Enter minutes: ";
    //cin >> b;
    
    //cout << "Enter seconds: ";
    //cin >> c;
    set_time(a,b,c);

    

    // แสดงผลในรูปแบบ hh:mm:ss
    cout << "Time: " 
         << setfill('0') << setw(2) << hour << ":" 
         << setfill('0') << setw(2) << minute<< ":" 
         << setfill('0') << setw(2) << second << endl;
}

//create 3 functions
/*
//1.  getTime function
void getTime(Time* time) {
    cout << "\nEnter hours: ";
    cin >> time->h;
    cout << "Enter minutes: ";
    cin >> time->m;
    cout << "Enter seconds: ";
    cin >> time->s;

    // แสดงผลในรูปแบบ hh:mm:ss
    cout << "Time: " 
         << setfill('0') << setw(2) << time->h << ":" 
         << setfill('0') << setw(2) << time->m << ":" 
         << setfill('0') << setw(2) << time->s << endl;
}
//2. subtract fuctions
Time subtract(Time t1, Time t2)
{
	struct Time t3;
    int s1_sum, s2_sum, s3_sum;
    s1_sum = (t1.h)*3600 + (t1.m)*60 + (t1.s) ;
    s2_sum = (t2.h)*3600 + (t2.m)*60 + (t2.s) ;
    
    s3_sum = s2_sum - s1_sum;
    
    t3.h = s3_sum / 3600;
    t3.m = (s3_sum % 3600) / 60;
    t3.s = s3_sum % 60;
    return t3;
}
*/

//3. display functions
/*
void Time::display(Time* time) {
    cout << setfill('0') << setw(2) << time->h << ":"
         << setfill('0') << setw(2) << time->m << ":"
         << setfill('0') << setw(2) << time->s << endl;
}
*/


void Time::display() {
    student::display();
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
