#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *l;
	struct node *r;
}new;

struct node* create_tree()
{
	int x;
	 struct node *root=(struct node*)malloc(sizeof(new));
	printf("Enter the data for the nodes(-1 if it is a end node)\n");
	scanf("%d",&x);
 	if(x==-1)	
    	 return NULL;
  	root->data=x;
    printf("Enter the left child data for node\n");
    root->l=create_tree();
    printf("Enter the right child data for node\n");      
    root->r=create_tree();
    return root;

}
void postorder(node *t)
{
	if(t)
	{
		printf("%d ",t->data);
		postorder(t->l);
		postorder(t->r);
	}
}
int main()
{
	node *mainroot=create_tree();
	node *t=mainroot;
	printf("postorder traversal of this binary tree is \n");
	postorder(temp);
	return 0;
}