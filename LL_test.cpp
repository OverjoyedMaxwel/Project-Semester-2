#include <iostream>
#include<cstdlib>
#include <fstream>
//#include"STD_NODE.h"
//#include "student.h"
#include"LL.h"
//#include "student.h"
#include "Time.h"
using namespace std;
int main(int argc, char *argv[])
{  
   int choice;
   cout << "Type \"0\" = Write to file[argv] \"1\" = Write to file[cin] \"2\" = Read to file \"3\" = Delete file Data"<< endl ;
   cin >> choice ;
   
   if(choice == 0){   
      ofstream fout("demo4.txt", ios::app);
      if (fout) {  
      
       cout << "Successfully writing to text file." << endl;
       for (int i = 1; i < argc; i+=7) {
            string n=argv[i+3];
          fout << atoi(argv[i]) <<" "<< atoi(argv[i+1]) <<" "<<  atoi(argv[i+2]) <<" "<< n <<" "
          << atoi(argv[i+4]) << " " << atoi(argv[i+5]) << " " << atoi(argv[i+6]) << " " ;
       }
 
       fout << endl;
      } else {
         cout << "Error opening file!" << endl;
      }
      fout.close();   
   }
   
   else if(choice == 1){   
      ofstream fout("demo4.txt", ios::app);
      if (fout) {  
          cout << "Successfully writing to file." << endl;
  
          int n;
          cout << "Enter number of homework: ";
          cin >> n;
  
          for (int i = 0; i < n; ++i) {
              
            int year, month, day;
            int hour, minute, second;
              float gpa;
              string name;
  
              cout << "Enter Year: ";
              cin >> year;
              cout << "Enter Month: ";
              cin >> month;
              cout << "Enter Day: ";
              cin >> day;
              cout << "Enter Homework Name: ";
              cin >> name;
              cout << "Enter Hour,Minute,Second: ";
              cin >> hour >> minute >> second;
              
  
              fout << year << " " << month << " " << day << " " << name << " " 
              << hour << " " << minute << " " << second << " ";
          }
  
          fout << endl;
      } else {
          cerr << "Error opening file!" << endl;
      }
      fout.close();   
  }

   else if(choice == 2){
      ifstream fin("demo4.txt");
      if (!fin) {
         cerr << "Cannot open demo4.txt" << endl;
         return 1;
      }
      cout << "Successfully read to text file." << endl;
      LL A;
      NODE *t;

      int year, month, day;
      int hour, minute, second;
      float gpa;
      string name;

       // อ่านข้อมูลทีละ 4 ค่า (int, int, float, string)
      while (fin >> year >> month >> day >> name >> hour >> minute >> second) {
          t = new Time(year, month, day, name, hour, minute, second);
          A.add_node(t);
      }

      A.show_all();
      // highestGPA(t);  // ถ้าคุณมีฟังก์ชันนี้
      
      fin.close();
    
   } 
   
   else if (choice == 3) {
      ofstream fout("demo4.txt", ios::trunc); // ล้างไฟล์
      if (fout) {
          cout << "File cleared successfully." << endl;
      } else {
          cerr << "Failed to clear file." << endl;
      }
      fout.close();
  }
  return 0;
}