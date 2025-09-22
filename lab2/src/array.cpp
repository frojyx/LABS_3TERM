#pragma once

#include <iostream>
#include "../includes/utils.h"
#include "../includes/array.h"

Array::Array() :data(nullptr){}

Array::~Array()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

Array::Array(const Array& other):size(other.size)
{
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

Array& Array::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] data;

		size = other.size;
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

Array& Array:: operator++()
{
	for (int i = 0; i < size; i++)
	{
		data[i]++;
	}
	return *this;
}

Array& Array:: operator++([[maybe_unused]] int value)
{
	Array* temp = this;
	for (int i = 0; i < size; i++)
	{
		data[i]++;
	}
	return *temp;
}

void inputArray(Array& arr)
{
	std::cout << "Задайте размер массива: " <<std:: endl;
	while (true)
	{
		while (true) {
			arr.size = validInt();
			if (arr.size<1 || arr.size>kMaxInt) {
				std::cout << "Введите число больше 0:" << std::endl;
				continue;
			}
			break;
		}
		
		if (arr.size < 1) {
			std::cout << "Задайте размер больше единицы.Введите ещё раз:" << std::endl;
		}
		else {
			break;
		}
	}

	std::cout << "Заполните массив." << std::endl;
	arr.data = new int[arr.size];
	for (int i = 0; i < arr.size; i++)
	{
		std::cout << "Элемент " << i + 1 << " равен ";

		while (true) {
			arr.data[i] = validInt();
			if (arr.data[i]<kMinInt || arr.data[i]>kMaxInt) {
				std::cout << "Введите число в диапозоне int:" << std::endl;
				continue;
			}
			break;
		}
		std::cout << std::endl;
	}
}

void showArray(const Array& arr)
{
	if (arr.data == nullptr)
	{
		std::cout << "Заполните массив!";
		return;
	}
	for (int i = 0; i < arr.size; i++)
	{
		std::cout << arr.data[i] << " ";
	}
}

bool increment(Array& arr)
{
	bool temp=true;
	if (arr.data == nullptr){
		std::cout << "Заполните массив!" << std::endl;
		temp = false;
		return temp;
	}
	++arr;
	return temp;
}