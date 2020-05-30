// Program for Quick Sort

#include<stdio.h>
#include<limits.h>

//This function returns the index at which partition is done
int split(int A[],int l,int h)
{
	int x=A[l];
	int i=l;
	int j=h;
	do
	{
		do {i++;}
		while(A[i]<=x);

		do {j--;}
		while(A[j]>x);

		if(i<j)
		{
			int t=A[j];
			A[j]=A[i];
			A[i]=t;
		}

	}
	while(i<j);

	int t=A[j];
	A[j]=A[l];
	A[l]=t;

	return j;
}

void quicksort(int A[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=split(A,l,h);
		quicksort(A,l,j);
		quicksort(A,j+1,h);
	}
}

int main()
{
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int A[n+1];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	//Assigning max value to last position of array
	A[n]=INT_MAX; 
	quicksort(A,0,n);
	printf("The sorted array is(quick sort)\n");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}