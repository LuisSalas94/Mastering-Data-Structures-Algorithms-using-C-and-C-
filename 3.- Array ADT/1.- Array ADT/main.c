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


//reverse array function, using aux. array
void reverFun(struct Array *arr)
{
    int *B;
    int i, j;

    B = (int*)malloc(arr->length*sizeof(int));
    for(i = arr->length-1, j = 0; i>=0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for(i = 0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}



//reverse array function, using swap fun
void reverFun2(struct Array *arr)
{
    int i, j;
    for(i = 0, j= arr->length-1; i<j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}


//insert an element in a sorted position
void insertFun(struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)
    {
        return;
    }

    while(i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }

    arr->A[i+1] = x;
    arr->length++;
}


//check is array is sorted funtion
int isSorted(struct Array arr)
{
    for(int i = 0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}


//rearrange positive and negative elements from array
void REarrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;

    while(i < j)
    {
        while(arr->A[i] < 0)
        {
            i++;
        }

        while(arr->A[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

//merge two arrays function
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    //create third array in heap
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    //copy all the elements by comparing one by one
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    //copy remaining elements from the arrays
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    //increment arr3 length
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;

}


//union two arrays function
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    //create third array in heap
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    //copy all the elements by comparing one by one
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    //copy remaining elements from the arrays
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    //increment arr3 length
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

//intersection two arrays function
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    //create third array in heap
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    //copy all the elements by comparing one by one
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    //increment arr3 length
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


//difference two arrays function
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    //create third array in heap
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

    //copy all the elements by comparing one by one
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    //copy remaining elements from the arrays
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    //increment arr3 length
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int main()
{
    //struct Array arr = {{2,-3,25,10,-15, -7},20,6};
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
    printf("Average of the array is: %d", avgFun(arr));
    reverFun(&arr);
    reverFun2(&arr);
    insertFun(&arr, 24);
    printf("%d", isSorted(arr));
    REarrange(&arr);
    */

    /*
    MERGE FUNCTION
    create new arrays for mergin function
    struct Array arr1 = {{1,6,10,15,25},10,5};
    struct Array arr2 = {{3,4,7,18,20},10,5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    */

    /*
    //UNION FUNCTION
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;
    arr3 = Union(&arr1, &arr2);
    */

    /*//INTERSECTION FUNCTION
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;
    arr3 = Intersection(&arr1, &arr2);
    */

    //DIFFERENCE FUNCTION
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;
    arr3 = Difference(&arr1, &arr2);


    Display(*arr3);

    return 0;
}
