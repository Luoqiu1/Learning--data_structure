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
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	int ja,jb,jc;ja=jb=jc=0;
	while(ja<La.length&&jb<Lb.length){
		if(La.elem[ja]<Lb.elem[jb]){
			Lc.elem[jc++]=La.elem[ja++];
		}
		else{
			Lc.elem[jc++]=Lb.elem[jb++];
		}
	}

	while(ja<La.length){
		Lc.elem[jc++]=La.elem[ja++];
	}
	while(jb<Lb.length){
	//	Lc.elem[jc++]=La.elem[jb++];
		// 改没改全。。仔细
		 Lc.elem[jc++]=Lb.elem[jb++];
	}
}
int main ()
{
	SqList a,b,c;
	InitList_Sq(a);InitList_Sq(b);InitList_Sq(c);
	printf("请输入n，m分别表示非递减顺序表a，b的元素个数，并输入元素填充顺序表a,b！\n");
	int n,m;
	scanf("%d %d",&n,&m);
	a.length=n;b.length=m;c.length=n+m;
	getelem(a,n);getelem(b,m);
	printf("a表为：");
	DispList(a);
	printf("b表为：");
	DispList(b);
	printf("导出非递减线性表c如下：");
	MergeList_Sq(a,b,c);
	DispList(c);
	return 0;
}
