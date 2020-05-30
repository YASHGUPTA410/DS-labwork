/*Write a C program that uses function to perform following:
1. Create a doubly linked list of integers.
2. Delete a given integer from the above doubly linked list.
3. Display the contents of the above list after deletion.*/

#include <stdio.h>
#include <stdlib.h>

struct doublyLinkedList
{
  int data;
  struct doublyLinkedList *next;
  struct doublyLinkedList *prev;
}*first;

void create(int n)
{
  struct doublyLinkedList *p=first;
  p=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &p->data);
  p->next=NULL;
  p->prev=NULL;
  first=p;

  while(n--)
  {
  struct doublyLinkedList *t;
  t=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &t->data);
  t->next=NULL;
  t->prev=p;
  p->next=t;
  p=t;
  }
}

void display(struct doublyLinkedList *p)
{
  while(p)
  {
    printf("%d\t", p->data);
    p=p->next;
  }
}

void deleteRandom(int a)
{
  struct doublyLinkedList *p,*temp=first;
  p=first;
  for(int i=1;i<a;i++)
  {
    temp=p;
    p=p->next;
  }

  temp->next = p->next;
  p->next->prev=temp;
  free(p);
}

int main ()
{
  int x,n;
  printf("Enter the number of data user want to enter\n");
  scanf("%d", &n);
  printf("Enter the  data you want to enter\n");
  create(n-1);
  printf("The initial double linked list is:\n");
  display(first);
  printf("\n");
  printf("\nEnter the position of integer to be deleted\n");
  scanf("%d",&x);
  printf("The final double linked list after deletion : \n"); 
  deleteRandom(x);
  display(first);
  return 0;
}