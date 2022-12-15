#pragma once
#include "polynomial_template.h"

template <class T>
class Collection
{
private:
	Polynominal<T>* coll;
	int size;

public:
	Collection() {
		size = 0;
		coll = NULL;
	}
	int get_size_coll() {
		return size;
	}

	void add_collection(Polynominal<T> poly) {
		if (coll == NULL) {
			Collection();
		}
		size++;
		Polynominal<T>* new_coll = new Polynominal<T>[size];
		for (int i = 0; i < size - 1; i++) {
			new_coll[i] = coll[i];
		}
		delete[] coll;
		coll = new_coll;
		coll[size - 1] = poly;
	}

	void delete_collection() {
		size = 0;
		delete[] coll;
		coll = NULL;
	}
	void delete_index(int& index) {
		if (size == 1) {
			index = 0;
			delete_collection();
			return;
		}
		for (int i = index; i < size - 1; i++) {
			coll[i] = coll[i + 1];
		}
		index = 0;
		size--;
		Polynominal<T>* new_coll = new Polynominal<T>[size];
		for (int i = 0; i < size; i++) {
			new_coll[i] = coll[i];
		}
		delete[] coll;
		coll = new_coll;
	}
	Polynominal<T>& operator[](int id) {
		return coll[id];
	}
};