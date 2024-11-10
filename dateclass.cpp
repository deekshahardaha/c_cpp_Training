#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Date {
    int year, month, day;

    // Helper function to check if a date is valid
    bool isValidDate(int year, int month, int day) {
        if (month < 1 || month > 12 || day < 1) return false;

        // Days in each month
        int daysInMonth[] = { 31, 28 + (isLeapYear(year) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return day <= daysInMonth[month - 1];
    }

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Calculate total days from a reference date
    int totalDaysFromReference()  {
        int totalDays = 0;

        // Add days for the years
        for (int y = 0; y < year; y++) {
            totalDays += 365 + (isLeapYear(y) ? 1 : 0);
        }

        // Add days for the months in the current year
        int daysInMonth[] = { 31, 28 + (isLeapYear(year) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        for (int m = 1; m < month; m++) {
            totalDays += daysInMonth[m - 1];
        }

        // Add days in the current month
        totalDays += day;

        return totalDays;
    }

public:
    Date(int year, int month, int day) {
        if (!isValidDate(year, month, day)) {
            throw invalid_argument("Invalid date");
        }
        this->year = year;
        this->month = month;
        this->day = day;
    }

    // Overload the ++ operator (prefix)
    Date& operator++() {
        // Increment the date by one day
        day++;
        if (!isValidDate(year, month, day)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Overload the -- operator (prefix)
    Date& operator--() {
        // Decrement the date by one day
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = isLeapYear(year) && month == 2 ? 29 : (month == 2 ? 28 : (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31));
        }
        return *this;
    }

    // Overload the += operator
    Date& operator+=(int days) {
        for (int i = 0; i < days; i++) {
            ++(*this);
        }
        return *this;
    }

    // Overload the - operator
    int operator-( Date& other) {
        return abs(this->totalDaysFromReference() - other.totalDaysFromReference());
    }

    // Overload the > operator
    bool operator>( Date& other)  {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }

    // Function to print the date
    void print()  {
        cout << year << "-" << month << "-" << day << endl;
    }
};

int main() {
    try {
        Date dt(2024, 11, 30);
        dt.print();

        ++dt; // Increment
        dt.print();

        --dt; // Decrement
        dt.print();

        dt += 4; // Add 4 days
        dt.print();

        Date dt2(2024, 11, 16);
        int days = dt2 - dt; // Subtracting dates
        cout << "Days between dt2 and dt: " << days << endl;

        if (dt2 > dt) {
            cout << "dt2 is after dt" << endl;
        }
        else{
            cout << "dt1 is after d2" << endl;
        }

    } catch ( invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}