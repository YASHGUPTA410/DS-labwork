// Program for Insertion Sort 

#include<stdio.h>
int main()
{
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int x,j;
	for(int i=1;i<n;i++)
	{
		x=A[i];
		j=i-1;
		while(j>-1&&A[j]>x)
		{
			//shifting lager elements
			A[j+1]=A[j]; 
			j--;
		}
		A[j+1]=x;
	}
	printf("The sorted array is(insertion sort)\n");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}