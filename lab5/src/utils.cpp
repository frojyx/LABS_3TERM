#include "../includes/utils.h"

template <typename T>
void swap(int firstInd, int secondInd, T* arr)
{
	T temp = arr[firstInd];
	arr[firstInd] = arr[secondInd];
	arr[secondInd] = temp;
}

template <typename T>
void runProgram(const char* name)
{
	int size;
	int i1;
	int i2;
	std::cout << "Work with " << name << " type." << std::endl;
	while (true)
	{
		size = getValue<int>("Enter size : ");
		if (size > 0) break;
		std::cout << "Size must be positive. Please try again\n";
	}

	auto* arr = new T[size];
	inputArray(arr, size);
	outputArray(arr, size);

	inputIndexes(i1, i2, size);
	swap(i1, i2, arr);

	outputArray(arr, size);

	delete[] arr;
}

void inputIndexes(int& i1, int& i2, int size)
{
	std::cout << "\nEnter indexes for swap:" << std::endl;
	while (true)
	{
		i1 = getValue<int>("Enter first index : ");
		if (i1 > -1 && i1 < size) break;
		std::cout << "Size must be non-negative and smaller size. Please try again\n";
	}
	while (true)
	{
		i2 = getValue<int>("Enter second index : ");
		if (i2 > -1 && i2 < size && i2 != i1) break;
		std::cout << "Size must be non-negative, smaller size and not equal first index. Please try again\n";
	}
}

template void runProgram<int>(const char* name);
template void runProgram<double>(const char* name);
template void runProgram<char>(const char* name);

