#include "Triad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void Triad::Init(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Triad::Display() const {
	cout << endl;
	cout << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}

void Triad::Read() {
	int day, month, year;
	cout << "Input date: ";
	cin >> day >> month >> year;

	Init(day, month, year);
}

Triad& Triad::operator++()
{
	setDay((getDay() + 1));
	setMonth((getMonth() + 1));
	setYear((getYear() + 1));
	return *this;
}

Triad::operator string()const
{
	stringstream ss;
	ss << endl;
	ss << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
	return ss.str();
}

Triad& Triad::operator = (const Triad& other)
{
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
	return *this;
}

Triad::~Triad() {}