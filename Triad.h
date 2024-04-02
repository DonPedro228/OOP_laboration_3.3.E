#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Triad : public Date
{
private:
    int date[3];
public:
    Triad() : Date() {};
    Triad(int day, int month, int year) : Date(day, month, year) {};
    Triad(const Triad& other) : Date(other.date[0], other.date[1], other.date[2]) {};

    void Init(int day, int month, int year);
    void Display() const;
    void Read();

    Triad& operator ++();
    Triad& operator = (const Triad& other);
    operator string () const;


    ~Triad(void);
};