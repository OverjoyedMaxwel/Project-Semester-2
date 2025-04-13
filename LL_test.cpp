#include <iostream>
#include<cstdlib>
#include <fstream>
#include <vector>
//#include"STD_NODE.h"
//#include "student.h"
#include"LL.h"
//#include "student.h"
#include "Time.h"
#include "Data.h"
using namespace std;
int main(int argc, char *argv[])
{  
   int choice;
   cout << "Type \"0\" = Write to file[argv] \"1\" = Write to file[cin] \"2\" = Read to file"
   << " \"3\" = Delete file Data \"4\" = BubbleSort Data Descending" << endl ;
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

  else if (choice == 4) {
    ifstream fin("demo4.txt");
    if (!fin) {
        cerr << "Cannot open demo4.txt for reading." << endl;
        return 1;
    }

    vector<Data> dataList;
    Data temp;

    while (fin >> temp.year >> temp.month >> temp.day >> temp.name >> temp.hour >> temp.minute >> temp.second) {
        dataList.push_back(temp);
    }
    fin.close();

    // เรียงข้อมูล
    bubbleSort(dataList);

    // เขียนข้อมูลใหม่กลับไปในไฟล์ (เขียนทับ)
    ofstream fout("demo4.txt", ios::trunc);
    if (!fout) {
        cerr << "Cannot open demo4.txt for writing." << endl;
        return 1;
    }

    for (int i = 0; i < dataList.size(); ++i) {
        Data d = dataList[i];
        fout << d.year << " " << d.month << " " << d.day << " " 
             << d.name << " " << d.hour << " " << d.minute << " " << d.second << " ";
    }
    fout << endl;
    fout.close();

    cout << "Data sorted by time (descending) and updated in file." << endl;
}
  return 0;
}