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
	Array(int arr_size);
	Array(int arr_size,int arr_length);
	Array(int arr[],int arr_size, int arr_length);
	~Array();

	void display() const;
	void append(int x);
	void insert(int index, int x);
	int Delete(int index);
	int linearSearch(int key) const;
	int lBinSearch(int key) const;
	int rBinSearch(int low, int high, int key) const;
	int get(int index) const;
	void set(int index, int x);
	int max() const;
	int min() const;
	int sum() const;
	int rSum(int n) const;
	float avg() const;
	void reverse();
	void lShift();
	void lRotate();
	void rShift();
	void rRotate();
	void insertSort(int x);
	bool isSorted() const;
	void rearrange();
	Array merge(Array& arr2) const;
	Array Union(Array& arr2) const;

private:
	void swap(int* x, int* y);
};

#endif
