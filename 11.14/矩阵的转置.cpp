#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include "constant.h"
#include "tsmatrix.h"

typedef int Status;

Status TransposeSMatrix(TSMatrix M,TSMatrix &T)//����Ԫ��Ԫ���data[0]δ�� 
{
	T.tu=M.tu;
	T.mu=M.nu;
	T.nu=M.mu;

	int p,q,col;
	if(T.tu)		//���T���з���Ԫ�� 
	{
		q=1;
		for(col=1;col<=T.mu;col++)
			for(p=1;p<=M.tu;p++)
				if(M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					q++;
				}
	}
	return OK;
}

int main()
{
	TSMatrix m,t;
	int i,j,k,q,p;
	printf("������m�����������������");
	scanf("%d%d",&m.mu,&m.nu);
	int a[m.mu][m.nu];
	printf("��Ϊ����ֵ\n");
	for(i=0;i<m.mu;i++)
	{
		for(j=0;j<m.nu;j++)
		{
			scanf("%d",&a[i][j]);
		 } 
	}
	q=1;
	for(i=0;i<m.mu;i++)
	{
		for(j=0;j<m.mu;j++)
		{
			if(a[i][j]!=0)
			{
				m.data[q].e=a[i][j];
				m.data[q].i=i+1;
				m.data[q].j=j+1;
				q++;
			}
				
				
		 } 
	}
	p=q-1;
	m.tu=p;
	printf("���������m����Ϊ��\n");
	k=1;
	int o=0;
	while(k<=m.tu)
	{
		for(i=0;i<m.mu;i++)
		{
			for(j=0;j<m.nu;j++)
			{
				if(m.data[k].i==i+1 && m.data[k].j==j+1)
				{
					printf("%2d",m.data[k].e);
					k++;
				}
				 	
				else
					printf("%2d",o);
			}
			printf("\n");
		}
	}
	 TransposeSMatrix(m,t);
	 printf("after transposition,the matrix is:\n");
	 k=1;
	while(k<=t.tu)
	{
		for(i=0;i<t.mu;i++)
		{
			for(j=0;j<t.nu;j++)
			{
				if(t.data[k].i== i+1 && t.data[k].j==j+1)
				{
					printf("%2d",t.data[k].e);
					k++;
				}
				else printf("%2d",o);
			}
			printf("\n");
		}
	}
	return 0;
	
	
	
	
	
	
	
		 
		 
		 
		 
}
