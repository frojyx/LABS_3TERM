#pragma once
#include <iostream>

template <typename T> void swap(int firstInd, int secondInd, T* arr);
template <typename T> void runProgram(const char* name);
void inputIndexes(int& i1, int& i2, int size);

template <typename T>
T getValue(const char* prompt) {
	T value;
	std::cout << prompt;

	while (true) {
		if (std::cin >> value) {
			if (std::cin.get() == '\n') {
				return value;
			}
			std::cin.clear();
			while (std::cin.get() != '\n' && !std::cin.eof());
			std::cout << "Invalid input. Please enter a valid value: ";
		}
		else {
			std::cin.clear();
			while (std::cin.get() != '\n' && !std::cin.eof());
			std::cout << "Invalid input. Please enter a valid value: ";
		}
	}
}

template <typename T>
void inputArray(T* arr, int size)
{
	std::cout << "\nEnter " << size << " elements ." << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter " << i + 1 << " element : ";
		arr[i] = getValue<T>(" ");
	}
}

template <typename T>
void outputArray(T* arr, int size)
{
	std::cout << "\nArray:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
