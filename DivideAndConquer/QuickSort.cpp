/********************************************************************
Author: daidi@live.cn
Date:10/22/2013
Description: 快速排序
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 9

int sort(int A[],int start,int end)
{
	int x=A[start];
	int low=start,high=end;
	while(low<high)
	{
		while(A[high]>=x&&low<high)
			high--;
		if(low<high)
		{
			A[low]=A[high];
			low++;
		}
		while(A[low]<x&&low<high)
			low++;
		if(low<high)
		{
			A[high]=A[low];
			high--;
		}
	}
	A[low]=x;
	return low;
}

void QuickSort(int A[],int start,int end)
{
	if(start<end)
	{
		int x=sort(A,start,end);
		QuickSort(A,start,x-1);
		QuickSort(A,x+1,end);
	}
}

int main()
{
	int i;
	int A[N]={2,5,4,7,3,1,9,8,6};
	QuickSort(A,0,N-1);
	for(i=0;i<N;i++)
		printf("%d ",A[i]);
	return 0;
}