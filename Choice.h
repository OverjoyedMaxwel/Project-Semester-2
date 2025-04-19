#include <iostream>     // สำหรับ cout, cin
#include <fstream>      // สำหรับ ifstream, ofstream
#include <vector>       // สำหรับ vector
#include <string>       // สำหรับ string
#include <cstdlib>      // สำหรับ atoi()
#include <ctime>        // สำหรับเวลาปัจจุบัน (time, tm, localtime)
//#include <Windows.h>    // control terminal

#include"LL.h"
//#include "student.h"
#include "Time.h"
#include "Data.h"

void processChoice(int choice, int argc, char* argv[]) {
    if(choice == '0'){   
        vector<Data> dataList;
    
        // ดึงข้อมูลจาก argv แล้วเก็บลง vector
        for (int i = 1; i < argc; i += 7) {
            Data d;
            d.year = atoi(argv[i]);
            d.month = atoi(argv[i + 1]);
            d.day = atoi(argv[i + 2]);
            d.name = argv[i + 3];
            d.hour = atoi(argv[i + 4]);
            d.minute = atoi(argv[i + 5]);
            d.second = atoi(argv[i + 6]);
    
            // ตรวจสอบความถูกต้องของข้อมูล
            if (!isValidTime(d)) {
                cout << "มีข้อมูลที่รับมาไม่ถูกต้อง กรุณาลองใหม่อีกครั้ง" << endl;
                return;
            }
            dataList.push_back(d);
        }
    
        // ถ้าข้อมูลทุกชุดถูกต้อง ค่อยเขียนลงไฟล์
        writeDataToFile(dataList); 
       }
       
    else if(choice == '1'){   
        vector<Data> dataList;
        int n;
    
        
        cout << "Enter number of homework: ";
        cin >> n;
    
        for (int i = 0; i < n; ++i) {
            Data d;
    
            cout << "Enter Year: ";
            cin >> d.year;
            cout << "Enter Month: ";
            cin >> d.month;
            cout << "Enter Day: ";
            cin >> d.day;
            cout << "Enter Homework Name: ";
            cin >> d.name;
            cout << "Enter Hour, Minute, Second: ";
            cin >> d.hour >> d.minute >> d.second;
    
            // ตรวจสอบวันเวลา
            if (!isValidTime(d)) {
                cout << "มีข้อมูลที่รับมาไม่ถูกต้อง กรุณาลองใหม่อีกครั้ง" << endl;
                return;
            }
            dataList.push_back(d);
        }
    
        // ถ้าข้อมูลทั้งหมดถูกต้อง ค่อยเขียนลงไฟล์
        writeDataToFile(dataList);
      }
    
    else if(choice == '2'){
          ifstream fin("demo4.txt");
          if (!fin) {
             cerr << "Cannot open demo4.txt" << endl;
             return ;
          }
          cout<<""<<endl;
          cout<<""<<endl;
          cout << "Successfully read to text file." << endl;
          cout<<"-------"<<endl;
          //cout<<"-------"<<endl;
          //sleep(1);
          cout<<"CONSTRUCTOR:"<<endl;
          cout<<"=========================================="<<endl;
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
    
        cout<<"DATALIST:"<<endl;
        cout<<"=========================================="<<endl;

          A.show_all();
          // highestGPA(t);  // ถ้าคุณมีฟังก์ชันนี้
          
          fin.close();
          
        cout<<"DESTRUCTOR:"<<endl;
        cout<<"=========================================="<<endl;
        
        //cin.ignore();
        //cin.get();
        
        } 
       
    else if (choice == '3') {
          ofstream fout("demo4.txt", ios::trunc); // ล้างไฟล์
          if (fout) {
              cout << "File cleared successfully." << endl;
          } else {
              cerr << "Failed to clear file." << endl;
          }
          fout.close();
      }
    
    else if (choice == '4') {
        ifstream fin("demo4.txt");
        if (!fin) {
            cerr << "Cannot open demo4.txt for reading." << endl;
            return ;
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
        writeDataToFileTruncate(dataList, "demo4.txt");
    
        cout << "Data sorted by time (descending) and updated in file." << endl;
        }
      
    else if (choice == '5') {
            ifstream fin("demo4.txt");
            if (!fin) {
                cout << "Cannot open demo4.txt" << endl;
                return ;
            }
        
            vector<Data> dataList;
            Data temp;
            
            // อ่านข้อมูลทั้งหมดลง vector
            while (fin >> temp.year >> temp.month >> temp.day >> temp.name >> temp.hour >> temp.minute >> temp.second) {
                dataList.push_back(temp);
            }
            fin.close();
        
            // กรองเฉพาะข้อมูลที่เป็นอนาคต
            vector<Data> futureData;
            bool hasPastData = false; // ตัวแปรไว้เช็คว่ามีข้อมูลในอดีตรึเปล่า
    
            for (int i = 0; i < dataList.size(); ++i) {
                if (isFuture(dataList[i])) {
                    futureData.push_back(dataList[i]);
                } else {
                    hasPastData = true; // เจอข้อมูลในอดีต
                }
            }
    
            if (hasPastData) {
                cout << "เราพบข้อมูลที่เลยกำหนด(อดีต) และเราได้นำข้อมูลดังกล่าวออกจากไฟล์ไปเรียบร้อย" << endl;
            }
        
            // เรียงข้อมูลแบบ Bubble Sort โดยเปรียบเทียบเวลาจริง
            bubbleSortByTime(futureData);
        
            // เขียนข้อมูลใหม่ลงไฟล์ (แทนที่)
            writeDataToFileTruncate(futureData, "demo4.txt");
        
            cout << "Filtered and sorted future data written to file." << endl;
        }
    else if (choice == '6') {
        ifstream fin("demo4.txt");
        if (!fin) {
            cout << "Cannot open demo4.txt" << endl;
            return ;
        }
    
        vector<Data> dataList;
        Data temp;
        
        // อ่านข้อมูลทั้งหมดลง vector
        while (fin >> temp.year >> temp.month >> temp.day >> temp.name >> temp.hour >> temp.minute >> temp.second) {
            dataList.push_back(temp);
        }
        fin.close();

        int n,i;
        vector<Data> OneDeletedData;

        cout << "Homework List:" << endl;
        for (int i = 0; i < dataList.size(); ++i) {
            cout << i + 1 << ". " << dataList[i].name << endl;
        }

        cout << "Choose the Number of Homework you want to Delete: ";
        cin >> n;
        for (i=0;i<dataList.size(); ++i){
            if(i == n-1){
                continue;
            }
            else{
                OneDeletedData.push_back(dataList[i]);
            }
        }
        writeDataToFileTruncate(OneDeletedData, "demo4.txt");
        cout << "Deleted homework and written to file." << endl;

        

    }
    /*
    else if(choice == '7'){
        ifstream fin("demo4.txt");
        if (!fin) {
        cout << "Cannot open demo4.txt" << endl;
        return;
        }
    
         LL A;  // สร้างลิงค์ลิสต์ใหม่
         NODE* t;
        int year, month, day, hour, minute, second;
         string name;

    // อ่านข้อมูลจากไฟล์และเพิ่มเข้าไปในลิงค์ลิสต์
         while (fin >> year >> month >> day >> name >> hour >> minute >> second) {
             t = new Time(year, month, day, hour, minute, second);
             A.add_node(t);
         }
        fin.close();

        // กรองเฉพาะข้อมูลที่เป็นอนาคต
         Time* current = A.hol;
         Time* prev = nullptr;
         bool hasPastData = false;

         while (current != nullptr) {
              if (!isFutureLL(*current)) {  // ถ้าเป็นข้อมูลในอดีต
                   hasPastData = true;
                   Time* temp = current;
                 if (prev == nullptr) {
                     A.hol = current->next;  // ถ้าเป็นหัวให้ปรับหัวใหม่
                     current = A.hol;
                  } else {
                     prev->next = current->next;
                     current = current->next;
                   }
                   delete temp;
             } else {
                prev = current;
                 current = current->next;
              }
         }

    // ถ้ามีข้อมูลในอดีต
         if (hasPastData) {
             cout << "เราพบข้อมูลที่เลยกำหนด(อดีต) และเราได้นำข้อมูลดังกล่าวออกจากไฟล์ไปเรียบร้อย" << endl;
          }

    // เรียงข้อมูลที่เป็นอนาคต
          bubbleSortByTimeLL(A);

    // เขียนข้อมูลใหม่ลงไฟล์ (แทนที่ไฟล์เดิม)
           writeDataToFileTruncateLL(A, "demo4.txt");

         cout << "Filtered and sorted future data written to file." << endl;
    }
    */
    else if(choice!='8'){
        cout << "Invalid choice!" << endl;
    }
    
        
    
}
