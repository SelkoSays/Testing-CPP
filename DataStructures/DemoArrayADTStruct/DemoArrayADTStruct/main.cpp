#include <iostream>
//#include <cstdlib>
#include <malloc.h>

void Swap(int*, int*);

struct Array
{
	//int *A;
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr)
{
	std::cout << "Elements are\n";
	for (int i = 0; i < arr.length; i++)
		std::cout << arr.A[i] << " ";
}

void Append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x)
{
	if (index >= 0 && index <= arr->length)
	{
		for (int i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}


int Delete(struct Array* arr, int index)
{
	if (index >= 0 && index <= arr->length)
	{
		int x = arr->A[index];
		for (int i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	return -123456789;
}

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(const struct Array* const arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (arr->A[i] == key)
		{
			// 1. Transposition
			//Swap(&(arr->A[i]),&(arr->A[i-1]));
			// 2. Move to Front
			//Swap(&arr->A[i],&arr->A[0]);
			return i;
		}
	}
	return -1;
}

/**
 * Binary search using iteration
 *
 * @param struct Array (sorted), desired element of the array
 * @return index of desired element,
 * or if not found returns -1
 */
int LBinSearch(struct Array arr, int key)
{
	int low = 0;
	int high = arr.length - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

/**
 * Binary search using recursion
 *
 * @param struct Array (sorted), inidex 0/start of the array, array.length-1, desired element of the array
 * @return index of desired element, or if not found returns -1
 */
int RBinSearch(int arr[], int low, int high, int key)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			return RBinSearch(arr, low, mid - 1, key);
		else
			return RBinSearch(arr, mid + 1, high, key);
	}
	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = x;
}

/**
* Unordered array
* @param Array
* @return max
*/
int Max(struct Array arr)
{
	int max = arr.A[0];
	for (int i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}
/**
* Unordered array
* @param Array
* @return min
*/
int Min(struct Array arr)
{
	int min = arr.A[0];
	for (int i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}

int LSum(struct Array arr)
{
	int total = 0;
	for (int i = 0; i < arr.length; i++)
		total += arr.A[i];
	return total;
}

int RSum(int arr[], int n)
{
	if (n < 0)
		return 0;
	else
		return RSum(arr, n - 1) + arr[n];
}

float Avg(struct Array arr)
{
	return (float)LSum(arr) / arr.length;
}

/**
* Reverse with auxiliary array
* @param struct Array*
*/
void AReverse(struct Array* arr)
{
	int* B;

	B = (int*)malloc(arr->length * sizeof(int));
	for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (int i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
	free(B);
}

void Reverse(struct Array* arr)
{
	for (int i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		Swap(&arr->A[i], &arr->A[j]);
	}
}

void LShift(struct Array* arr)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (i < arr->length - 1)
			arr->A[i] = arr->A[i + 1];
		else
			arr->A[i] = 0;
	}
}

void LRotate(struct Array* arr)
{
	int temp = arr->A[0];
	for (int i = 0; i < arr->length; i++)
	{
		if (i < arr->length - 1)
			arr->A[i] = arr->A[i + 1];
		else
			arr->A[i] = temp;
	}
}

void RShift(struct Array* arr)
{
	for (int i = arr->length - 1; i > 0; i--)
	{
		if (i > 1)
			arr->A[i] = arr->A[i - 1];
		else
			arr->A[i] = 0;
	}
}

void RRotate(struct Array* arr)
{
	int temp = arr->A[arr->length - 1];
	for (int i = arr->length - 1; i >= 0; i--)
	{
		if (i > 0)
			arr->A[i] = arr->A[i - 1];
		else
			arr->A[i] = temp;
	}
}

/**
* Insert into sorted array
* @param struct Array*, value x
*/
void InsertSort(struct Array* arr, int x)
{
	if (arr->length == arr->size)
		return;

	int i = arr->length - 1;
	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

bool isSorted(struct Array arr)
{
	for (int i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return false;
	}
	return true;
}

/**
* Rearranges negatives on the left and positives on the right
* @param struct Array*
*/
void Rearrange(struct Array* arr)
{
	int i = 0;
	int j = arr->length - 1;

	while (i < j)
	{
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--; }
		if (i < j) { Swap(&arr->A[i], &arr->A[j]); }
	}
}


struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
	int i = 0, j = 0, k = 0;
	//int m = arr1->length, n = arr2->length;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	/*int* arr3;
	arr3 = (int*)malloc((n + m) * sizeof(int));*/

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	//free(arr3);

	return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	int k = 0;
	for (int i = 0; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (int i = 0; i < arr2->length; i++)
		if (LinearSearch(arr1, arr2->A[i]) == -1)
			arr3->A[k++] = arr2->A[i];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* UnionS(struct Array* arr1, struct Array* arr2)
{
	int i = 0, j = 0, k = 0;
	//int m = arr1->length, n = arr2->length;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	/*int* arr3;
	arr3 = (int*)malloc((n + m) * sizeof(int));*/

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = k;
	arr3->size = 10;
	//free(arr3);

	return arr3;
}

struct Array* IntersectionS(struct Array* arr1, struct Array* arr2)
{
	int i = 0, j = 0, k = 0;
	//int m = arr1->length, n = arr2->length;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	/*int* arr3;
	arr3 = (int*)malloc((n + m) * sizeof(int));*/

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	arr3->length = k;
	arr3->size = 10;
	//free(arr3);

	return arr3;
}

struct Array* DifferenceS(struct Array* arr1, struct Array* arr2)
{
	int i = 0, j = 0, k = 0;
	//int m = arr1->length, n = arr2->length;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	/*int* arr3;
	arr3 = (int*)malloc((n + m) * sizeof(int));*/

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	arr3->length = k;
	arr3->size = 10;
	//free(arr3);

	return arr3;
}

int main()
{
	struct Array arr1 = { {2, 6, 10, 15, 25}, 10, 5 };
	struct Array arr2 = { {3, 6, 7, 15, 20}, 10, 5 };
	struct Array* arr3;

	//Insert(&arr,5,10);
	//Append(&arr,10);
	//std::cout << Delete(&arr,1) << std::endl;
	//std::cout << RBinSearch(arr.A, 0,arr.length, 5) << std::endl;
	//std::cout << Get(arr,9) << std::endl;
	//Set(&arr, 0, 15);
	//std::cout << Avg(arr) << std::endl;
	//std::cout << std::boolalpha;
	//std::cout << isSorted(arr) << std::endl;
	//RRotate(&arr);
	//Rearrange(&arr);
	//Display(arr);
	arr3 = DifferenceS(&arr1, &arr2);
	Display(*arr3);

	std::cout << std::endl;
	return 0;
}