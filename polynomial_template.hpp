#include <iostream>
#include <math.h>
using namespace std;
class Polynominal {
private:
	struct Data {
		Data* pnext;
		int value;
		int Mystep;
		Data(int value, int Mystep);
	};
	Data* Head;
	int counter_nul;
	int step;
public:
	Polynominal(int step);
	Data* getHead() const;
	int get_step() const;
	void set_coef(int i, int coef);
	void remove_coef(int i, int coef);
	void dell_coef(int i);
	friend int maximum(int a, int b);
	friend ostream& operator <<(ostream& os, const Polynominal poly);
	//===============================================
	int& operator[](int& id);
	Polynominal operator+(Polynominal other)const;
	Polynominal operator-(Polynominal other)const;
	Polynominal operator*(int value);
	int equation_roots(double*& arr) const;
	int valueX(int x);
	//bool operator==(Polynominal& other) const;
	//bool operator!=(Polynominal& other)const;
};