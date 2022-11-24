#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
#include "Polynomial.h"
#include <conio.h>
using namespace std;


int check()
{
	int number = 0;

	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n'){
			system("cls");
			cout << "\tВведите корректное число: ";
		}
	}
	return number;
}

int menu1() {
	cout << "\n\t'->' - Cледуюий элемент\n\t'<-' - предыдуший элемент";//77 75 ok===============
	cout << "\n\t[1] - добавить многочлен";// 49 ok=============================================
	cout << "\n\t[2] - значение при данном Х";//50 ок===========================================
	cout << "\n\t[3] - удалить все элементы";//51 ок============================================
	cout << "\n\t[4] - сложение двух многочленов";//52 ОК============================================
	cout << "\n\t[5] - разность двух многочленов";//53 ОК============================================
	cout << "\n\t[6] - умножить многочлен на вещественное число";//54 ОК==========================
	cout << "\n\t[7] - обратиться к коэффициенту по индексу";//55 ОК
	cout << "\n\t[8] - поиска корней 1 и 2 степеней";//56
	cout << "\n\t[BackSpace] - удалить элемент по индексу";//8 ОК===============================
	cout << "\n\n\tEsc - Выход";//27============================================================
	while (true) {
		int key = _getch();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 8) || (key == 77) || (key == 75)) {
			return key;
		}
	}
}

void add_collection(Polynominal**& coll, int& size) {
	system("cls");
	size++;
	int step;
	cout << "\n\tВведите степень многочлена: ";
	step=check();
	while ((step <= 0) || (step > 55)) {
		system("cls");
		cout << "\n\tВведите еще раз степень многочлена: ";
		step = check();
	}
	coll = (Polynominal**)realloc(coll, size * sizeof(Polynominal*));
	Polynominal* tmp = new Polynominal;
	tmp->set_step(step);
	for (int i = 0; i <= step; i++) {
		double ch;
		cout  << "\tкоэффициет перед х^" << i<<" : ";
		ch = check();
		tmp->set_coef(ch, i);
	}
	coll[size - 1] = tmp;
}

void all_delete(Polynominal**& coll, int& size, int& i) {
	delete[] coll;
	i = 0;
	size = 0;
	coll = NULL;
}

void delete_index(Polynominal**& coll, int& index, int& size) {
	delete coll[index];
	for (int i = index; i < size - 1; i++)
	{
		coll[i] = coll[i + 1];
	}
	size--;
	index = 0;
	coll = (Polynominal**)realloc(coll, (size) * sizeof(Polynominal*));
}

void summa(Polynominal** coll,const int size) {
	system("cls");
	if (size == 1) {
		cout << "\n\n\n\t\t\t У вас в холодильнике всего 1 элемент :(";
		cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
		_getch();
		return;
	}
	int i, j;
	cout << "\n\n\n\t\t\tВведите индекс многочлена к которому прибавить второй многочлен: ";
	cin>> i ;
	while ((i < 0) || (i >= size)) {
		system("cls");
		cout << "\n\n\n\t\tInvalid Index, введите индекс многочлена к которому прибавить второй многочлен, ещё раз: ";
		cin >> i;
	}
	cout << "\n\n\n\t\t\tВведите индекс многочлена который нужно прибавить к первому многочлену: ";
	cin >> j;
	while ((j < 0) || (j >= size)) {
		system("cls");
		cout << "\n\n\n\t\tInvalid Index, Введите индекс многочлена который нужно прибавить к первому многочлену, ещё раз: ";
		cin >> j;
	}
	Polynominal temp;
	temp = *coll[i] + *coll[j];
	cout << "\n\n\t\t";
	cout<<*coll[i];
	cout << "\n\t\t++++++++++++++++++++++++\n\t\t";
	cout<<*coll[j];
	cout << "\n\t\t================= \n\t\t";
	cout<<temp;
	cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
	_getch();

}

