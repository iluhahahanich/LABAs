#pragma once
#include <cassert>
#include <cmath>
#include <vector>
template <typename T>
class Stack {
public:
	Stack();
	Stack(const Stack& other);
	Stack(Stack&& other);
	Stack(const std::initializer_list<T>& lst);
	~Stack();
	int size() const;
	bool empty() const;
	T& top() const;
	void operator<< (const T& elem);
	bool operator>> (T& var);
	Stack<T> operator= (const Stack& other);
	Stack<T> operator= (Stack&& other);
	bool operator< (const Stack& other) const;
	bool operator== (const Stack& other) const;
	T operator[](const int index) const;
private:
	T* arr = nullptr;
	int arr_size = 0;
	int end = 0;
};

template<typename T>
Stack<T>::Stack() : arr(nullptr), arr_size(0), end(0) {}

template<typename T>
Stack<T>::Stack(const Stack& other) : arr_size(other.arr_size), end(other.end) {
	arr = new T[arr_size];
	for (int i = 0; i < end; i++) {
		arr[i] = other.arr[i];
	}
}

template<typename T>
Stack<T>::Stack(Stack&& other){
	arr = other.arr;
	end = other.end;
	arr_size = other.arr_size;
	other.arr = nullptr;
}

template<typename T>
Stack<T>::Stack(const std::initializer_list<T>& lst) {
	for (const T& x : lst) {
		*this << x;
	}
}

template<typename T>
Stack<T>::~Stack() {
	if (arr != nullptr) {
		delete[] arr;
	}
	arr_size = 0;
	end = 0;
}

template<typename T>
int Stack<T>::size() const {
	return end;
}

template<typename T>
bool Stack<T>::empty() const {
	return end == 0;
}

template<typename T>
T& Stack<T>::top() const {
	return arr[end - 1];
}

template<typename T>
void Stack<T>::operator<<(const T& elem){
	if (arr_size == end) {
		arr_size = arr_size + arr_size / 2 + 1;
		T* old_arr = arr;
		arr = new T[arr_size];
		for (int i = 0; i < end; i++) {
			arr[i] = old_arr[i];
		}
		arr[end] = elem;
		++end;
		if (old_arr != nullptr) {
			delete[] old_arr;
		}
	}
	else {
		arr[end] = elem;
		++end;
	}
}

template<typename T>
bool Stack<T>::operator>>(T& var){
	if (end == 0) {
		return false;
	}
	var = arr[end - 1];
	--end;
	if (ceil(0.7 * arr_size) > end) {
		T* old_arr = arr;
		arr_size = ceil(arr_size * 0.7);
		arr = new T[arr_size + 1];
		for (int i = 0; i < end; i++) {
			arr[i] = old_arr[i];
		}
		delete[] old_arr;
	}
	return true;
}

template<typename T>
Stack<T> Stack<T>::operator=(const Stack& other) {
	if (this == &other) {
		return *this;
	}
	if (arr != nullptr) {
		delete[] arr;
	}

	arr = new T[other.arr_size];
	arr_size = other.arr_size;
	end = other.end;

	for (int i = 0; i < other.end; i++){
		arr[i] = other[i];
	}
	return *this;
}

template<typename T>
Stack<T> Stack<T>::operator=(Stack&& other){
	if (this == &other) return *this;
	arr = other.arr;
	end = other.end;
	arr_size = other.arr_size;
	other.arr = nullptr;
	return *this;
}

template<typename T>
bool Stack<T>::operator<(const Stack& other) const {
	if (end < other.end) {
		return true;
	}
	if (end > other.end) {
		return false;
	}
	for (int i = 0; i < end; ++i) {
		if (arr[i] < other[i]) {
			return true;
		}
		if (arr[i] > other[i]) {
			return false;
		}
	}
	return false;
}

template<typename T>
bool Stack<T>::operator==(const Stack& other) const {
	if (end != other.end) {
		return false;
	}
	for (int i = 0; i < end; i++){
		if (arr[i] != other[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
T Stack<T>::operator[](const int index) const {
	assert(index < end);
	assert(index >= 0);
	return arr[index];
}
