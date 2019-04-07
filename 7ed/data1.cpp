#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define MAX_ARRAY_DIM 8
#define Error 0
#define Overflow -2 
#define Underflow -1
typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *base;
	int dim;
	int *bounds;
	int *constants;
}Array;

Status InitArray(Array &A,int dim,...)
{
	if(dim<1||dim>MAX_ARRAY_DIM)return Error;
	A.dim=dim;
	A.bounds=(int*)malloc(sizeof(int)*dim);
	if(!A.bounds)exit(Overflow);
	int elemtotal=1;
	
	va_list ap; 
	
	va_start(ap,dim);
	for(int i=0;i<dim;i++){
		A.bounds[i]=va_arg(ap,int);
		if(A.bounds[i]<0)return Underflow;
		elemtotal*=A.bounds[i];
	}
	va_end(ap);
	A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
	if(!A.base)exit(Overflow);
	A.constants=(int*)malloc(dim*sizeof(int));
	if(!A.constants)exit(Overflow);
	A.constants[dim-1]=1;
	for(int i=dim-2;i>=0;i--){
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];
	}
	return Ok;
}

Status DestroyArray(Array &A)
{
	if(!A.base)return Error;
	free(A.base);A.base=NULL;
	if(!A.bounds)return Error;
	free(A.bounds);A.bounds=NULL;
	if(!A.constants)return Error;
	free(A.constants);A.constants=NULL;
	return Ok;
}

Status Locate(Array A,va_list ap,int &off)
{
	off=0;
	for(int i=0;i<A.dim;i++){
		int ind=va_arg(ap,int);
		if(ind<0||ind>=A.bounds[i])return Overflow;
		off+=A.constants[i]*ind;
	}
	va_end(ap);
	return Ok;
}

Status Value(Array A,ElemType &e,...)
{
	int result,off;
	va_list(ap);
	va_start(ap,e);
	if((result=Locate(A,ap,off))<=0)return result;
	va_end(ap);
	e=*(A.base+off);
	return Ok;
}

Status Assign(Array &A,ElemType e,...)
{
	int result,off;
	va_list ap;
	va_start(ap,e);
	if((result=Locate(A,ap,off))<=0)return result;
	va_end(ap);
	*(A.base+off)=e;
	return Ok;
}
int main ()
{
	Array A;
	ElemType e=0;
	InitArray(A,3,2,3,4);
	Assign(A,100,1,2,3);
	if(Value(A,e,1,2,3)==Ok)printf("输出 e 的值：%d\n",e);
	if(DestroyArray(A)==Ok)cout<<"数组 A 销毁成功！\n";
	return 0;
 } 
