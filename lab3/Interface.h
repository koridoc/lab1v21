#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Array.h"
#include "UserStructs.h"

const int headerTableLen = 5;
const int maxStrLen = 100;
const int maxTextMenuLen = 25;
const int headerTableListLen = 4;

using namespace std;

class Interface{
private:
	char headerTable[headerTableLen][maxStrLen],
			textMenu[maxTextMenuLen][maxStrLen],
			headerTableList[headerTableListLen][maxStrLen];
	int lenMenu;

public:
	Interface();
	void loadFromFile(Array<Student> &arr);
	void printHeaderTable(ostream &out);

	void printHeaderTableList(ostream &out);
	void printTableList(Array<BirthdaySeason> &seasons, ostream & out = cout);

	void printTable(Array<Student> &arr, ostream & out = cout);
	void printTable(Student student, int id, ostream & out = cout);

	void writeToFile(Array<Student> &arr);
	void writeToFile(Array<BirthdaySeason> &seasons);
	void add(Array<Student> &arr);
	void del(Array<Student> &arr);
	void constructor(Array<Student> &arr);
	int menu();
};

inline Interface::Interface(){
	ifstream fHeader("header.txt");
	ifstream fHeaderList("headerList.txt");
	ifstream fMenu("textmenu.txt");

	for (int i = 0; i<headerTableListLen; i++) {
		fHeaderList.getline(headerTableList[i], maxStrLen);
	}
	for (int i = 0;i<headerTableLen; i++){
		fHeader.getline(headerTable[i], maxStrLen);
	}
	for (lenMenu = 0; !fMenu.eof() && lenMenu < maxTextMenuLen; lenMenu++){
		fMenu.getline(textMenu[lenMenu], maxStrLen);
	}
};

inline int Interface::menu(){
	int res;
	for (int i = 3; i < lenMenu; i++) {
		cout << textMenu[i] << endl;
	}
	cout << textMenu[0];
	cin >> res;
	return res;
}




inline void Interface::loadFromFile(Array<Student> &arr) {
	string fileName;
	cout << "Введите имя файла: "; cin >> fileName;		//C++11 
	ifstream file(fileName);
	
	if (!file.is_open())
		cout << "\n";
	Student tmp;
	while (!file.eof()) {
		file >> tmp;
		if (arr.insert(tmp) == -1) {
			cout << "Ошибка при загрузке записей из файла. Их слишком много?";
			return;
		}
	};
	cout << "Записи добавлены!" << endl;
};

inline void Interface::printHeaderTable(ostream & out){
	for (int i = 0; i<5; i++) {
		out << headerTable[i] << endl;
	}
};
inline void Interface::printHeaderTableList(ostream &out) {
	for (int i = 0; i<4; i++) {
		out << headerTableList[i] << endl;
	}
}

inline void Interface::printTableList(Array<BirthdaySeason> &seasons, ostream & out) {
	printHeaderTableList(out);
	std::string nameSeasons[] = { "Зима","Весна", "Лето", "Осень" };

	for (int i = 1; i <= seasons.Size(); i++) {
		out << "|" << setw(10) << nameSeasons[seasons[i].season] << " |" <<setw(11)<< seasons[i].count << " |\n";
	}
	out << headerTableList[0] << endl;
}

inline void Interface::printTable(Array<Student> &arr, ostream & out) {
	printHeaderTable(out);
	for (int i = 1; i <= arr.Size(); i++){
		out << "|" << setw(3) << i << " |" << arr[i];
	}
	out << headerTable[4]<<endl;
}

inline void Interface::printTable(Student student, int id, ostream & out){
	printHeaderTable(out);
	out << "|" << setw(3) << id << " |" << student;
	out << headerTable[4] << endl;
}

inline void Interface::writeToFile(Array<Student> & arr){
	string fileName;
	cout << "Введите имя файла: "; cin >> fileName;
	ofstream file(fileName);
	this->printTable(arr, file);
	cout << "Файл записан!" << endl;
}

inline void Interface::writeToFile(Array<BirthdaySeason> &seasons) {
	string fileName;
	cout << "Введите имя файла: "; cin >> fileName;
	ofstream file(fileName);
	this->printTableList(seasons, file);
	cout << "Файл записан!" << endl;
}

inline void Interface::add(Array<Student> & arr){
	Student node;
	std::string inic;
	cout << "Введите фамилю и инициалы студента: ";
	cin >> node.name >> inic;

	node.name +=  " " + inic;

	cout << "Введите группу студента: "; cin>>node.group;
	cout << "Введите дату рождения студента в формате дд.мм.гггг: "; cin >> node.birthday;

	if (arr.insert(node) == 0)
		cout << "Запись добавлена." << endl;
	else
		cout << "Ошибка при добавлении записи!" << endl;
}
inline void Interface::del(Array<Student>& arr){
	printTable(arr);
	char ans;
	int id;
	cout << "Укажите номер записи для удаления: "; cin >> id;
	printTable(arr[id],id);
	cout << "Вы уверены, что нужно удалить запись? (д/н): "; cin >> ans;
	if (ans == 'д') arr.earase(id);
}
inline void Interface::constructor(Array<Student>& arr){
	Array<Student> tmp(arr);
	this->printTable(tmp);
};

