#ifndef _ARRAY_H_
#define _ARRAY_H_
class Array
{
private:
	int* A;
	int size;
	int length;

public:
	Array();
	Array(int arr_size,int arr_length);
	Array(int arr[],int arr_size, int arr_length);
	~Array();

	void display();
	void append(int x);
	void insert(int index, int x);
	int Delete(int index);
	int linearSearch(int key);

private:
	void swap(int* x, int* y);
};

#endif
