#include <iostream>
#include "Collection.h"
#include "polynomial_template.h"
#include <conio.h>
using namespace std;

int menu1()
{
	cout << "\n\t'->' - Cледуюий элемент\n\t'<-' - предыдуший элемент"; // 77 75 ok===============
	cout << "\n\t[1] - добавить многочлен";								// 49 ok=============================================
	cout << "\n\t[2] - значение при данном Х";							// 50 ок===========================================
	cout << "\n\t[3] - удалить все элементы";							// 51 ок============================================
	cout << "\n\t[4] - сложение двух многочленов";						// 52 ОК============================================
	cout << "\n\t[5] - разность двух многочленов";						// 53 ОК============================================
	cout << "\n\t[6] - умножить многочлен на вещественное число";		// 54 ОК==========================
	cout << "\n\t[7] - обратиться к коэффициенту по индексу";			// 55 ОК
	cout << "\n\t[8] - поиска корней 1 и 2 степеней";					// 56
	cout << "\n\t[BackSpace] - удалить элемент по индексу";				// 8 ОК===============================
	cout << "\n\n\tEsc - Назад";										// 27============================================================
	while (true)
	{
		int key = _getch();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 8) || (key == 77) || (key == 75))
		{
			return key;
		}
	}
}

int menu1_null()
{
	cout << "\n\t'->' - Cледуюий элемент\n\t'<-' - предыдуший элемент"; // 77 75 ok
	cout << "\n\t[1] - добавить многочлен";								// 49 ok
	cout << "\n\t[2] - значение при данном Х";							// 50 ок
	cout << "\n\t[3] - удалить все элементы";							// 51 ок
	cout << "\n\t[4] - сложение двух многочленов";						// 52 ОК
	cout << "\n\t[5] - разность двух многочленов";						// 53 ОК
	cout << "\n\t[6] - умножить многочлен на вещественное число";		// 54 ОК
	cout << "\n\t[7] - обратиться к коэффициенту по индексу";			// 55 ОК
	cout << "\n\t[8] - поиска корней 1 и 2 степеней";					// 56 ОК
	cout << "\n\t[BackSpace] - удалить элемент по индексу";				// 8 ОК
	cout << "\n\n\tEsc - Назад";										// 27
	while (true)
	{
		int key = _getch();
		if ((key == 27) || (key == 49))
		{
			return key;
		}
	}
}

template <typename T>
T check()
{
	T number = 0;

	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			system("cls");
			cout << "\tВведите корректное число: ";
		}
	}
	return number;
}

template <typename T>
void add_collection(Collection<T>& coll, int& size)
{
	system("cls");
	size++;
	int step;
	cout << "\n\n\t\t Введите степень многочлена: ";
	step = check<int>(); b
	while ((step <= 0) || (step > 55))
	{
		system("cls");
		cout << "\n\n\t\tВведите еще раз степень многочлена: ";
		step = check<int>();
	}
	system("cls");
	cout << "Степень многочлена:  " << step << "\n";
	Polynominal<T> tmp(step);
	T value;
	for (int i = 0; i <= step; i++)
	{
		cout << "\tкоэффициет перед х^" << i << " - ";
		value = check<T>();
		tmp.set_coef(i, value);
	}
	coll.add_collection(tmp);
}

template <typename T>
void roots(Polynominal<T> coll)
{
	system("cls");
	T* root = new T[2];
	try
	{
		int root_counter = coll.equation_roots(root);
		cout << "\n\n\n\t\t" << coll;
		for (int i = 0; i < root_counter; i++)
		{
			cout << "\n\t\t\t x" << i + 1 << " = " << root[i];
		}
	}
	catch (string problem)
	{
		cout << problem;
	}
	cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
	_getch();
}

