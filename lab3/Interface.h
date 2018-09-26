#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Array.h"
#include "UserStructs.h"

const int headerTableLen = 5;
const int maxStrLen = 100;
const int maxTextMenuLen = 20;


using namespace std;

struct Interface{
	char headerTable[headerTableLen][maxStrLen],
			textMenu[maxTextMenuLen][maxStrLen];
	int lenMenu;
	Interface();

	void loadFromFile(Array<Student> &arr);
	void printHeaderTable(ostream &out);
	void printTable(Array<Student> &arr, ostream & out = cout);
	void printTable(Student student, int id, ostream & out = cout);
	void writeToFile(Array<Student> &arr);
	void add(Array<Student> &arr);
	void del(Array<Student> &arr);
	int menu();
};

Interface::Interface(){
	ifstream fHeader("header.txt");
	ifstream fMenu("textmenu.txt");
	for (size_t i = 0;i<headerTableLen; i++){
		fHeader.getline(headerTable[i], maxStrLen);
	}
	for (lenMenu = 0; !fMenu.eof() && lenMenu < maxTextMenuLen; lenMenu++){
		fMenu.getline(textMenu[lenMenu], maxStrLen);
	}
};

inline int Interface::menu(){
	int res;
	for (size_t i = 3; i < lenMenu; i++) {
		cout << textMenu[i] << endl;
	}
	cout << textMenu[0]; cin >> res;
	return res;
}


void Interface::loadFromFile(Array<Student> &arr) {
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

void Interface::printHeaderTable(ostream & out){
	for (size_t i = 0; i<5; i++) {
		out << headerTable[i] << endl;
	}
};

void Interface::printTable(Array<Student> &arr, ostream & out) {
	printHeaderTable(out);
	for (size_t i = 1; i <= arr.size; i++){
		out << "|" << setw(3) << i << " |" << arr[i];
	}
	out << headerTable[4]<<endl;
}

void Interface::printTable(Student student, int id, ostream & out){
	printHeaderTable(out);
	out << "|" << setw(3) << id << " |" << student;
	out << headerTable[4] << endl;
}

void Interface::writeToFile(Array<Student> & arr){
	string fileName;
	cout << "Введите имя файла: "; cin >> fileName;
	ofstream file(fileName);
	this->printTable(arr, file);
	cout << "Файл записан!" << endl;
}

void Interface::add(Array<Student> & arr){
	Student node;
	char inic[5];
	cout << "Введите фамилю и инициалы студента: ";
	cin >> node.name >> inic;

	strcat_s(node.name, " ");
	strcat_s(node.name, inic);

	cout << "Введите группу студента: "; cin>>node.group;
	cout << "Введите дату рождения студента в формате дд.мм.гггг: "; cin >> node.birthday;

	if (arr.insert(node) == 0)
		cout << "Запись добавлена." << endl;
	else
		cout << "Ошибка при добавлении записи!" << endl;
}
void Interface::del(Array<Student>& arr){
	printTable(arr);
	char ans;
	int id;
	cout << "Укажите номер записи для удаления: "; cin >> id;
	printTable(arr[id],id);
	cout << "Вы уверены, что нужно удалить запись? (д/н): "; cin >> ans;
	if (ans == 'д') arr.earase(id);
};

Array<Student> FindStudents(Array<Student> &students) {
	bool added[30] = { false };
	Array<Student> result;
	for (size_t i = 1; i < students.size; i++) {
		if (added[i])
			continue;

		for (size_t j = i + 1 ; j < students.size; j++) {
			if (!students[i].birthday.isEqual(students[j].birthday, eqMounth | eqYear))
				continue;

			if (!added[i]) {
				result.insert(students[i]);
				added[i] = true;
			}
			if (!added[j]) {
				result.insert(students[j]);
				added[j] = true;
			}
		};
	};
	return result;
}