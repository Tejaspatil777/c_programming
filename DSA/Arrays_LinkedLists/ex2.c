#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*You are tasked with performing operations on two types of
linked lists: a doubly linked list, and a circular linked list.
Complete the following tasks:
Create doubly linked list and circular linked list with the
elements [5, 15, 25, 35].
a) Insert 20 at the beginning of the list.
b) Delete the node containing 25 and display the final list*/
typedef struct Circular{
    int data;
    struct Circular* nxt;
}C;
typedef struct Doubly{
    struct Doubly* prev;
    int data;
    struct Doubly* nxt;
}D;
C* createCircular(){ 
   
}
D* createDoubly(){ 
 
}
C* insertAtBeg(C* head,int n){ 

}
int main(){
C* head = createCircular();
C* p = head;
    for(int i= 1;i<=4;i++){ 
        printf("%d\t",p->data);
        p=p->nxt;
    }
     p = head;
    D* head1 = createDoubly();
    D* ptr = head1;
    for(int i= 1;i<=4;i++){ 
        printf("%d\t",ptr->data);
        ptr=ptr->nxt;
    }
head = insertAtBeg(head , 20);
head1 = insertAtBeg(head1,20);
return 0;
}