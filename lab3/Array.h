#pragma once

template<typename T>
struct Array{
	size_t capasity,
		size;
	T data[30];

	Array();
	T& operator[](const int id);
	int insert(T &node);
	int earase(const int id);
	void clear();
};

template<typename T>
Array<T>::Array() {
	capasity = 30;
	size = 0;
}
template<typename T>
T& Array<T>::operator[](const int id){
	return data[id - 1];
}

template<typename T>
int Array<T>::insert(T &node) {
	T tmp = node;
	if (size < capasity) {
		data[size] = tmp;
		size++;
		return 0;
	}
	return -1;
}

template<typename T>
int Array<T>::earase(const int id){
	for (size_t i = id - 1; i < size - 1; i++)
		std::swap(data[i], data[i + 1]);
	--size;
	return 0;
}
	
template<typename T>
inline void Array<T>::clear(){
	size = 0;
}