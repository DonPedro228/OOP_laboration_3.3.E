#pragma once
#include <string>
#include "Object.h"
using namespace std;

class Date : public Object
{
private:
    int date[3];
public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);

    void Init(int day, int month, int year);
    void Display() const;
    void Read();
    operator string() const;

    int getDay() const { return date[0]; }
    int getMonth() const { return date[1]; }
    int getYear() const { return date[2]; }
    void setDay(int day) { date[0] = day; }
    void setMonth(int month) { date[1] = month; }
    void setYear(int year) { date[2] = year; }

    Date& operator ++();
    Date& operator --();
    Date operator ++(int);
    Date operator --(int);

    friend ostream& operator << (ostream& out, const Date& m);
    friend istream& operator >> (istream& in, Date& m);

    Date& operator = (const Date& other);
    friend Date operator+(const Date& date, int days);


    ~Date(void);


};