template <typename T>
int MainMenu()
{
	int size = 0;
	int i = 0;
	int index;
	Collection<T> coll;
	T x;
	T value;
	T c;
menu1:
	system("cls");
	if (coll.get_size_coll() == 0)
	{
		i = 0;
		cout << ("\t\t\t <Холодильник пуст>  ^_^");
		int m1 = menu1_null();
		switch (m1)
		{
		case 27:
			return 0;
		case 49:
			add_collection(coll, size);
			goto menu1;
		}
	}
	else
	{
		cout << "index [" << i << "]"
			<< "\t\t\t\t";
		cout << coll[i] << " = 0";
		int m1 = menu1();
		switch (m1)
		{
		case 27:
			return 0;
		case 50: // valueX 
			system("cls");
			cout << "\n\n\n\t\t\t\t\tВведите значение Х: ";
			x = check<T>();
			value = coll[i].valueX(x);
			cout << "\n\n\t\t\t";
			cout << coll[i];
			cout << "\tПри Х = " << x << " == " << value;
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 51: // all delete
			coll.delete_collection();
			goto menu1;
		case 52: // сложение двух многочленов
			system("cls");
			int index;
			cout << "\n\n\t\t Введите индекс многочлена, который нужно сложить с текущим: ";
			index = check<int>();
			while ((index > size - 1) || (index < 0))
			{
				cout << "\n\n\t\t Введите еще раз индекс многочлена, который нужно сложить с текущим, так как такого индекса нет: ";
				index = check<int>();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] + coll[index];
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 53: // разность двух многочленов
			system("cls");
			cout << "\n\n\t\t Введите индекс многочлена, который нужно вычесть из текуего: ";
			index = check<int>();
			while ((index > size - 1) || (index < 0))
			{
				cout << "\n\n\t\t Введите еще раз индекс многочлена, который нужно сложить с текущим, так как такого индекса нет: ";
				index = check<int>();
			}
			cout << "\n\n\n\t\t" << coll[i] << "\n\t\t+++++++++++++++++++\n\t\t" << coll[index] << "\n\t\t===============================\n\t\t" << coll[i] - coll[index];
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 8: // удаление элемента из коллекции 
			coll.delete_index(i);
			goto menu1;
		case 77: // стрелочки ОК 
			if (i == (coll.get_size_coll() - 1))
			{
				goto menu1;
			}
			else
			{
				i++;
				goto menu1;
			}
		case 54: // умножить многочлен на вещественное число
			system("cls");
			cout << "\n\n\n\t\t\t Введите число на которое нужно умножить многочлен: ";
			c = check<T>();
			if (c == T(0)) {
				cout << "\n\n\t\t( " << coll[i] << ") * " << c << " = 0";
			}
			else {
				cout << "\n\n\t\t( " << coll[i] << ") * " << c << "\n\t\t======================================\n\t\t" << coll[i] * c;
			}
			cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
			_getch();
			goto menu1;
		case 55: // обратиться к коэффициенту по индексу
			system("cls");
			int id;
			cout << "\n\n\n\t\tВведите индекс коэффициента к которому хотите обратиться \n\t\t\t" << coll[i] << "\n\t\t\t index :";
			cin >> id;
			try
			{
				cout << "\t\t\t\t = " << coll[i][id];
				cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
				_getch();
				goto menu1;
			}
			catch (string problem)
			{
				cout << "\n\n\t\t" << problem;
				cout << "\n\n\t\t\tНАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ПРОДОЛЖИТЬ ";
				_getch();
				goto menu1;
			}

		case 56: // поиска корней 1 и 2 степеней
			roots(coll[i]);
			goto menu1;
		case 75: // стрелочки ОК
			if (i == 0)
			{
				goto menu1;
			}
			else
			{
				i--;
				goto menu1;
			}
		case 49: // добавить многочлен  OK====================================
			add_collection(coll, size);
			goto menu1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	while (true)
	{
		system("cls");
		cout << "\n\t\tВыберете тип данных для ваших многочленов:";
		cout << "\n\t\t\t[1] - int";
		cout << "\n\t\t\t[2] - float" ;
		cout << "\n\t\t\t[3] - double" ;
		cout << "\n\t\t\t[4] - complex (float)";
		cout << "\n\t\t\t[5] - complex (double)";
		cout << "\n\t\t\t[ESC] - Выход";
		
		int Choice = _getch();
		switch (Choice)
		{
		case 49:
			MainMenu<int>();
			break;
		case 50:
			MainMenu<float>();
			break;
		case 51:
			MainMenu<double>();
			break;
		case 52:
			MainMenu<complex<float>>();
			break;
		case 53:
			MainMenu<complex<double>>();
			break;
		case 27:
			return 0;
		}
	}
}