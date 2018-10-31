#pragma once

template<typename T>
struct Array{
	size_t capasity,
		size;
	T *data;

	Array();
	Array(const Array<T> &arr);
	~Array(){
		if (data != nullptr)
			delete[] data;
	}
	Array operator = (const Array<T> arr);

	T& operator[](const int id);
	int insert(T &node);
	int earase(const int id);
	void realloc(int newSize);
	void clear();


};

template<typename T>
Array<T>::Array() {
	data = nullptr;
	capasity = 4;
	size = 0;
	this->realloc(capasity);
}
template<typename T>
Array<T>::Array(const Array<T> &arr){
	this->data = new T[arr.size];
	this->size = arr.size;
	for (size_t i = 0; i < size; i++)
		this->data[i] = arr.data[i];

}
template<typename T>
Array<T> Array<T>::operator=(Array<T> arr){
	this->realloc(arr.size);
	this->size = arr.size;
	for (size_t i = 0; i < size; i++)
		this->data[i] = arr.data[i];
	return *this;
}


template<typename T>
void Array<T>::realloc(int newCapasity){
	T *newArray = new T[newCapasity];

	for (int i = 0; i < min(this->size, newCapasity); i++)
		newArray[i] = this->data[i];

	if(this->data != nullptr)
		delete[] this->data;

	this->capasity = newCapasity;
	this->data = newArray;
};


template<typename T>
T& Array<T>::operator[](const int id){
	return data[id - 1];
}

template<typename T>
int Array<T>::insert(T &node) {
	T tmp = node;

	if (size == capasity)
		this->realloc(2 * size);

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