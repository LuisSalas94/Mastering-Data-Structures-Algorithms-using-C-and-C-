#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;

//creation of linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//creating 2 linked list
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i = 1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}



//display function
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//recursive display
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}


//count function - length of linked list
int count(struct Node *p)
{
    int length = 0;
    while(p)
    {
        length++;
        p = p->next;
    }

    return length;
}


//recursive count function
int Rcount(struct Node *p)
{
    if(p!=NULL)
    {
        return Rcount(p->next)+1;
    }
    else
    {
        return 0;
    }
}

//sum function
int sum(struct Node *p)
{
    int sum = 0;
    while(p!=NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//recursive sum function
int Rsum(struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next)+p->data;
    }
}

//max. element fun
int max(struct Node *p)
{
    int m = -32768;

    while(p)
    {
        if(p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }

    return m;
}

//recursive max. element fun
int Rmax(struct Node *p)
{
    int x = 0;
    int m = -32768;

    if(p == 0)
    {
        return m;
    }
    else
    {
        x = Rmax(p->next);
        if(x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

//linear search
struct Node* LSearch(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;

};

//Recursive linear search
struct Node* RLSearch(struct Node *p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }

    if(key == p->data)
    {
        return p;
    }

    return RLSearch(p->next, key);
};

//Insert for linked list
void Insert(struct Node *p, int index, int x)
{
    //create a new node
    struct Node *t;
    int i;

    //validate for index
    if(index < 0 || index > count(p))
    {
        return;
    }

    t = (struct Node*)malloc(sizeof(struct Node));
    //fill data
    t->data = x;

    //link new node in linked list
    //if index is less than zero, it should be in the left hand site
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        //insert at some given position
        for(i = 0; i<index-1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

//insert new node in a sorted linked list
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }

    }
}

//delete node
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if(index < 1 || index > count(p))
    {
        return -1;
    }

    //delete first index
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i = 0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;

        x = p->data;

        free(p) ;

        return x;

    }
}

//checked if linked list is sorted
int isSorted(struct Node *p)
{
    int x = -65536;

    while(p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }

        x = p->data;
        p = p->next;
    }

    return 1;
}

//remove duplicate from a sorted list
void RemoveDuplicate(struct Node *p)
{
   struct Node *q = p->next;

   while(q!=NULL)
   {
       if(p->data != q->data)
       {
           p = q;
           q = q->next;
       }
       else
       {
           p->next = q->next;
           free(q);
           q = p->next;
       }
   }

}

//reversing link
void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int*)malloc(sizeof(int)*count(p));

    while(q!=NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;

    while(q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

}


//reverse link using sliding pointers
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}


//reverse using recursion
void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}


//concatenate two linked list
void Concat(struct Node *p, struct Node *q)
{
    third = p;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = q;
}

//merge two linked list
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;

    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }


    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;

        }
    }

    if(p)last->next = p;
    if(q)last->next = q;

}



int main()
{

    int A[] = {10, 20, 30, 40 ,50};
    int B[] = {5, 15, 25, 35, 45};
    create(A, 5);
    create2(B, 5);

    //Display(first);
    //printf("Lenght is: %d", count(first));
    //printf("Lenght is: %d", Rcount(first));
    //printf("Sum is: %d", sum(first));
    //printf("Sum is: %d", Rsum(first));
    //printf("Max element is: %d", Rmax(first));
    //Insert(first, 8, 10);
    //SortedInsert(first, 35);
    //printf("Deleted Element %d\n", Delete(first, 4));
    //printf("%d\n", isSorted(first));
    //RemoveDuplicate(first);
    //Reverse3(NULL, first);
    /*
    struct Node *temp;
    temp = RLSearch(first, 15);
    if(temp)
    {
        printf("Key was found");
    }
    else
    {
        printf("Key was not found");
    }
    */

    /*
    Concat(second, first);
    printf("Concatinated\n");
    Display(third);
    printf("\n\n");
    */

    Merge(first, second);
    Display(third);



    return 0;
}
