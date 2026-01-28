#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Exercise 2
Design a Queue with O(1) getMin() Operation:
Design a queue data structure that supports standard
enqueue and dequeue operations, along with a getMin()
function that returns the minimum element in O(1) time.
Describe the additional data structures used and how they
maintain the minimum efficiently.*/
int Q[100],n;
int front = -1;
int rear = -1;
void NQ(int key){ 
if((rear+1)%n==front) printf("Q is full");
else{
    if(rear==-1){
        front=rear=0;
        Q[rear]=key;
    }
    else{
        rear=(rear+1)%n;
        Q[rear]=key;
    }
}
}
int DQ(){
if(front==-1){
    printf("Q is empty");
    exit(1);
}
else{
int x=Q[front];
if(front==rear) front=rear=-1;
else front=(front+1)%n;
return x;
}
}
void display(){
int i = front;
for(int j = 1;j <= n;j++){
    printf("%d ",Q[i]);
    i = (i+1)%n;
}
}

int main(){
int key;

    scanf("%d", &n);

    printf("Enter Q elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        NQ(key);
    }
    display();
    return 0;
}