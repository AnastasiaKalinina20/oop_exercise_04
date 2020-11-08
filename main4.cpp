/*
Калинина анастасия М8О-208Б
Создать программу, которая позволяет:
·  Создавать набор фигур согласно варианту задания 
	(как минимум по одной фигуре каждого типа с координатами типа int и координатами типа double).
·  Сохранять фигуры в std::tuple
·	Печатать на экран содержимое std::tuple с помощью шаблонной функции print.
·	Вычислять суммарную площадь фигур в std::tuple и выводить значение на экран.
 
При реализации шаблонных функций допускается использование вспомогательных шаблонов 
std::enable_if, std::tuple_size, std::is_same.

Вариант №1: Треугольник, квадрат, прямоугольник
*/

#include <iostream>
#include <cmath>
#include <tuple>
#include <utility>
#include <string.h>
#include "template_classes.hpp"
#include "functions.hpp"

using namespace std;

int main(){

	// area = 0.5
	Triangle<double> tr;
	tr.arr[0] = {2, 4};
	tr.arr[1] = {0, 3};
	tr.arr[2] = {1, 4};

	// area = 1.69
	Square<double> sq1;
	sq1.arr[0] = {1.6, 2.8};
	sq1.arr[1] = {1.6, 4.1};
	sq1.arr[2] = {2.9, 4.1};
	sq1.arr[3] = {2.9, 2.8};

	// area = 14
	Rectangle<double> rect;
	rect.arr[0] = {-1, 0};
	rect.arr[1] = {-1, 7};
	rect.arr[2] = {2, 7};
	rect.arr[3] = {2, 0};
	
	Rectangle<double> rect2;
	rect2.arr[0] = {-3, 1};
	rect2.arr[1] = {-3, 2};
	rect2.arr[2] = {4, 2};
	rect2.arr[3] = {4, 1};

	// area = 5.5
	Triangle<int> tr2;
	tr2.arr[0] = {-2, 0};
	tr2.arr[1] = {1, 2};
	tr2.arr[2] = {0, 5};

	// area = 4
	Square<int> sq2;
	sq2.arr[0] = {-1, -1};
	sq2.arr[1] = {-1, 1};
	sq2.arr[2] = {1, 1};
	sq2.arr[3] = {1, -1};


	tuple<decltype(tr), decltype(sq1), decltype(rect), decltype(rect2), decltype(tr2), decltype(sq2)> tup{tr, sq1, rect, rect2, tr2, sq2};
	cout << "Summ of areas " << areaTuple<decltype(tup),0>(tup) << endl;
	displayTuple<decltype(tup),0>(tup);
	return 0;
}
