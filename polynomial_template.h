#pragma once
#include <iostream>
#include <math.h>
#include <complex>

using namespace std;

template<typename T>
class Polynominal {
private:
	struct Data {
		Data* pnext;
		T value;
		int Mystep;
		Data(T value, int Mystep);
	};
	Data* Head;
	int counter_nul;
	int step;
public:
	Polynominal(int step);
	Data* getHead() const;
	int get_step() const;
	void set_coef(int i, T coef);
	void remove_coef(int i, T coef);
	void dell_coef(int i);
	friend int maximum(int a, int b);
	friend ostream& operator <<(ostream& os, const Polynominal poly){
		Data<T>* tmp = poly.Head;
		while (tmp != nullptr)
		{
			if (tmp->Mystep == 0)
			{
				os << tmp->value << " + ";
			}
			else if (tmp->Mystep == poly.get_step()) {
				os << tmp->value << "x^" << tmp->Mystep;
			}
			else
			{
				os << tmp->value << "x^" << tmp->Mystep << " + ";
			}
			tmp = tmp->pnext;
		}
		return os;
	}
	//===============================================
	T& operator[](int& id);
	Polynominal operator+(Polynominal other)const;
	Polynominal operator-(Polynominal other)const;
	Polynominal operator*(int value);
	int equation_roots(T*& arr) const;
	T valueX(T x);
	//bool operator==(Polynominal& other) const;
	//bool operator!=(Polynominal& other)const;

	//============================================== 0 1 
};