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
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pb=Lb.elem;pa=La.elem;
//	Lc.listsize=Lc.length=La.listsize+Lb.listsize;
	pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem)exit(-2);
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa<=*pb)*pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last)*pc++=*pa++;
	while(pb<=pb_last)*pc++=*pb++;
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
