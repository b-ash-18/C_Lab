#include <stdio.h>
#include<stdlib.h>
int n=1;
typedef struct queue{
        int size;
        int arr[5];
        int front,rear;
    }queue;
    
void insert( queue* q);
void delete( queue* q);
void display( queue*q);

int main() {
    
    
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 5;
    q->front = -1;
    q->rear = -1;
    
    
    int i=1;
    while(1){
        int menu;
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter ur choise:");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                insert(q);
                display(q);
                break;
            case 2:
                delete(q);
                display(q);
                break;
            case 3:
                display(q);
                break;
            default:
                printf("Program terminating !!!!!\n");
                return 0;
        }
    }
}

void insert(queue* q){
    if(q->rear == q->size -1){
        printf("Overflow\n");
    }
    else if( q->front == -1 && q->rear == -1){
        q->arr[++(q->rear)] = n++;
        q->front++;
    }
    else{
        q->arr[++q->rear] = n++;
    }
    return ;
}

void delete( queue* q){
    if(q->front == -1){
        printf("Underflow\n");
    }
    else{
        printf("Popped : %d\n",q->arr[(q->front)++]);
    }
    if(q->front > q->rear){
        q->front = -1;
        q->rear = -1;
    }
}

void display( queue*q){
    int i = q->front;
    if(i == -1){
        printf("Empty Queue\n\n");
        return;
    }
    printf("The Queue: ");
    while(i <= q->rear){
        printf("%d\t",q->arr[i]);
        i++;
    }
    printf("\n\n\n");
}
