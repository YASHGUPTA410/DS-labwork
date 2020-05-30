/*Write a C program that uses function to perform following:
1. Create a singly linked list of integers.
2. Delete a given integer from the above linked list.
3. Display the contents of the above list after deletion.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*link;
}*first=NULL;

void create (int A [], int n)
{
	int i;
	struct node *t, *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->data=A [0];
	p->link=NULL;
	first=p;

	for (int i = 1; i <n; i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->link=NULL;
		p->link=t;
		p=t;	
	}
}

void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
}
void deleteindex(struct node *p, int index)
{
	struct node *q=NULL;
    int  i;
    for(i=0; i<index-1; i++)
    {
       q=p;
       p=p->link;
    }
    q->link=p->link;
    free(p);
}

int main()
{            
 int  A[100],n, i, m ,r ,x, y;
 printf("Enter the number of values you want to enter \n");
 scanf ("%d", &n);
 printf("Enter the data values\n");
 for (int i = 0; i < n; i++)
 {
 	scanf("%d",&A[i]);
 }
 create(A ,n);
 printf("The elements in the linked list are:\n");
 display(first);
 printf("\n");
 printf("Enter the index which you want to delete:\n");
 scanf("%d",&m);
 deleteindex(first,m);
 printf("The new linked list is:\n");
 display(first);
 printf("\n"); 
 return 0;
} 