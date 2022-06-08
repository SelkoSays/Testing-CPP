#include <iostream>
#include <cstdlib>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(Array arr)
{
    int i;
    std::cout << "Elements are\n";
    for(int i = 0; i < arr.length; i++)
        std::cout << arr.A[i] << " ";
}

int main()
{
    struct Array arr;
    int n{};
    std::cout << "Enter size of an array: ";
    std::cin >> arr.size;
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    std::cout << "Enter number of numbers: ";
    std::cin >> n;

    std::cout << "Enter all Elements\n";
    for(int i = 0; i < n; i++)
        std::cin >> arr.A[i];

    arr.length=n;

    display(arr);

    return 0;
}