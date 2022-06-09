#ifndef _ARRAY10_H_
#define _ARRAY10_H_

class Array10
{
private:
	int A[10];
	int size;
	int length;

public:
	Array10();
	Array10(int arr_length);
	Array10(int arr[], int arr_length);
	~Array10();

	void display();
	void append(int x);
	void insert(int index, int x);
	int Delete(int index);
	int linearSearch(int key);

private:
	void swap(int* x, int* y);
};

#endif