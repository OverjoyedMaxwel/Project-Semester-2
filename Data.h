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
    return difftime(taskTime, time(0)) > 0;
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

    return difftime(time1, time2) < 0;
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