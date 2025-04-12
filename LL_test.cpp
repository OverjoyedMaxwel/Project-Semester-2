#include <iostream>
#include<cstdlib>
#include <fstream>
//#include"STD_NODE.h"
//#include "student.h"
#include"LL.h"
#include "student.h"
using namespace std;
int main(int argc, char *argv[])
{  
   int choice;
   cout << "Type \"1\" = Write to file[argv] \"2\" = Write to file[cin] \"3\" = Read to file \"4\" = Delete file Data"<< endl ;
   cin >> choice ;
   
   if(choice == 1){   
      ofstream fout("demo4.txt", ios::app);
      if (fout) {  
      
       cout << "Successfully writing to text file." << endl;
       for (int i = 1; i < argc; i+=4) {
            string n=argv[i+3];
          fout << atoi(argv[i]) <<" "<< atoi(argv[i+1]) <<" "<<  atof(argv[i+2]) <<" "<< n <<" ";
       }
 
       fout << endl;
      } else {
         cout << "Error opening file!" << endl;
      }
      fout.close();   
   }
   
   else if(choice == 2){   
      ofstream fout("demo4.txt", ios::app);
      if (fout) {  
          cout << "Successfully writing to file." << endl;
  
          int n;
          cout << "Enter number of students: ";
          cin >> n;
  
          for (int i = 0; i < n; ++i) {
              int nid, muid;
              float gpa;
              string name;
  
              cout << "Enter NID: ";
              cin >> nid;
              cout << "Enter MUID: ";
              cin >> muid;
              cout << "Enter GPA: ";
              cin >> gpa;
              cout << "Enter Name: ";
              cin >> name;
  
              fout << nid << " " << muid << " " << gpa << " " << name << " ";
          }
  
          fout << endl;
      } else {
          cerr << "Error opening file!" << endl;
      }
      fout.close();   
  }

   else if(choice == 3){
      ifstream fin("demo4.txt");
      if (!fin) {
         cerr << "Cannot open demo4.txt" << endl;
         return 1;
      }
      cout << "Successfully read to text file." << endl;
      LL A;
      NODE *t;

      int nid, muid;
      float gpa;
      string name;

       // อ่านข้อมูลทีละ 4 ค่า (int, int, float, string)
      while (fin >> nid >> muid >> gpa >> name) {
          t = new student(nid, muid, gpa, name);
          A.add_node(t);
      }

      A.show_all();
      // highestGPA(t);  // ถ้าคุณมีฟังก์ชันนี้
      
      fin.close();
    
   } 
   
   else if (choice == 4) {
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