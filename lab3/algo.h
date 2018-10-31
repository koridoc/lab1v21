#pragma once

#include "Array.h"
#include "UserStructs.h"

//Сортировка пузырьком на шаблонах.
template<typename T, typename Compare>
inline void sort(T  &arr, Compare cmp) {
	for (int i = arr.Size(); i > 0; i--)
		for (int j = 1; j < i; j++)
			if (cmp(arr[j], arr[j + 1]))
				swap(arr[j], arr[j + 1]);

	std::cout << "Записи отсортированы!" << std::endl;
};

inline Array<Student> FindStudents(Array<Student> &students) {
	bool added[30] = { false };
	Array<Student> result;
	for (int i = 1; i < students.Size(); i++) {
		if (added[i])
			continue;

		for (int j = i + 1; j < students.Size(); j++) {
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

inline int getIdSeason(Array<BirthdaySeason> &Seasons, int season) {
	for (int i = 1; i <= Seasons.Size(); i++)
		if (Seasons[i].season == season)
			return i;

	BirthdaySeason tmp(season);
	Seasons.insert(tmp);

	return Seasons.Size();
}

inline Array<BirthdaySeason> getBirtdaySeasons(Array<Student> &students) {
	bool added[13] = { false };
	int m = 0;
	Array<BirthdaySeason> result;
	for (int i = 1; i < students.Size(); i++) {
		m = students[i].birthday.mounth;
		if (!added[m]) {
			int id = getIdSeason(result, (m / 3) % 4);
			result[id].count++;
			added[m] = true;
		}
	}
	return result;
}