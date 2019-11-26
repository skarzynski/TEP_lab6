#pragma once

template <typename T> class Table {

private:
	int size;			//rozmiar tablicy
	T* table;			//wskaźnik na tablicę

public:
	Table();			//konstruktor bezparametrowy
	~Table();			//destruktor

	bool setLength(int newSize);				//ustawia nową długość tablicy

	T* getElement(int position);				//zwraca wskaźnik na element tablicy o zadanej pozycji
	bool setElement(int position, T newValue);	//wstawia element do tablicy na zadaną pozycję

	void print();		//drukuje tablicę
};

//------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
Table<T>::Table() {
	this->size = 0;
	this->table = nullptr;
}

template <typename T>
Table<T>::~Table() {
	if (this->table != nullptr) {
		delete[] this->table;
	}
}

template <>
bool Table<string>::setLength(int newSize) {
	if (newSize <= 0 || newSize > 10) {
		return false;
	}
	string *newTable = new string[newSize];
	if (this->table != nullptr) {
		int minLength;
		if (newSize < this->size) {
			minLength = newSize;
		}
		else {
			minLength = this->size;
			for (int i = minLength; i < newSize; i++) {
				newTable[i] = "-";
			}
		}
		for (int i = 0; i < minLength; i++) {
			newTable[i] = this->table[i];
		}
		delete[] this->table;
	}
	else {
		for (int i = 0; i < newSize; i++) {
			newTable[i] = "-";
		}
	}
	this->size = newSize;
	this->table = newTable;
	return true;
}

template <typename T>
bool Table<T>::setLength(int newSize) {
	if (newSize <= 0 || newSize > 10) {
		return false;
	}
	T *newTable = new T[newSize];
	if (this->table != nullptr) {
		int minLength;
		if (newSize < this->size) {
			minLength = newSize;
		}
		else {
			minLength = this->size;
			for (int i = minLength; i < newSize; i++) {
				newTable[i] = 0;
			}
		}
		for (int i = 0; i < minLength; i++) {
			newTable[i] = this->table[i];
		}
		delete[] this->table;
	}
	else {
		for (int i = 0; i < newSize; i++) {
			newTable[i] = 0;
		}
	}
	this->size = newSize;
	this->table = newTable;
	return true;
}template <typename T>
T* Table<T>::getElement(int position) {
	if ((position < 0) || (position >= this->size)) {
		return nullptr;
	}
	return(&(this->table[position]));
}template <typename T>
bool Table<T>::setElement(int position, T newValue) {
	if ((position < 0) || (position >= this->size)) {
		return false;
	}
	this->table[position] = newValue;
	return true;
}template <>
bool Table<int>::setElement(int position, int newValue) {
	if ((position < 0) || (position >= this->size) || (newValue < 0)) {
		return false;
	}
	this->table[position] = newValue;
	return true;
}template <>
bool Table<double>::setElement(int position, double newValue) {
	if ((position < 0) || (position >= this->size) || (newValue > 0)) {
		return false;
	}
	this->table[position] = newValue;
	return true;
}template <typename T>void Table<T>::print() {
	for (int i = 0; i < this->size; i++) {		cout << this->table[i] << " ";	}	cout << endl;}