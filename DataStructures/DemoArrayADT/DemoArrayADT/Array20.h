#ifndef _ARRAY20_H_
#define _ARRAY20_H_

#include <vector>

class Array20
{
private:
	int A[20];
	int size;
	int length;

public:
	Array20();
	Array20(int arr_length);
	Array20(int arr[], int arr_length);
	~Array20();

	void display();
	void append(int x);
	void insert(int index, int x);
	int Delete(int index);
	int linearSearch(int key);

private:
	void swap(int* x, int* y);
};

#endif