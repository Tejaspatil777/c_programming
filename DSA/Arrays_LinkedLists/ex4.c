#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Remove Duplicates from Unsorted Linked List
Write a program to remove duplicates from an unsorted linked list?
Input: 1 -> 2 -> 3 -> 2 -> 4 -> 3
Output: 1 -> 2 -> 3 -> 4
What is the time complexity of your solution for removing duplicates
from the unsorted linked list?*/
typedef struct MyStruct{
    int data;
    struct MyStruct* next;
}S;
S* createList(int n){ 
S* head = (S*)calloc(n,sizeof(S));
if(!head){ 
    printf("Memory Allocation Unsuccessful");
    exit(1);
}
S* p = head;
int value ;
printf("Enter values ---->\n");
for (int i = 1; i <= n; i++){
    scanf("%d",&value);
    if(i == n){ 
        p->data = value;
        p->next = NULL;
        break;
    }
    p->data = value ;
    p->next = p+1;
    p = p->next;
}
p = NULL;
free(p);
return head;
}
S* removeDuplicates(S* head){
   if(!head)printf("Empty List");
   else if(!head->next)printf("list has only one element");
   else{ 
    S* p1 ; S* p2 ; S*f;
    p1 =  head;
    while(p1->next){ 
        p2=p1;
        while(p2->next){
        if(p2->next->data == p1->data){ 
            f = p2->next;
            p2->next = f->next;
            free(f);
            f=NULL;
        }
       else p2 = p2->next;
    }
    p1= p1->next;
    }
   }
   return head;
}
int main(){
int n;
printf("Enter number of elements of lists : ");
scanf("%d",&n);
S* head = createList(n);
head = removeDuplicates(head);
S* ptr = head;
while(ptr){ 
    printf("%d",ptr->data);
    ptr = ptr->next;
}
free(ptr);
return 0;
}