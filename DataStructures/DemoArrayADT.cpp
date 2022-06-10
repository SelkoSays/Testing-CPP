#include <iostream>
#include <cstdlib>

void Swap(int*,int*);

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
    for(int i = 0; i < arr.length; i++)
        std::cout << arr.A[i] << " ";
}

void Append(struct Array* arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x)
{
    if(index>=0 && index <= arr->length)
    {
        for(int i = arr->length; i > index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}


int Delete(struct Array* arr, int index)
{
    if(index>=0 && index <= arr->length)
    {
        auto x = arr->A[index];
        for(int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
}

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array* arr, int key)
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

int main()
{
    struct Array arr = {{2,3,4,5,6},20,5};

    //Insert(&arr,5,10);
    //Append(&arr,10);
    //std::cout << Delete(&arr,1) << std::endl;
    std::cout << LinearSearch(&arr,6) << std::endl;
    Display(arr);

    std::cout << std::endl;
    return 0;
}