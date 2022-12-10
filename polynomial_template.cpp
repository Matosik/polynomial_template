#include "polynomial_template.hpp"
int maximum(int a, int b) { 
	if (a > b) { return a; }
	else { return b; }
}

Polynominal::Data::Data(int value, int Mystep) {
	this->value = value;
	this->Mystep = Mystep;
	this->pnext = nullptr;
}

Polynominal::Polynominal(int step) {
	this->step = step+1;
	Head = nullptr;
}
void Polynominal::dell_coef(int i) {
	Data* tmp = this->Head;
	Data* pred;
	Data* next;
	int counter = 0;
	while (counter != i) {
		if (counter - 1 == i) {
			pred = tmp;
		}
		counter++;
		
	}
	tmp = tmp->pnext;
	pred = tmp->pnext;
	delete tmp;
}
void Polynominal::remove_coef(int i, int coef) {
	if (coef == 0) {
		dell_coef(i);
	}
	int counter = 0;
	Data* tmp = this->Head;
	while (counter != i) {
		counter++;
		tmp = tmp->pnext;
	}
	tmp->value = coef;
}
Polynominal::Data* Polynominal::getHead() const {
	return Head;
}
int Polynominal::get_step()const {
	return step-1;
}
void Polynominal::set_coef(int i, int coef) {
	if (coef == 0) {
		counter_nul++;
	}
	else if (Head == nullptr) {
		Head = new Data(coef, i);
		if (get_step() == counter_nul) {
			
		}
	}
	else {
		Data* tmp = this->Head;

		while (tmp->pnext != nullptr) {
			tmp = tmp->pnext;
		}
		tmp->pnext = new Data(coef, i);
	}
}
ostream&  operator <<(ostream& os,const Polynominal poly) {
	Polynominal::Data* tmp = poly.Head;
	while (tmp !=nullptr) {
		if (tmp->Mystep == 0) {
			os << tmp->value << " + ";
		}
		else {
			os << tmp->value << "x^" << tmp->Mystep << " + ";
		}
		tmp = tmp->pnext;
	}
	//os << tmp->value << "x^" << tmp->Mystep;
	return os;
}
Polynominal Polynominal::operator +(Polynominal other)const {
	Data* tmp_this = this->Head;
	Data* tmp_other = other.Head;
	int max = maximum(this->step, other.step);
	Polynominal tmp(max);
	while ((tmp_this != nullptr) ||(tmp_other!= nullptr)) {
		if ((tmp_this != nullptr) && (tmp_other != nullptr)) {
			if(tmp_this->Mystep<tmp_other->Mystep){
				tmp.set_coef(tmp_this->Mystep, tmp_this->value);
				tmp_this = tmp_this->pnext;
			}
			else if(tmp_this->Mystep > tmp_other->Mystep){
				tmp.set_coef(tmp_other->Mystep, tmp_other->value);
				tmp_other = tmp_other->pnext;
			}
			else {
				tmp.set_coef(tmp_other->Mystep, tmp_other->value+tmp_this->value);
				tmp_other = tmp_other->pnext;
				tmp_this = tmp_this->pnext;
			}
		}
		else if (tmp_this->pnext!= nullptr) {
			tmp.set_coef(tmp_other->Mystep, tmp_other->value);
			tmp_other = tmp_other->pnext;
		}
		else {
			tmp.set_coef(tmp_this->Mystep, tmp_this->value);
			tmp_this = tmp_this->pnext;
		}
	}

	
	return tmp;
}

