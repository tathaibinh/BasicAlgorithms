/********************************************************************
Author: daidi@live.cn
Date:10/23/2013
Description: 设X[0:n-1]和Y[0:n-1]为两个数组，每个数组均已经排好序，
试设计一个O (log(n)) 的算法，找出X和Y中2n个数的中位数。
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 5

int GetMedian(int X[],int Y[],int s1,int e1,int s2,int e2)
{
	int m1,m2;
	m1=(s1+e1)/2;
	m2=(s2+e2)/2;
	if(X[m1]==Y[m2])
		return X[m1];
	else if(e1==s1)
		return X[m1]<Y[m2]?X[m1]:Y[m2];//当只剩下一个元素的时候也要处理，不要想当然的认为下面的处理偶数的部分可以处理
	else if((e1-s1+1)%2==1)//要判断长度的奇偶性再进行，否则截取去掉的两部分不能保证长度相同
	{
		if(X[m1]<Y[m2])
		return GetMedian(X,Y,m1+1,e1,s2,m2-1);//在这种递归调用时不能忘了return
		else
		return GetMedian(X,Y,s1,m1-1,m2+1,e2);
	}
	else//长度为偶数时，假定中间两位的前一个是中位数。长度为0时无法处理（试一下就知道了	）
	{
		if(X[m1]<Y[m2])
		return GetMedian(X,Y,m1+1,e1,s2,m2);
		else
		return GetMedian(X,Y,s1,m1,m2+1,e2);
	}
}

int main()
{
	int i;
	int X[N]={1,2,3,4,5};
	int Y[N]={4,5,6,7,8};
	i=GetMedian(X,Y,0,N-1,0,N-1);
		printf("%d ",i);
	return 0;
}