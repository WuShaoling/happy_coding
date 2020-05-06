#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int daysBetweenDates(string date1, string date2) {
        int days1 = getDays(date1);
        int days2 = getDays(date2);
        return abs(days1 - days2);
    }

   private:
    void format(string date, int& year, int& month, int& day) {
        year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 +
               (date[2] - '0') * 10 + date[3] - '0';
        month = (date[5] - '0') * 10 + date[6] - '0';
        day = (date[8] - '0') * 10 + date[9] - '0';
    }

    int getDays(const string& date) {
        int year, month, day;
        format(date, year, month, day);

        int days = 0;
        for (int i = 1970; i < year; i++) {
            if (checkIsLeapYear(i))
                days += 366;
            else
                days += 365;
        }

        bool leapYear = checkIsLeapYear(year);
        for (int i = 1; i < month; i++) {
            if (leapYear)
                days += dayOfLeapYear[i];
            else
                days += dayOfYear[i];
        }

        return days + day;
    }

    bool checkIsLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int dayOfYear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfLeapYear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

int main() {
    Solution s;
    cout << s.daysBetweenDates("2019-06-29", "2019-06-30");
}