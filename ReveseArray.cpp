#include <iostream>
#include <vector>

template <typename T>
void reverse(std::vector<T> *vec)
{
    //std::cout << "Hello\n";
    size_t vec_size = vec->size();
    for (size_t i = 0; i < (vec_size/2);i++)
    {
        auto temp = vec->at(i);
        vec->at(i) = vec->at(vec_size-i-1);
        vec->at(vec_size-i-1) = temp;
    }
}

void reverse(int* array, int arr_size)
{
    //std::cout << "Holla\n";
    for (size_t i = 0; i < arr_size/2;i++)
    {
        int temp = array[i];
        //std::cout << temp << std::endl;
        array[i] = array[arr_size-i-1];
        //std::cout << array[i] << std::endl;
        array[arr_size-i-1] = temp;
    }
}

int main() {
    //std::cout << "Hello world!";
    std::vector<int> vec {1,2,3,4,5};
    for (auto i: vec)
        std::cout << i << " ";
    std::cout<<std::endl;
    reverse(&vec);
    for (auto i: vec)
        std::cout << i << " ";
    //std::cout << vec[0] << std::endl;
    std::cout<<std::endl;
    int arr[] {1,2,3,4,4,5,6,7,8,9};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    for (auto i: arr)
        std::cout << i << " ";
    std::cout<<std::endl;
    //std::cout << sizeof(A)/sizeof(A[0]) << std::endl;
    reverse(arr,arr_size);
    for (auto i: arr)
        std::cout << i << " ";
    
    return 0;
}