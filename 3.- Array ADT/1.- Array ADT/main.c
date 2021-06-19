#include <stdio.h>
#include <stdlib.h>

struct Array
{
    //int *A;
    int A[10];
    int size;
    int length;
};

//display function
void Display(struct Array arr)
{
    printf("Elements are\n");
    for(int i = 0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

//append(at the end of the array) function, call by address 'cause it'll modify array
void Append(struct Array *arr, int x)
{
    //check for enought space
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

//insert function, x = value to be inserted
void Insert(struct Array *arr, int index, int x)
{
    //validation for a proper index
    if(index >= 0 && index <= arr->length)
    {
        //shift elements to provide a free space
        for(int i = arr->length; i>index; i--)
        {
            //transfer elements
            arr->A[i] = arr->A[i-1];
        }

        arr->A[index] = x;
        arr->length++;
    }
}

//delete function, delete an element from a given index
int Delete(struct Array *arr, int index)
{
    int x = 0;

    //check for validation
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(int i = index; i<arr->length-1; i++)
        {
            //copy elements
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

//swap function
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


//linear search function
int LinearSearch(struct Array arr, int key)
{
    for(int i = 0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    //element is not found
    return -1;
}

//linear search improved
int ImprovedLinearSearch(struct Array *arr, int key)
{
    for(int i = 0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            //transposition method
            //swap(&arr->A[i], &arr->A[i-1]);

            //move to head method
            swap(&arr->A[i], &arr->A[0]);

            return i;
        }
    }
    return -1;
}


//binary search(iteractive version), call by value
int BinarySearch(struct Array arr, int key)
{
    int low, mid, height;
    low = 0;
    height = arr.length-1;

    while(low <= height)
    {
        mid = (low+height)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            height = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }

    return -1;
}


int RBinSearch(int a[], int low, int height, int key)
{
    int mid;
    if(low <= height)
    {
        mid = (low+height)/2;
        if(key == a[mid])
        {
            return mid;
        }
        else if(key < a[mid])
        {
            return RBinSearch(a, low, mid-1, key);
        }
        else
        {
            return RBinSearch(a, mid+1, height, key);
        }
    }
    return -1;
}

//get function
int getFun(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

}

//set function
int setFun(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
    return x;
}

//max function
int maxFun(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }

    return max;
}

//min function
int minFun(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }

    return min;
}


//sum function
int sumFun(struct Array arr)
{
    int total = 0;

    for(int i = 0; i<arr.length; i++)
    {
        total = total + arr.A[i];

    }

    return total;
}

//avg function
int avgFun(struct Array arr)
{
    int total = 0;
    int n = arr.length;

    for(int i = 0; i<arr.length; i++)
    {
        total+=arr.A[i];
    }

    return total = total / n;
}

int main()
{
    //hardcore an array
    struct Array arr = {{22,23,4,15,6},20,5};
    /*int n;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    //create array in heap
    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter number of numbers");
    scanf("%d", &n);

    printf("Enter all Elements\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    arr.length = n;

    Append(&arr, 10);
    Insert(&arr, 2, 10);
    printf("%d\n", Delete(&arr, 0));
    printf("key found at index: %d\n", ImprovedLinearSearch(&arr, 5));
    printf("key found at index: %d\n", LinearSearch(arr, 6));
    printf("Key found at index: %d\n", BinarySearch(arr, 4));
    printf("Key found at index: %d\n", RBinSearch(arr.A, 0, arr.length, 5));
    printf("Element is %d", getFun(arr, 2));
    printf("Element is: %d", setFun(&arr, 0, 27));
    printf("Max. element is: %d", maxFun(arr));
    printf("Min. element is: %d", minFun(arr));
    printf("Sum of the elements is: %d", sumFun(arr));
    */

    printf("Average of the array is: %d", avgFun(arr));




    //Display(arr);

    return 0;
}