void difference(Polynominal** coll, const int size) {
	system("cls");
	if (size == 1) {
		cout << "\n\n\n\t\t\t У вас в холодильнике всего 1 элемент :(";
		cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
		_getch();
		return;
	}
	int i, j;
	cout << "\n\n\n\t\t\tВведите индекс многочлена, из которого нужно вычесть второй многочлен: ";
	i = check();
	while ((i < 0) || (i >= size)) {
		system("cls");
		cout << "\n\n\n\t\tInvalid Index, Введите индекс многочлена, из которого нужно вычесть второй многочлен, ещё раз: ";
		i = check();
	}
	cout << "\n\n\n\t\t\tВведите индекс многочлена, который нужно вычесть из первого многочлена: ";
	j = check();
	while ((j < 0) || (j >= size)) {
		system("cls");
		cout << "\n\n\n\t\tInvalid Index, Введите индекс многочлена, который нужно вычесть из первого многочлена, ещё раз: ";
		j = check();
	}
	Polynominal temp;
	temp = *coll[i] - *coll[j];
	cout << "\n\n\t\t";
	cout<<*coll[i];
	cout << "\n\t\t-----------------------\n\t\t";
	cout<<*coll[j];
	cout << "\n\t\t================= \n\t\t";
	cout<<temp;
	cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
	_getch();
}

void multiplication(Polynominal coll) {
	system("cls");
	double c;
	cout << "\n\n\n\t\t\t Введите вещественное число на которое нужно умножить многочлен: ";
	c = check();
	Polynominal temp;
	temp = coll * c;
	cout << "\n\n\t многочлен ";
	cout<<coll;
	cout << " умноженный на число с = " << c << "\t===\t\n\t========\n\t";
	cout<<temp;
	cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
	_getch();
}

void roots(Polynominal* coll) {
	system("cls");
	double len;
	double* tmp = new double[2];
	cout << "\n\n\n\t\t\t ";
	cout<<*coll;
	cout << " = 0 \tкорень  = ";
	try {
		len = coll->equation_roots(tmp);
		for (int i = 0; i < len; i++) {
			cout << "x" << i + 1 << " = " << tmp[i] << " ";
		}
	}
	catch (string problem) {
		cout << "\n\n\n\t\t\t\t" << problem;
	}
	delete[] tmp;
}

void coef(Polynominal coll) {
	system("cls");
	int id;
	cout << "\n\n\n\t\t\tВведите индекс к которому хотиет обратиться: ";
	id = check();
	cout << "\n\n\t\t";
	cout<<coll;
	cout << " ==== " << coll[id];
	cout << "При " << "\t id = " << id;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int size = 0;
	int i = 0;
	Polynominal** collection = NULL;
menu1:
	system("cls");
	if (collection == NULL) {
		cout << ("\t\t\t <Холодильник пуст>  ^_^");
		int m1 = menu1();
		switch (m1) {
		case 27:
			return 0;
		case 50:
			goto menu1;
		case 51:
			goto menu1;
		case 52:
			goto menu1;
		case 53:
			goto menu1;
		case 54:
			goto menu1;
		case 55:
			goto menu1;
		case 56:
			goto menu1;
		case 8:
			goto menu1;
		case 77:
			goto menu1;
		case 75:
			goto menu1;
		case 49:
			add_collection(collection, size);
			goto menu1;
		}
	}
	else {
		cout << "index [" << i << "]" << "\t\t\t\t";
		cout<<*collection[i]<<" = 0";
		int m1 = menu1();

		switch (m1) {
		case 27:
			return 0;
		case 50: //valueX ====================================================
			system("cls");
			double x;
			double value;
			cout << "\n\n\n\t\t\t\t\tВведите значение Х: ";
			x = check();
			value = collection[i]->valueX(x);
			cout << "\n\n\t\t\t";
			cout<<*collection[i];
			cout << "\tПри Х = " << x << " == " << value;
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 51: // all delete============================================================
			all_delete(collection, size, i);
			goto menu1;
		case 52:// сложение двух матриц ==================================================
			summa(collection, size);
			goto menu1;
		case 53://разность двух матриц ===================================================
			difference(collection, size);
			goto menu1;
		case 8:// удаление элемента из коллекции =========================================
			delete_index(collection, i, size);
			goto menu1;
		case 77:// стрелочки ОК ==========================================================
			if (i == (size - 1)) {
				goto menu1;
			}
			else {
				i++;
				goto menu1;
			}
		case 54:// умножить матрицу на вещественное число==================================
			multiplication(*collection[i]);
			goto menu1;
		case 55:// обратиться к коэффициенту по индексу
			coef(*collection[i]);
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 56://поиска корней 1 и 2 степеней
			roots(collection[i]);
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 75:// стрелочки ОК==========================================
			if (i == 0) {
				goto menu1;
			}
			else {
				i--;
				goto menu1;
			}
		case 49:// добавить многочлен  OK====================================
			add_collection(collection, size);
			goto menu1;
		}
	}
	return 0;
} 