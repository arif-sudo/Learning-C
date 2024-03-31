#include <stdio.h>

int main()
{
    int arr[10] = {1, 6, 3, 7, 2, 6, 17, 78, 23, 10};
    // for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    printf("Value of array is %p\n", arr);
    printf("Value of array is %p\n", &arr);
    printf("Value of array is %p\n\n", &arr[0]);
    printf("Value of arr* is %d\n", *arr);
    printf("Value of *(arr+1) is %d\n", *(arr + 1));
    printf("Value of (*arr)+1 is %d\n", (*arr) + 1);
    return 0;
}
// https://stackoverflow.com/questions/73832320/when-i-point-a-pointer-to-an-array-why-does-the-pointer-and-the-index0-of-the

/* In C and C++, when you declare an array, the name of the array usually decays into a pointer to the first element of the array. 
This pointer holds the memory address of the first element. 
So, in a sense, the array itself does have a memory address because it is represented by the memory address of its first element.
*/