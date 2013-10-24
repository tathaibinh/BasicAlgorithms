/********************************************************************
Author: daidi@live.cn
Date:10/24/2013
Description: 给定一个数组S[n]和整数x，判断S中是否有两个元素的和为x。
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

bool FindSum(int A[],int n,int sum)
{
	int i;
	mergeSort(A,0,n-1);
	for(i=0;i<n;i++)
		if(BinarySearch(A,0,n-1,sum-A[i])!=-1)
			return true;
	return false;
}

int main()
{
	int i;
	int A[N]={2,5,4,7,3,1,9,8,6};
	if(FindSum(A,N,17))
		printf("有！");
	else
		printf("没有！");	
	return 0;
}
