#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*front, *rear;

void enqueve(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Queve is Full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeve()
{
    int x = -1;
    struct Node *t;

    if(front == NULL)
    {
        printf("Queve is Empty\n");
    }
    else
    {
       x = front->data;
       t = front;
       front = front->next;
       free(t);
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueve(10);
    enqueve(20);
    enqueve(30);
    enqueve(40);
    enqueve(50);
    Display();
    printf("Element deleted is: %d", dequeve());

    return 0;
}
