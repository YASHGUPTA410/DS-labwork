#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Creation of Binary Search Tree and traversal of node*/

struct node
{
	char  dat[100];
	struct node *rchild;
	struct node *lchild;
}*root=NULL;


struct nodestak
{
	struct node *data;
	struct nodestak *next;
}*top=NULL;


void push(struct node *x)
{
	struct nodestak *temp;
	temp=(struct nodestak *)malloc(sizeof(struct nodestak));
	temp->data=x;
	temp->next=top;
	top=temp;
}

struct node  *pop()
{
	struct nodestak *temp;
	temp=top;
	struct node *x=temp->data;
	top=top->next;
	free(temp);
	return x;
}

char* sttop()
{
	if(top==NULL)
		return "zzzzzz";
	else
		return top->data->dat;

}

struct node* insertnode(char val[100] , struct node *p)
{
	if(p==NULL)
	{
			struct node *t;
			t=(struct node *)malloc(sizeof(struct node));
			strcpy(t->dat,val);
			t->rchild=t->lchild=NULL;
			return t;
	}
	if(strcmp(val,p->dat)<0)
			p->lchild=insertnode(val,p->lchild);
	else
	{
		if(strcmp(val,p->dat)>0&&strcmp(val,sttop())<0)
			p->rchild=insertnode(val,p->rchild);
	}
	return p;
}

void preorder(struct node *p)
{
	if(p)
	{
		printf("%s ",p->dat);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}


void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%s ",p->dat);
		inorder(p->rchild);
	}
}


void postorder(struct node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%s ",p->dat);
	}
}


int main()
{

	printf("Enter the no. of names u want  to enter in binary search tree\n");
	int n;
	int i=0;
	scanf("%d",&n);
	char A[100][100];

	printf("Enter the names of binary search tree in preorder\n");
	fflush(stdin);//To take the enter key char
	for(;i<n;i++)
	{
		scanf("%s",&A[i]);
		fflush(stdin);//To take the enter key char
	}

	
	i=0;
	root=(struct node *)malloc(sizeof(struct node));
	strcpy(root->dat,A[i++]);
	root->rchild=root->lchild=NULL;
	struct node *p=root;
	
	while(i<n)
	{
		if(strcmp(A[i],p->dat)<0)
		{
			struct node *t;
			t=(struct node *)malloc(sizeof(struct node));
			strcpy(t->dat,A[i++]);
			t->rchild=t->lchild=NULL;
			p->lchild=t;
			push(p);
			p=t;
		}
		else
		{
			if(strcmp(A[i],p->dat)>0&&strcmp(A[i],sttop())<0)
			{
				struct node *t;
				t=(struct node *)malloc(sizeof(struct node));
				strcpy(t->dat,A[i++]);
				t->rchild=t->lchild=NULL;
				p->rchild=t;
				p=t;
			}
			else
				p=pop();
		}
	}
	fflush(stdin);
	printf("\nThe preorder traversal is\n");
	preorder(root);

	printf("\n\nThe inorder traversal is\n");
	inorder(root);

	printf("\n\nThe postorder traversal is\n");
	postorder(root);

	char val[100]; 
	printf("\nEnter the name to be inserted in BST\n");
	fflush(stdin);
	scanf("%s",&val);

	insertnode(val , root);

	printf("\nThe preorder traversal is\n");
	preorder(root);

	printf("\n\nThe inorder traversal is\n");
	inorder(root);

	printf("\n\nThe postorder traversal is\n");
	postorder(root);

	return 0;
}