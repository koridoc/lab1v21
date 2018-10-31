#include<Windows.h>
#include <cstdlib>
#include "Interface.h"
#include "algo.h"


class ViewInterface{
public:
	ViewInterface();
	void showMenu();

private:
	Interface UI;
	Array<Student> inArr, outArr;
	Array<BirthdaySeason> seasons;
};
