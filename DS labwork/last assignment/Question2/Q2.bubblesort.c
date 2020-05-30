// Program for Bubble Sort 

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
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			flag=0;
			//for swaping
			if(A[j]>A[j+1])
			{
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
				flag=1;
			}
		}
		//flag tells whether the array is already sorted or not
		if(flag==0)
			break;
	}
	printf("The sorted array is(bubble sort)\n");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}