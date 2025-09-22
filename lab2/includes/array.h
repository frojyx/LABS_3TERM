#pragma once

#include <iostream>
#include "../includes/utils.h"

class Array{
private:
	int* data;
	int size=0;
public:
	friend void inputArray(Array& arr);
	friend void showArray(const Array& arr);
	friend bool increment(Array& arr);

	Array();
	~Array();
	Array(const Array& other);
	Array& operator=(const Array& other);
	Array& operator++();
	Array& operator++(int value);
};

