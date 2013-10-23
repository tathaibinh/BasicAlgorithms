/********************************************************************
Author: daidi@live.cn
Date:10/22/2013
Description: 查找第k大元素
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
		while(A[high]<=x&&low<high)
			high--;
		if(low<high)
		{
			A[low]=A[high];
			low++;
		}
		while(A[low]>x&&low<high)
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

int FindKth(int A[],int start,int end,int k)
{
	if(start<end)
	{
		int x=sort(A,start,end);
		if(x==k-1)
			return  x;
		else if(x<k-1)
			return FindKth(A,x+1,end,k-x);
		else
			return FindKth(A,start,x-1,k);
	}

}

int main()
{
	int i;
	int A[N]={2,5,4,7,3,1,9,8,6};
	i=FindKth(A,0,N-1,2);
		printf("%d ",A[i]);
	return 0;
}