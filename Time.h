#include <iostream>
using namespace std;

class Time{
private:	
    int m,h,s;

public:
    void set_time(int=0,int=0,int=0);
    void display();
    void get_time();
    Time operator-(Time);

};

void Time::set_time(int a,int b,int c){
    /*
    h = (a>24)?0:a;
    m = (b>60)?0:b;
    s = (c>60)?0:c;
    */
    h=(a>0&&a<24)?a:0;
    m=(b>0 && b<60)?b:0;
    s=(c>0 && c<60)?c:0;
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
         << setfill('0') << setw(2) << h << ":" 
         << setfill('0') << setw(2) << m << ":" 
         << setfill('0') << setw(2) << s << endl;
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
    cout << setfill('0') << setw(2) << h << ":"
         << setfill('0') << setw(2) << m << ":"
         << setfill('0') << setw(2) << s << endl;
}

Time Time::operator-(Time x){
    
  
    Time t;

    t.h=0;
    t.m=0;
    t.s=0;
    

    
    t.s=this->s - x.s;
    if(t.s<0)
    {
        t.m=-1;
        t.s+=60;
    }
    t.m+=this->m - x.m;
    
    if(t.m<0)
    {
        t.h=-1;
        t.m+=60;

    }
    
    t.h+=this->h - x.h;
    
    if(t.h<0)
    {
        
        t.h+=24;

    }
    
    
    /*
    t.h= h - x.h;
    t.m=this->m - x.m;
    t.s=this->s - x.m;
    */   
        
    return t;
        



}