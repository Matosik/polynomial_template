#include <iostream>
#include "Collection.hpp"
#include "polynomial_tamplate.hpp"
#include <conio.h>
using namespace std;

int menu0() {
	cout << "\n\t[1] - Работа с int ";
	cout << "\n\t[2] - Работа с float";
	cout << "\n\t[3] - Работа с double;";
	cout << "\n\t[4] - Работа с complex<float>;";
	cout << "\n\t[5] - Работа с complex<double>;";
	cout << "\n\n\tesc - Выход";
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

int menu1_null() {
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
		if ((key == 27) || (key == 49) ) {
			return key;
		}
	}
}

int check()
{
	int number = 0;

	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "\tВведите корректное число: ";
		}
	}
	return number;
}
void add_collection(Collection &coll,int& size){
	system("cls");
	size++;
	int step;
	cout << "\n\n\t\t Введите степень многочлена: ";
	step=check();
	while ((step <= 0) || (step > 55)) {
		system("cls");
		cout << "\n\n\t\tВведите еще раз степень многочлена: ";
		step = check();
	}
	system("cls");
	cout << "Степень многочлена:  "<< step<<"\n";
	Polynominal tmp(step);
	int value;
	for (int i = 0; i <= step; i++) {
		cout << "\tкоэффициет перед х^" << i << " - ";
		cin >> value;
		tmp.set_coef(i,value);
	}
	coll.add_collection(tmp);

}
void roots(Collection coll,int i) {
	system("cls");
	double* root = new double[2];
	try {
		int root_counter = coll[i].equation_roots(root);
		cout << "\n\n\n\t\t" << coll[i];
		for (int i = 0; i < root_counter; i++) {
			cout << "\n\t\t\t x" << i + 1 << " = " << root[i];
		}
	}
	catch (string problem) {
		cout << problem;
	}
	cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
	_getch();
}
int main() {
	setlocale(LC_ALL, "RUS");
	int size = 0;
	int i = 0;
	int index;
	Collection coll;
menu1:
	system("cls");
	if (coll.get_size_coll()==0) {
		i = 0;
		cout << ("\t\t\t <Холодильник пуст>  ^_^");
		int m1 = menu1_null();
		switch (m1) {
		case 27:
			return 0;
		case 49:
			add_collection(coll, size);
			goto menu1;
		}
	}
	else {
		cout << "index [" << i << "]" << "\t\t\t\t";
		cout << coll[i] << " = 0";
		int m1 = menu1();

		switch (m1) {
		case 27:
			return 0;
		case 50: //valueX ====================================================
			system("cls");
			int x;
			int value;
			cout << "\n\n\n\t\t\t\t\tВведите значение Х: ";
			x = check();
			value = coll[i].valueX(x);
			cout << "\n\n\t\t\t";
			cout << coll[i];
			cout << "\tПри Х = " << x << " == " << value;
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 51: // all delete============================================================
			coll.delete_collection();
			goto menu1;
		case 52:// сложение двух многочленов 
			system("cls");
			int index;
			cout << "\n\n\t\t Введите индекс многочлена, который нужно сложить с текущим: ";
			index = check();
			while((index > size - 1) || (index < 0)) {
				cout << "\n\n\t\t Введите еще раз индекс многочлена, который нужно сложить с текущим, так как такого индекса нет: ";
				index = check();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] + coll[index];
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 53://разность двух многочленов ===================================================
			system("cls");
			cout << "\n\n\t\t Введите индекс многочлена, который нужно вычесть из текуего: ";
			index = check();
			while ((index > size - 1) || (index < 0)) {
				cout << "\n\n\t\t Введите еще раз индекс многочлена, который нужно сложить с текущим, так как такого индекса нет: ";
				index = check();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] - coll[index];
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 8:// удаление элемента из коллекции =========================================
			coll.delete_index(i);
			goto menu1;
		case 77:// стрелочки ОК ==========================================================
			if (i == (size - 1)) {
				goto menu1;
			}
			else {
				i++;
				goto menu1;
			}
		case 54:// умножить многочлен на вещественное число==================================
			system("cls");
			int c;
			cout << "\n\n\n\t\t\t Введите число на которое нужно умножить многочлен: ";
			c = check();
			cout << "\n\n\t\t" << coll[i] << " * " << c << "\n\t\t======================================\n\t\t" << coll[i] * c;
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 55:// обратиться к коэффициенту по индексу
			system("cls");
			int id;
			cout << "\n\n\n\t\tВведите индекс коэффициента к которому хотите обратиться \n\t\t\t" << coll[i] << "\n\t\t\t index :";
			cin >> id;
			cout << "\t\t\t\t = " << coll[i][id];
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
			
		case 56://поиска корней 1 и 2 степеней
			roots(coll,i);
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
			add_collection(coll, size);
			goto menu1;
		}
	}
	return 0;
}