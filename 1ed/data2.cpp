#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
int getelem(SqList L,int n)
{
	if(n<1||n>L.length)return 0;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&L.elem[i]);
	}
}
int InitList_Sq(SqList &L)//算法2.3 
{ 
	L.elem=(ElemType*)malloc(100*sizeof(ElemType));
	if(!L.elem)exit(-2);
	L.length=0;
	L.listsize=100;
	return 1;
}
int ListInsert_Sq(SqList &L,int i,ElemType e)//算法2.4 
{
	if(i<1||i>L.length+1)return 0;
	if(L.length>=L.listsize){
		ElemType *newbase=(ElemType*)realloc((L.elem),(L.listsize+100)*sizeof(ElemType));
		if(!newbase)exit(-2);
		L.elem=newbase;
		L.listsize+=100;
	}
	int j;
//	L.elem[L.length]=L.elem[L.length-1];
	for(j=L.length;j>i-1;j--){
		L.elem[j]=L.elem[j-1];
	}
	L.elem[i-1]=e;
	L.length++;
	return 1;
}
int ListDelete_Sq(SqList &L,int i,ElemType &e)//算法2.5 
{
	if(i<1||i>L.length)return 0;
	int j;
	e=L.elem[i-1];
	for(j=i-1;j<L.listsize-1;j++){
		L.elem[j]=L.elem[j+1];
	}
	L.length--;
	return e;
}

void DispList(SqList L)
{
	int i;
	if (L.length==0)return;
	for(i=0;i<L.length-1;i++)printf("%d ",L.elem[i]);printf("%d",L.elem[i]);
	printf("\n");
}

int main()
{
	SqList L;
	int n;
	printf("创建一个n个元素的顺序表，请输入元素个数n以及这n个数！\n");
	scanf("%d",&n);
	InitList_Sq(L); 
	L.length=n;
	getelem(L,n);
	DispList(L); 
	printf("在第i个位置插入元素k，请输入i,k\n");
	int i,k;
	scanf("%d %d",&i,&k);
	ListInsert_Sq(L,i,k);
//	printf("%d\n",L.length);
	DispList(L); 
	printf("删除第i个位置的元素，并返回被删除的数e\n请输入i\n");
	scanf("%d",&i);
	int e;
	e=ListDelete_Sq(L,i,e);
	printf("被删除的元素是%d\n合并后的表为\n",e);
	DispList(L); 
	return 0;
}
