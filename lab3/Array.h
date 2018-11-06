#pragma once

template<typename T>
class Array{
private:
	int capasity,
		size;
	T data[30];

public:
	Array();
	Array(const Array<T> &arr);
	~Array(){
		size = 0;
	}
	Array operator = (const Array<T> &arr);

	T& operator[](const int id);
	int insert(T &node);
	int earase(const int id);
	void clear();
	int Size() const;

};

template<typename T>
inline Array<T>::Array() {
	capasity = 30;
	size = 0;
}
template<typename T>
inline Array<T>::Array(const Array<T> &arr){
	this->size = arr.size;
	this->capasity = arr.size;
	for (int i = 0; i < size; i++)
		this->data[i] = arr.data[i];
}
template<typename T>
inline Array<T> Array<T>::operator=(const Array<T> &arr){
	if (this == &arr)
		return *this;

	this->size = arr.size;
	this->capasity = arr.size;
	for (int i = 0; i < size; i++)
		this->data[i] = arr.data[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](const int id) {
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
int Array<T>::earase(const int id) {
	for (int i = id - 1; i < size - 1; i++)
		std::swap(data[i], data[i + 1]);
	--size;
	return 0;
}

template<typename T>
inline void Array<T>::clear() {
	size = 0;
}

template<typename T>
inline int Array<T>::Size() const
{
	return this->size;
}
