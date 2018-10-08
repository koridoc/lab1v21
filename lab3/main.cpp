#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include "Interface.h"
#include "algo.h"
using namespace std;


bool ByDay(Student &a, Student &b) {
	return a.birthday.day < b.birthday.day;
}
struct ByBirthday{
	bool operator() (Student &a, Student &b) {
		return a.birthday.getHash() > b.birthday.getHash();
	};
}byBirthday;



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface UI;
	Array<Student> inArr, outArr;
	Array<BirthdaySeason> season;
	while (true){
		system("cls");
		int key = UI.menu();
		switch (key){
		case 1: 
			UI.loadFromFile(inArr); break;
		case 2:
			UI.printTable(inArr); break;
		case 3:
			UI.add(inArr); break;
		case 4:
			UI.del(inArr); break;
		case 5:
			sort(inArr, ByDay);  //В качестве компаратора указатель на функцию
			break;
		case 6:
			sort(inArr, byBirthday); break; // структура с перегруженным оператором ()
		case 7:
			UI.writeToFile(inArr); break;
		case 8:
			outArr = FindStudents(inArr); break;
		case 9:
			UI.printTable(outArr); break;
		case 10:
			sort(outArr, [](Student &a, Student &b) { //Лямба-функция
				return a.birthday.year > b.birthday.year ? true :
					a.birthday.year == b.birthday.year && a.birthday.mounth > b.birthday.mounth ? true :
					a.birthday.mounth == b.birthday.mounth && a.name > b.name ? true : false;
			});
			break;
		case 11:
			UI.writeToFile(outArr); break;
		case 12:
			season = getBirtdaySeasons(inArr); break;
		case 13:
			exit(0);

		default:
			cout << "Такого пункта не существует. Попробуйте еще раз." << endl;
		}
		system("pause");

	}

	return 0;
};