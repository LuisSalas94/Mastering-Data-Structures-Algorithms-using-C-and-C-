#include <stdio.h>
#include <stdlib.h>

//create Array Struct
struct Array
{
    int *A;
    int size;
    int length;
};


//display function
void display(struct Array arr)
{
    printf("\nElements of the array are: ");
    for(int i = 0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int main()
{
    //create struct array
    struct Array arr;

    //create variable to store numbers of elements
    int n;

    //get size of array
    printf("Enter size of array: \n");
    scanf("%d", &arr.size);

    //create array in heap
    arr.A = (int*)malloc(arr.size*sizeof(int));

    //initialize array's length
    arr.length = 0;

     //get number of elements
     printf("Enter number of array elements: \n");
     scanf("%d", &n);

    //insert elements into array
    printf("Insert elements of the array: \n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    //set new array's length
    arr.length = n;

    //call display function
    display(arr);


    return 0;
}
