#include "Array.h"
#include <iostream>

Array::Array(int arr_size, int arr_length)
{
	/*for (int i = 0; i < arr_length; i++)
		A[i] = 0;*/
	this->A = (int*)malloc(arr_size * sizeof(int));
	this->size = arr_size;
	this->length = arr_length;
}

Array::Array(int arr[], int arr_size, int arr_length)
{
	A = (int*)malloc(arr_size * sizeof(int));
	for (int i = 0; i < arr_length; i++)
	{
		this->A[i] = arr[i];
	}
	this->size = arr_size;
	this->length = arr_length;
}

Array::Array(int arr_size)
{
	this->A = (int*)malloc(arr_size * sizeof(int));
	/*for (int i = 0; i < 10; i++)
		A[i] = 0;
	*/
	this->size = arr_size;
	this->length = 0;
}

Array::Array()
{
	this->A = (int*)malloc(10 * sizeof(int));
	/*for (int i = 0; i < 10; i++)
		A[i] = 0;
	*/
	this->size = 10;
	this->length = 0;
}

Array::~Array()
{
	//free(A);
	delete A;
}

void Array::display() const
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
		int x = A[index];
		for (int i = index; i < this->length - 1; i++)
			this->A[i] = A[i + 1];
		this->length--;
		return x;
	}
	return -123456789;
}

int Array::linearSearch(int key) const
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

int Array::lBinSearch(int key) const
{
	int low = 0;
	int high = this->length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == this->A[mid])
			return mid;
		else if (key < this->A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int Array::rBinSearch(int low, int high, int key) const
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == this->A[mid])
			return mid;
		else if (key < this->A[mid])
			return rBinSearch(low, mid - 1, key);
		else
			return rBinSearch(mid + 1, high, key);
	}
	return -1;
}

int Array::get(int index) const
{
	if (index >= 0 && index < this->length)
		return this->A[index];
	return -1;
}

void Array::set(int index, int x)
{
	if (index >= 0 && index < this->length)
		this->A[index] = x;
}

int Array::max() const
{
	int max = this->A[0];
	for (int i = 1; i < this->length; i++)
	{
		if (this->A[i] > max)
			max = this->A[i];
	}
	return max;
}

int Array::min() const
{
	int min = this->A[0];
	for (int i = 1; i < this->length; i++)
	{
		if (this->A[i] < min)
			min = this->A[i];
	}
	return min;
}

int Array::sum() const
{
	int total = 0;
	for (int i = 0; i < this->length; i++)
		total += this->A[i];
	return total;
}

int Array::rSum(int n) const
{
	if (n < 0)
		return 0;
	else
		return rSum(n - 1) + this->A[n];
}

float Array::avg() const
{
	return (float)sum() / this->length;
}

void Array::reverse()
{
	for (int i = 0, j = this->length - 1; i < j; i++, j--)
	{
		swap(&this->A[i], &this->A[j]);
	}
}

void Array::lShift()
{
	for (int i = 0; i < this->length; i++)
	{
		if (i < this->length - 1)
			this->A[i] = this->A[i + 1];
		else
			this->A[i] = 0;
	}
}

void Array::lRotate()
{
	int temp = this->A[0];
	for (int i = 0; i < this->length; i++)
	{
		if (i < this->length - 1)
			this->A[i] = this->A[i + 1];
		else
			this->A[i] = temp;
	}
}

void Array::rShift()
{
	for (int i = this->length - 1; i > 0; i--)
	{
		if (i > 1)
			this->A[i] = this->A[i - 1];
		else
			this->A[i] = 0;
	}
}

void Array::rRotate()
{
	int temp = this->A[this->length - 1];
	for (int i = this->length - 1; i >= 0; i--)
	{
		if (i > 0)
			this->A[i] = this->A[i - 1];
		else
			this->A[i] = temp;
	}
}

void Array::insertSort(int x)
{
	if (this->length == this->size)
		return;

	int i = this->length - 1;
	while (i >= 0 && this->A[i] > x)
	{
		this->A[i + 1] = this->A[i];
		i--;
	}
	this->A[i + 1] = x;
	this->length++;
}

bool Array::isSorted() const
{
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
}


void Array::rearrange()
{
	int i = 0;
	int j = this->length - 1;

	while (i < j)
	{
		while (this->A[i] < 0) { i++; }
		while (this->A[j] >= 0) { j--; }
		if (i < j) { swap(&this->A[i], &this->A[j]); }
	}
}

 Array Array::merge(Array& arr2) const
{
	Array arr3(length + arr2.length, length + arr2.length);
	int i = 0, j = 0, k = 0;

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.get(j))
			arr3.set(k++, A[i++]);
		else
			arr3.set(k++,arr2.get(j++));
	}
	for (; i < length; i++)
		arr3.set(k++, A[i]);
	for (; j < arr2.length; j++)
		arr3.set(k++, arr2.get(j));

	return arr3;
}

 Array Array::Union(Array& arr2) const
 {
	 Array arr3(length + arr2.length);
	 int k = 0;
	 for (int i = 0; i < length; i++)
		arr3.set(k++, A[i]);
	 for (int i = 0; i < arr2.length; i++)
		if (linearSearch(arr2.A[i]) == -1)
			arr3.set(k++, arr2.A[i]);
	 arr3.length = k;
	 return arr3;
 }