#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include "Interface.h"

using namespace std;


//���������� ��������� �� ��������.
template<typename T, typename Compare>
void sort(T  &arr, Compare cmp) {
	for (int i = arr.size; i > 0; i--)
		for (int j = 1; j < i; j++)
			if (cmp(arr[j], arr[j + 1]))
				swap(arr[j], arr[j + 1]);

	cout << "������ �������������!" << endl;
};

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
			sort(inArr, ByDay);  //� �������� ����������� ��������� �� �������
			break;
		case 6:
			sort(inArr, byBirthday); break; // ��������� � ������������� ���������� ()
		case 7:
			UI.writeToFile(inArr); break;
		case 8:
			outArr = FindStudents(inArr); break;
		case 9:
			UI.printTable(outArr); break;
		case 10:
			sort(outArr, [](Student &a, Student &b) { //�����-�������
				return a.birthday.getHash() > a.birthday.getHash() || strcmp(a.name, b.name) > 0;
			});
			break;
		case 11:
			UI.writeToFile(outArr); break;
		case 12:
			exit(0);

		default:
			cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
		}
		system("pause");

	}

	return 0;
};