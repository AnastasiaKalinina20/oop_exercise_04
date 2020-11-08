# pragma once

#include <iostream>
#include <string.h>
#include <utility>

using namespace std;

template <class T>
class Triangle{
public:
	pair<T, T> arr[3];
	string type = "Triangle";
};

template <class T>
class Square{
public:
	string type = "Square ";
	pair<T, T> arr[4];
};

template <class T>
class Rectangle{
public:
	pair<T, T> arr[4];
	string type = "Rectangle";
};