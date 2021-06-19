#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

//display function
void display(struct Array arr)
{
    for(int i = 0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

//swap function
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//append function
void append(struct Array *arr, int x)
{
    //validation
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

//insert function
void insert(struct Array *arr, int index, int x)
{
    for(int i = arr->length; i>index; i--)
    {
        //shift elements of the array
        arr->A[i] = arr->A[i-1];
    }

    //set new value
    arr->A[index] = x;

    //increment array's length
    arr->length++;
}


//delete function
int deleteFun(struct Array *arr, int index)
{
     int x = 0;
    //validation
    if(index >= 0 && index <  arr->length)
    {
       //index at a given position
       x = arr->A[index];
       for(int i = index; i<arr->length-1; i++)
       {
           arr->A[i] = arr->A[i+1];
       }
       arr->length--;
       return x;
    }

    return 0;
}

//LinearSearch function
int linearSearch(struct Array arr, int key)
{
    for(int i = 0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }

    return -1;
}

//ImprovedLinearSearch function
int ImprovedLinearSearch(struct Array *arr, int key)
{
    for(int i = 0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            //transposition method
            //Swap(&arr->A[i], &arr->A[i-1]);

            //move to front/head method
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }

    return -1;
}

//binarySearch function
int binarySearch(struct Array arr, int key)
{
    int low = 0;
    int hight = arr.length-1;

    while(low <= hight)
    {
        int mid = (low+hight)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            hight = mid-1;
        }
        else
        {
            low = mid+1;
        }

    }

    return -1;

}


int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};

    //append function
    //append(&arr, 6);

    //insert function
    //insert(&arr, 4, 27);

    //delete function
    //deleteFun(&arr, 3);

    //LinearSearch function
    //printf("Key was found at index: %d", ImprovedLinearSearch(&arr, 3));

    //binarySearch function
    printf("Element found at index: %d", binarySearch(arr, 5));

    //display function
    //display(arr);

    return 0;
}
