/********************************************************************
Author: daidi@live.cn
Date:10/22/2013
Description: 归并排序
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 9

void merge(int A[],int start,int mid,int end)
{
	int temp[N];
	int i=start,j=mid+1,k=0;
	while(i<=mid&&j<=end)
	{
		if(A[i]<A[j])
			temp[k++]=A[i++];
		else
			temp[k++]=A[j++];
	}
	while(i<=mid)
		temp[k++]=A[i++];
	while(j<=end)
		temp[k++]=A[j++];
	for(i=end;i>=start;i--)
		A[i]=temp[--k];
}

void mergeSort(int A[],int start,int end)
{
	if(start<end)
	{
	int mid=(start+end)/2;
	mergeSort(A,start,mid);
	mergeSort(A,mid+1,end);
	merge(A,start,mid,end);
	}
}

int main()
{
	int i;
	int A[N]={2,5,4,7,3,1,9,8,6};
	mergeSort(A,0,N-1);
	for(i=0;i<N;i++)
		printf("%d ",A[i]);
	return 0;
}
