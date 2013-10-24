/********************************************************************
Author: daidi@live.cn
Date:10/24/2013
Description: 二分查找
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 9

int BinarySearch(int A[],int start,int end,int x)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		if(A[mid]==x)
			return mid;
		else if(A[mid]<x)
			return BinarySearch(A,mid+1,end,x);
		else
			return BinarySearch(A,start,mid-1,x);
	}
	else if(start==end)
	{
		if(A[start]==x)
			return start;
		else
			return -1;
	}
	else
		return -1;
}

int main()
{
	int i;
	int A[N]={1,2,3,4,5,6,7,8,9};
	i=BinarySearch(A,0,N-1,7);
	printf("%d ",i);
	return 0;
}
