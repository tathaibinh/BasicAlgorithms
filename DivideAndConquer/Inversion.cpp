/********************************************************************
Author: daidi@live.cn
Date:10/23/2013
Description: 求逆序对个数
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 9

//修改归并算法，在归并的过程中计数
int Merge(int A[],int start,int mid,int end)
{
	int i=start,j=mid+1,k=0,num=0;
	int temp[N];
	while(i<=mid&&j<=end)
	{
		if(A[i]<=A[j])
			temp[k++]=A[i++];
		else
		{
			temp[k++]=A[j++];
			num+=mid-i+1;//左边的A[i]比右边的A[j]大,则左边比A[i]大的所有数都比A[j]大
		}
	}
	while(i<=mid)
		temp[k++]=A[i++];
	while(j<=end)
		temp[k++]=A[j++];
	for(i=end;i>=start;i--)//别忘了把temp赋值回去
		A[i]=temp[--k];
	return num;
}

int Reversion(int A[],int start,int end)
{
	int num=0;
	if(start<end)
	{
		int mid=(start+end)/2;
		num+=Reversion(A,start,mid);
		num+=Reversion(A,mid+1,end);
		num+=Merge(A,start,mid,end);
	}
	return num;
}

int main()
{
	int i;
	int A[N]={1,2,3,4,5,6,7,8,9};
	i=Reversion(A,0,N-1);
		printf("%d ",i);
	return 0;
}