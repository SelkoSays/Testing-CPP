#include "Array20.h"
#include <iostream>

Array20::Array20(int arr_length)
{
	for (int i = 0; i < 20; i++)
		A[i] = 0;
	size = 20;
	length = arr_length;
}

Array20::Array20(int arr[], int arr_length)
{
	for (int i = 0; i < 20; i++)
	{
		if (i < arr_length)
			A[i] = arr[i];
		else
			A[i] = 0;
	}
	size = 20;
	length = arr_length;
}

Array20::Array20()
{
	for (int i = 0; i < 20; i++)
		A[i] = 0;
	size = 20;
	length = 0;
}

Array20::~Array20()
{

}

void Array20::display()
{
	std::cout << "Elements are\n";
	for (int i = 0; i < this->length; i++)
		std::cout << this->A[i] << " ";
	std::cout << std::endl;
}

void Array20::append(int x)
{
	if (length < size)
		A[this->length++] = x;
}

void Array20::insert(int index, int x)
{
	if (index >= 0 && index <= this->length)
	{
		for (int i = this->length; i > index; i--)
			A[i] = A[i - 1];
		this->A[index] = x;
		this->length++;
	}
}

void Array20::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Array20::Delete(int index)
{
	if (index >= 0 && index <= this->length)
	{
		auto x = A[index];
		for (int i = index; i < this->length - 1; i++)
			this->A[i] = A[i + 1];
		this->length--;
		return x;
	}
}

int Array20::linearSearch(int key)
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->A[i] == key)
		{
			// Improving linear search
			// 1. Transposition
			//swap(&A[i],&A[i-1]);
			// 2. Move to Front
			//swap(&A[i],&A[0]);
			return i;
		}
	}
	return -1;
}