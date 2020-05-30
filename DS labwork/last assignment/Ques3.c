//Ptogram for  Sorting of string using Merge Sort
//For sorting string proprly I will be ignoring the spaces and convert the string to lowercase as string characters are compared using ascii values
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//this function merges values from sorted arrays to array B
void merge(int A[],int l,int m,int h)
{
	int B[100];
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];
	for(int x=l;x<=h;x++)
		//copying of merged values to original array
		A[x]=B[x];
}

//recursive function of mergesort 
void mergesort(int A[],int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(A,l,m);
		mergesort(A,m+1,h);
		merge(A,l,m,h);
	}
}
int main()
{
	
	char A[100];
	int Z[100];
	printf("Enter the String\n");
	//Clearing The Buffer
	fflush(stdin);
	gets(A);
	int n=strlen(A);
	int i=0;
	while(A[i]!='\0')
	{
		//converting string to lowercase
		A[i]=tolower(A[i]);
		Z[i]=A[i];
		i++;
	}	
	mergesort(Z,0,n-1);
	printf("The sorted String is(merge sort)\n");
	for(int i=0;i<n;i++)
		{
			if(Z[i]==' ') continue;//ignoring spaces
			printf("%c",Z[i]);
		}
	return 0;
}