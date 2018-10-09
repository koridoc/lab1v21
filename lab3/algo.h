#pragma once

#include "Array.h"
#include "UserStructs.h"

//Сортировка пузырьком на шаблонах.
template<typename T, typename Compare>
void sort(T  &arr, Compare cmp) {
	for (int i = arr.size; i > 0; i--)
		for (int j = 1; j < i; j++)
			if (cmp(arr[j], arr[j + 1]))
				swap(arr[j], arr[j + 1]);

	std::cout << "Записи отсортированы!" << std::endl;
};

Array<Student> FindStudents(Array<Student> &students) {
	bool added[30] = { false };
	Array<Student> result;
	for (size_t i = 1; i < students.size; i++) {
		if (added[i])
			continue;

		for (size_t j = i + 1; j < students.size; j++) {
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

int getIdSeason(Array<BirthdaySeason> &Seasons, int season) {
	for (size_t i = 1; i <= Seasons.size; i++)
		if (Seasons[i].season == season)
			return i;

	BirthdaySeason tmp(season);
	Seasons.insert(tmp);

	return Seasons.size;
}

Array<BirthdaySeason> getBirtdaySeasons(Array<Student> &students) {
	bool added[13] = { false };
	int m = 0;
	Array<BirthdaySeason> result;
	for (size_t i = 1; i < students.size; i++) {
		m = students[i].birthday.mounth;
		if (!added[m]) {
			int id = getIdSeason(result, (m / 3) % 4);
			result[id].count++;
			added[m] = true;
		}
	}
	return result;
}