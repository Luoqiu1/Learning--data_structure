#include <bits/stdc++.h> 
#define Ok 1
#define True 1
#define Error 0
#define Overflow -2
typedef int Status;
typedef int TElemType;

Status PrintElement(TElemType e)
{
	printf("%c",e);
	return Ok;
}


int main ()
{
	BiThrTree T,Thrt;
	printf("����������������������������������������н���ֵ��\n");
	CreateBiThrTree(T);
	if(InOrderThreading(Thrt,T)==Ok)
		printf("�ɹ�������������������\n");
	InOrderTraverse_Thr(Thrt,PrintElement);
	printf("\n");
	return 0;
}
