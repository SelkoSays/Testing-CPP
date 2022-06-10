#include "Array.h"
#include <iostream>

Array::Array(int arr_size, int arr_length)
{
	/*for (int i = 0; i < arr_length; i++)
		A[i] = 0;*/
	A = (int*)malloc(arr_size * sizeof(int));
	size = arr_size;
	length = arr_length;
}

Array::Array(int arr[], int arr_size, int arr_length)
{
	A = (int*)malloc(arr_size * sizeof(int));
	for (int i = 0; i < arr_length; i++)
	{
			A[i] = arr[i];
	}
	size = arr_size;
	length = arr_length;
}

Array::Array()
{
	A = (int*)malloc(10 * sizeof(int));
	/*for (int i = 0; i < 10; i++)
		A[i] = 0;
	*/
	size = 10;
	length = 0;
}

Array::~Array()
{
	free(A);
}

void Array::display()
{
	std::cout << "Elements are\n";
	for (int i = 0; i < this->length; i++)
		std::cout << this->A[i] << " ";
	std::cout << std::endl;
}

void Array::append(int x)
{
	if (length < size)
		A[this->length++] = x;
}

void Array::insert(int index, int x)
{
	if (index >= 0 && index <= this->length)
	{
		for (int i = this->length; i > index; i--)
			A[i] = A[i - 1];
		this->A[index] = x;
		this->length++;
	}
}

void Array::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Array::Delete(int index)
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

int Array::linearSearch(int key)
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