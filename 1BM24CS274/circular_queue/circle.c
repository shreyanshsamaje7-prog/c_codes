#include<stdio.h>
#include<ctype.h>

#define max_size 5
int front=-1,rear=-1;

int q[max_size];

void enqueue(int item){
    if(front== (rear+1)% max_size){
        printf("queue is full\n");
    }
    else if(rear==-1){
        front=0;
        rear=0;
        q[rear]=item;
    }
    else {
        rear=(rear+1)%max_size;
        q[rear]=item;

    }
}

int dqueue(){
    int item;
    if(front==-1){
        printf("queue is empty\n");
    }
    else if(front == rear){
        item=q[front];
        front=-1;
        rear=-1;
        return item;
    }
    else{
        item= q[front];
        front=(front+1)% max_size;
        return item;
    }
}

void dis(){
    if(front==-1){
        printf("queue is empty\n");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d ",q[i]);
            i=(i+1)%max_size;
        }
        printf("%d",q[i]);
    }
}

void main(){
    int n;
    int ch,item;
    printf("enter number of elements: ");
    scanf("%d",&n);
    printf("enter elements");
    for(int i=0;i<n;i++){
        scanf("%d",&item);
        enqueue(item);
    }



    while(1){
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter the element : ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2:printf("deleted item: %d",dqueue());
                    break;
            case 3:dis();
                    break;

            case 4:printf("exiting");
                exit(0);
             default:printf("invalid choice");
                    break;

        }
    }
}






