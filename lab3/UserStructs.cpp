#include <iostream>
#include <iomanip>

#include"UserStructs.h"


std::istream& operator>>(std::istream &in, Date &date) {
	char p;
	in >> date.day >> p >> date.mounth >> p >> date.year;
	return in;
};

std::ostream & operator<<(std::ostream & out, Date & date) {
	out << std::setw(3) << date.day << " |" << std::setw(3) << date.mounth << " |" << std::setw(5) << date.year << " |";
	return out;
}

std::istream& operator>>(std::istream &in, Student &student) {
	std::string inic;
	in >> student.name >> inic >> student.group >> student.birthday;
	student.name += " " + inic;
	return in;
};

std::ostream & operator<<(std::ostream & out, Student & student) {
	out << std::setw(35) << student.name << " |" << std::setw(11) << student.group << " |" << student.birthday << std::endl;
	return out;
}