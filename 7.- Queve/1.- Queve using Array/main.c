#include <stdio.h>
#include <stdlib.h>

struct Queve
{
    int size;
    int front;
    int rear;
    int *Q;
};

//create queve
void create (struct Queve *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size*sizeof(int));
}

//circular queve
void create2 (struct Queve *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int*)malloc(q->size*sizeof(int));
}


void enqueve(struct Queve *q, int x)
{
    if(q->rear == q->size-1)
    {
        printf("Queve is Full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

//circular queve
void enqueve2(struct Queve *q, int x)
{
    if((q->rear+1)%q->size == q->front)
    {
        printf("Queve is Full");
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}


int dequeve(struct Queve *q)
{
    int x = -1;

    if(q->front == q->rear)
    {
        printf("Queve is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}


//circular queve
int dequeve2(struct Queve *q)
{
    int x = -1;

    if(q->front == q->rear)
    {
        printf("Queve is Empty\n");
    }
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}


void Display(struct Queve q)
{
    for(int i = q.front+1; i<=q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

//circular queve
void Display2(struct Queve q)
{
   int i = q.front+1;

   do
   {
      printf("%d ", q.Q[i]);
      i = (i+1)%q.size;

   }while(i!=(q.rear+1)%q.size);

    printf("\n");
}

int main()
{
    struct Queve q;
    create2(&q, 5);
    enqueve2(&q, 10);
    enqueve2(&q, 20);
    enqueve2(&q, 30);
    Display2(q);
    printf("Element deleted is: %d ", dequeve(&q));


    return 0;
}
