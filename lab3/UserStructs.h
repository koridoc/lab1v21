#pragma once 
#include <iostream>

#define eqYear		0xFFFF0000
#define eqMounth	0x0000FF00
#define eqDay		0x000000FF

struct Date {
	int day,
		mounth,
		year;

	bool isEqual(Date date, size_t mask = 0xFFFFFFFF) {
		return (getHash() & mask) == (date.getHash() & mask);
	};
	int getHash() {
		return day | (mounth << 8) | (year << 16);
	};

	friend std::istream& operator>>(std::istream &in, Date &date);
	friend std::ostream& operator<<(std::ostream &out, Date &date);
};

struct Student {
	char name[36],
		group[12];
	Date birthday;

	friend std::istream& operator>>(std::istream &in, Student &student);
	friend std::ostream& operator<<(std::ostream &out, Student &student);
};

