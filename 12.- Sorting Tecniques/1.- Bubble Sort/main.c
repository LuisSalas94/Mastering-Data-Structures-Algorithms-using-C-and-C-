#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int A[])
{
     for(int i = 0; i<10; i++)
    {
        printf("%d ", A[i]);
    }
}



void Bubble(int A[], int n)
{
    int i, j, flag = 0;

    for(i = 0; i<n-1; i++)
    {
        flag = 0;
        for(j = 0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }

        if(flag == 0)break;
    }
}

void Insertion(int A[], int n)
{
    int i, j, x;

    for(i = 1; i<n; i++)
    {
        j = i-1;
        x = A[i];

        while(j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n)
{
    int i, j, k;

    for(i = 0; i<n-1; i++)
    {
        for(j = k = i; j<n; j++)
        {
            if(A[j] < A[k])
            {
                k = j;
            }
        }

        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        }while(A[i] <= pivot);

        do
        {
            j--;
        }while(A[j] > pivot);

        if(i < j)
        {
            swap(&A[i], &A[j]);
        }

    }while(i < j);

    swap(&A[l], &A[j]);
    return j;
}


void Quicksort(int A[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = partition(A, l, h);
        Quicksort(A, l, j);
        Quicksort(A, j+1, h);
    }
}


void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid+1, k = l;

    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    for(; i<=mid; i++)
    {
        B[k++] = A[i];
    }

    for(; j<=h; j++)
    {
        B[k++] = A[j];
    }

    for(int i = l; i<=h; i++)
    {
        A[i] = B[i];
    }

}


void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for(p = 2; p <= n; p = p*2)
    {
        for(i = 0; i+p-1 < n; i = i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
    }

    if(p/2 < n)
    {
        Merge(A, 0, p/2-1, n-1);
    }
}

void MergeSort(int A[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}



int main()
{
    int A[] = {13,7,9,10,6,5,12,4,11,2}, n = 10, i;
    MergeSort(A, 0, 9);
    display(A);

    return 0;
}
