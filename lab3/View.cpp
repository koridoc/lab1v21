#include "View.h"

void ViewInterface::showMenu() {

	system("cls");
	int key = UI.menu();
	switch (key) {
	case 1:
		UI.loadFromFile(inArr); break;
	case 2:
		UI.printTable(inArr); break;
	case 3:
		UI.add(inArr); break;
	case 4:
		UI.del(inArr); break;
	case 5:
		sort(inArr, [](Student &a, Student &b) {
			return a.birthday.day < b.birthday.day;
		});
		break;
	case 6:
		sort(inArr, [](Student &a, Student &b) {
			return a.birthday.getHash() > b.birthday.getHash();
		}); break;
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
		seasons = getBirtdaySeasons(inArr); break;

	case 13:
		UI.printTableList(seasons); break;
	case 14:
		sort(seasons, [](BirthdaySeason &a, BirthdaySeason &b) {
			return a.season > b.season;
		});
		break;
	case 15:
		sort(seasons, [](BirthdaySeason &a, BirthdaySeason &b) {
			return a.count < b.count;
		});
		break;
	case 16:
		UI.writeToFile(seasons); break;
	case 17:
		exit(0);

	default:
		cout << "Такого пункта не существует. Попробуйте еще раз." << endl;
	}
	if (!cin.good()) {
		cin.clear();
		cin.ignore(32767, '\n');
	};
	system("pause");

}
ViewInterface::ViewInterface(){
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
}
