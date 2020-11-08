# pragma once

#include <string.h>
#include <utility>
#include <iostream>
#include <cmath>
#include <tuple>
#include "template_classes.hpp"

using namespace std;

// area for each figure
template <class T>
double calcArea(T& item){
	 if(item.type == "Triangle"){
		double ab = sqrt(pow((item.arr[1].first - item.arr[0].first), 2) + pow((item.arr[1].second - item.arr[0].second), 2));
		double bc = sqrt(pow((item.arr[2].first - item.arr[1].first), 2) + pow((item.arr[2].second - item.arr[1].second), 2));
		double ac = sqrt(pow((item.arr[2].first - item.arr[0].first), 2) + pow((item.arr[2].second - item.arr[0].second), 2));
		double p = 0.5 * (ab + bc + ac);
        double S = sqrt(p * (p - ab) * (p - bc) * (p - ac));
        return S;
	}
	double tmp = (item.arr[1].first - item.arr[0].first) + (item.arr[1].second - item.arr[0].second);
	double t = (item.arr[2].first - item.arr[1].first) + (item.arr[2].second - item.arr[1].second);
	return fabs(tmp * t);

}

// summ of areas
template <class T, size_t index>
double areaTuple(T& tuple){
    auto item = get<index>(tuple);
    double value = calcArea(item);
    if constexpr ((index+1) <tuple_size<T>::value) {
        return value + areaTuple<T, index + 1>(tuple);
    }

    return value;
}

// печать на экран фигуры
template <class T>
void displayFigure(T& figure){
		for(auto points: figure.arr){
			cout << "(" << points.first << ", " << points.second << ")";
			cout << " ";
		}
	cout << endl;
}

// печать на экран tuple
template<class T, size_t idx>
void displayTuple(T& tuple){
	if constexpr(idx < tuple_size<T>::value) {
		auto figure = get<idx>(tuple);
		cout << figure.type << " \t";
		displayFigure(figure);
		displayTuple<T, idx + 1>(tuple);
	}
}