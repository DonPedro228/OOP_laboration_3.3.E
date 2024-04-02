#include "Date.h"
#include <sstream>
#include <iostream>
using namespace std;

Date::Date()
{
    date[0] = 0;
    date[1] = 0;
    date[2] = 0;
}

Date::Date(int day, int month, int year)
{
    date[0] = day;
    date[1] = month;
    date[2] = year;
}

Date::Date(const Date& other)
{
    date[0] = other.date[0];
    date[1] = other.date[1];
    date[2] = other.date[2];
}

void Date::Init(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

void Date::Display() const
{
    cout << endl;
    cout << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}

void Date::Read()
{
    int day, month, year;
    cout << "Input date: ";
    cin >> day >> month >> year;

    Init(day, month, year);
}

Date::operator string() const
{
    stringstream ss;
    ss << endl;
    ss << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
    return ss.str();
}

Date& Date::operator++()
{
    ++date[0];
    ++date[1];
    ++date[2];
    return *this;
}

Date& Date::operator--()
{
    --date[0];
    --date[1];
    --date[2];
    return *this;
}

Date Date::operator++(int)
{
    date[0]++;
    date[1]++;
    date[2]++;
    return *this;
}

Date Date::operator--(int)
{
    date[0]--;
    date[1]--;
    date[2]--;
    return *this;
}

Date& Date::operator=(const Date& other)
{
    date[0] = other.date[0];
    date[1] = other.date[1];
    date[2] = other.date[2];
    return *this;
}

Date operator+(const Date& date, int days) {
    int day = date.getDay() + days;
    int month = date.getMonth();
    int year = date.getYear();

    while (day > 31 || (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29) ||
        (month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day -= 29;
            }
            else {
                day -= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            day -= 30;
        }
        else {
            day -= 31;
        }
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    Date result(date);
    result.setDay(day);
    result.setMonth(month);
    result.setYear(year);

    return result;
}

ostream& operator << (ostream& out, const Date& m)
{
    out << string(m);
    return out;
}


istream& operator >> (istream& in, Date& m)
{
    int day, month, year;
    cout << endl;
    cout << "Input date: ";
    in >> m.date[0] >> m.date[1] >> m.date[2];
    return in;
}


Date::~Date() {}