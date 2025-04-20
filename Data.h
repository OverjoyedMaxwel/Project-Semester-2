struct Data {
    int year, month, day, hour, minute, second;
    string name;
};

bool isGreater(const Data& d1, const Data& d2) {
    if (d1.year != d2.year) return d1.year > d2.year;
    if (d1.month != d2.month) return d1.month > d2.month;
    if (d1.day != d2.day) return d1.day > d2.day;
    if (d1.hour != d2.hour) return d1.hour > d2.hour;
    if (d1.minute != d2.minute) return d1.minute > d2.minute;
    return d1.second > d2.second;
}

// สลับค่าข้อมูล 2 ตัว
void swap(Data &a, Data &b) {
    Data temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<Data>& dataList) {
    int n = dataList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!isGreater(dataList[j], dataList[j + 1])) {
                swap(dataList[j], dataList[j + 1]);
            }
        }
    }
}

bool isFuture(const Data& d) {
    tm t = {};
    t.tm_year = d.year - 1900;
    t.tm_mon = d.month - 1;
    t.tm_mday = d.day;
    t.tm_hour = d.hour;
    t.tm_min = d.minute;
    t.tm_sec = d.second;

    time_t taskTime = mktime(&t);
    //return difftime(taskTime, time(0)) > 0;
    return taskTime > time(0);
}

// เปรียบเทียบว่าข้อมูล d1 ใกล้ปัจจุบันมากกว่าหรือไม่
bool compareByTime(const Data& d1, const Data& d2) {
    tm t1 = {}, t2 = {};
    t1.tm_year = d1.year - 1900;
    t1.tm_mon = d1.month - 1;
    t1.tm_mday = d1.day;
    t1.tm_hour = d1.hour;
    t1.tm_min = d1.minute;
    t1.tm_sec = d1.second;

    t2.tm_year = d2.year - 1900;
    t2.tm_mon = d2.month - 1;
    t2.tm_mday = d2.day;
    t2.tm_hour = d2.hour;
    t2.tm_min = d2.minute;
    t2.tm_sec = d2.second;

    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);

    //return difftime(time1, time2) < 0;
    return time1 < time2;
}


// Bubble sort ตามเวลา
void bubbleSortByTime(vector<Data>& dataList) {
    int n = dataList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compareByTime(dataList[j], dataList[j + 1])) {
                swap(dataList[j], dataList[j + 1]);
            }
        }
    }
}

bool isValidDate(int year, int month, int day) {
    if (year < 0 || month < 1 || month > 12 || day < 1) return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // เช็คปีอธิกสุรทิน (Leap Year)
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

bool isValidTime(const Data& d) {
    return isValidDate(d.year, d.month, d.day) &&
           d.hour >= 0 && d.hour <= 23 &&
           d.minute >= 0 && d.minute <= 59 &&
           d.second >= 0 && d.second <= 59;
}

void writeDataToFile(const vector<Data>& dataList, const string& filename = "demo4.txt") {
    ofstream fout(filename, ios::app);  // เขียนแบบต่อท้าย (append)
    if (fout) {
        cout << "Successfully writing to text file." << endl;

        for (int i = 0; i < dataList.size(); ++i) {
            fout << dataList[i].year << " "
                 << dataList[i].month << " "
                 << dataList[i].day << " "
                 << dataList[i].name << " "
                 << dataList[i].hour << " "
                 << dataList[i].minute << " "
                 << dataList[i].second << " ";
        }

        fout << endl;
        fout.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
}

void writeDataToFileTruncate(const vector<Data>& dataList, const string& filename) {
    ofstream fout(filename, ios::trunc);  // เปิดแบบเขียนทับ (truncate)
    if (!fout) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < dataList.size(); ++i) {
        fout << dataList[i].year << " "
             << dataList[i].month << " "
             << dataList[i].day << " "
             << dataList[i].name << " "
             << dataList[i].hour << " "
             << dataList[i].minute << " "
             << dataList[i].second << " ";
    }

    fout << endl;
    fout.close();
}

/*
bool isFutureLL(Time* t) {
    time_t now = time(0);
    tm* current = localtime(&now);

    if (t->getYear() != current->tm_year + 1900)
        return t->getYear() > current->tm_year + 1900;
    if (t->getMonth() != current->tm_mon + 1)
        return t->getMonth() > current->tm_mon + 1;
    if (t->getDay() != current->tm_mday)
        return t->getDay() > current->tm_mday;
    if (t->getHour() != current->tm_hour)
        return t->getHour() > current->tm_hour;
    if (t->getMinute() != current->tm_min)
        return t->getMinute() > current->tm_min;
    return t->getSecond() > current->tm_sec;
}
*/


time_t toTimeT(Time* t) {
    tm temp = {};
    temp.tm_year = t->getYear() - 1900;
    temp.tm_mon  = t->getMonth() - 1;
    temp.tm_mday = t->getDay();
    temp.tm_hour = t->getHour();
    temp.tm_min  = t->getMinute();
    temp.tm_sec  = t->getSecond();
    return mktime(&temp);
}


void bubbleSortByTimeLL(NODE*& head) {
    if (!head || !head->move_next()) return;

    bool swapped;
    do {
        swapped = false;
        NODE** currPtr = &head;

        while ((*currPtr) && (*currPtr)->move_next()) {
            Time* t1 = dynamic_cast<Time*>(*currPtr);
            Time* t2 = dynamic_cast<Time*>((*currPtr)->move_next());

            if (t1 && t2 && toTimeT(t1) > toTimeT(t2)) {
                // Swap pointers
                NODE* tmp = (*currPtr)->move_next();
                (*currPtr)->set_next(tmp->move_next());
                tmp->set_next(*currPtr);
                *currPtr = tmp;
                swapped = true;
            }

            currPtr = &((*currPtr)->next);
        }
    } while (swapped);
}

/*
void removePastLL(NODE*& head) {
    while (head && !isFutureLL(dynamic_cast<Time*>(head))) {
        NODE* temp = head;
        head = head->move_next();
        //delete temp;
    }

    NODE* curr = head;
    while (curr && curr->move_next()) {
        Time* nextTime = dynamic_cast<Time*>(curr->move_next());
        if (!isFutureLL(nextTime)) {
            NODE* temp = curr->move_next();
            curr->set_next(temp->move_next());
            //delete temp;
        } else {
            curr = curr->move_next();
        }
    }
}
*/

void writeToFileFromListLL(NODE* head, const std::string& filename) {
    std::ofstream fout(filename);
    Time* t;
    for (NODE* curr = head; curr; curr = curr->move_next()) {
        t = dynamic_cast<Time*>(curr);
        if (t) {
            fout << t->getYear() << " " << t->getMonth() << " " << t->getDay() << " "
                 << t->getName() << " " << t->getHour() << " " << t->getMinute() << " " << t->getSecond() << "\n";
        }
    }
    fout.close();
}