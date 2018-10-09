#pragma once 
#include <string>
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
	int getHash(size_t mask = 0xFFFFFFFF) {
		return (day | (mounth << 8) | (year << 16) & mask);
	};

	friend std::istream& operator>>(std::istream &in, Date &date);
	friend std::ostream& operator<<(std::ostream &out, Date &date);
};

struct Student {
	std::string name,
		group;
	Date birthday;

	friend std::istream& operator>>(std::istream &in, Student &student);
	friend std::ostream& operator<<(std::ostream &out, Student &student);
};

struct BirthdaySeason{
	int season;
	int count;
	BirthdaySeason(int season) :season(season) {
		this->count = 0;
	};
	BirthdaySeason() {
		season = -1;
		count = 0;
	}
};