Polynominal Polynominal::operator -(Polynominal other)const {
	Data* tmp_this = this->Head;
	Data* tmp_other = other.Head;
	int max = maximum(this->step, other.step);
	Polynominal tmp(max );
	while ((tmp_this != nullptr) || (tmp_other != nullptr)) {
		if ((tmp_this != nullptr) && (tmp_other != nullptr)) {
			if (tmp_this->Mystep < tmp_other->Mystep) {
				tmp.set_coef(tmp_this->Mystep, tmp_this->value);
				tmp_this = tmp_this->pnext;
			}
			else if (tmp_this->Mystep > tmp_other->Mystep) {
				tmp.set_coef(tmp_other->Mystep, tmp_other->value);
				tmp_other = tmp_other->pnext;
			}
			else {
				tmp.set_coef(tmp_other->Mystep, tmp_other->value - tmp_this->value);
				tmp_other = tmp_other->pnext;
				tmp_this = tmp_this->pnext;
			}
		}
		else if (tmp_this->pnext != nullptr) {
			tmp.set_coef(tmp_other->Mystep, tmp_other->value);
			tmp_other = tmp_other->pnext;
		}
		else {
			tmp.set_coef(tmp_this->Mystep, tmp_this->value);
			tmp_this = tmp_this->pnext;
		}
	}


	return tmp;
}
Polynominal Polynominal:: operator*(int value) {
	Polynominal tmp (this->get_step());
	Data* tmpD = this->Head;
	for (int i = 0; i < tmp.get_step(); i++) {
		tmp.remove_coef(i, tmpD->value * value);
	}
	return tmp;
}
int Polynominal::valueX(int x) {
	Data* tmp = this->Head;
	int answer=0;
	while (tmp) {
		answer += tmp->value * pow(x,tmp->Mystep);
		tmp = tmp->pnext;
	}
	return answer;
}

int& Polynominal::operator[](int& id) {
	int locale_counter = 0;
	Data* tmp = this->Head;
	while (locale_counter!=id){
		locale_counter++;
		tmp = tmp->pnext;
	}
	return tmp->value;
}

int Polynominal::equation_roots(double*& arr) const {
	Data* tmp = this->Head;
	if (this->get_step() == 2) {
		int coef_s0 = 0;
		int coef_s1 = 0;
		int coef_s2 = 0;
		while (tmp) {
			if (tmp->Mystep == 0) {
				coef_s0 = tmp->value;
				tmp = tmp->pnext;
			}
			else if (tmp->Mystep == 1) {
				coef_s1 = tmp->value;
				tmp = tmp->pnext;
			}
			else if (tmp->Mystep == 2) {
				coef_s2 = tmp->value;
				tmp = tmp->pnext;
			}
		}
		int disc;
		double x1;
		double x2;
		disc = pow(coef_s1, 2) - 4 * coef_s2 * coef_s0;
		if (disc>0) {
			x1=(-coef_s1 +sqrt(coef_s1)) / (2 * coef_s2);
			x2 = (-coef_s1 - sqrt(coef_s1)) / (2 * coef_s2);
			arr[0] = x1;
			arr[1] = x2;
			return 2;
		}
		else if (disc == 0) {
			x1 = (-coef_s1/(2*coef_s2));
			arr[0] = x1;
			return 1;
		}
		else if (disc < 0) {
			string error = "действительных корней нет :(";
			throw error;
		}
	}
	else if (this->get_step() == 1) {
		int coef_s0 = 0;
		int coef_s1 = 0;
		while (tmp) {
			if (tmp->Mystep == 0) {
				coef_s0 = tmp->value;
				tmp = tmp->pnext;
			}
			else if (tmp->Mystep == 1) {
				coef_s1 = tmp->value;
				tmp = tmp->pnext;
			}
		}
		if ((coef_s0 == 0) &&(coef_s1==0)){
			string error = "(- ; +)";
			throw error;
		}
		else if ((coef_s0 == 0) && (coef_s1 == 0)) {
			arr[0] = 0;
			return 1;
		}
		else if ((coef_s0 != 0) && (coef_s1 == 0)) {
			string error = "Корней нет!!!! у нас уравнение вида 0*x = 'value' ";
			throw error;
		}
	}
	else if (this->get_step() == 0) {
		string error = "(- ; +)";
		throw error;
	}
	else if (this->get_step() > 2) {
		string error = "Я не умею решать уровнения больше второй степени -_- ";
		throw error;
	}
}