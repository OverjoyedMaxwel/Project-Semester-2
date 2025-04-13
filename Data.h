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

void mySwap(Data &a, Data &b) {
    Data temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<Data>& dataList) {
    int n = dataList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!isGreater(dataList[j], dataList[j + 1])) {
                mySwap(dataList[j], dataList[j + 1]);
            }
        }
    }
}
