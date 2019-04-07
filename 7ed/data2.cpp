#include <bits/stdc++.h>
using namespace std;
#define MU 5
#define NU 6
#define MAXSIZE 12500
#define Ok 1
#define Error 0
typedef int Status;
typedef struct{
	int i,j,e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

Status CreateMatrix(TSMatrix &M)
{
	int e,i,j,k=1;
	M.mu=MU;M.nu=NU;
	srand((unsigned)time(NULL));
	M.tu=rand()%15;//M.tu=0为空三元组表 
	for(i=1;i<=M.mu;i++){
		for(j=1;j<=M.nu;j++){
			e=rand()%30;
			if(e!=0){
				M.data[k].i=i;
				M.data[k].j=j;
				M.data[k].e=e;
				if(k==M.tu)break;
				k++;//顺序问题 
			}
		}
		if(k==M.tu)break;//打破循环需要两次 
	}
	if(k<M.tu)M.tu=k;//存在缺陷的原因是，由于使用了 rand() 函数，
//存在着遍历完矩阵之后，得到的非零值小于M.tu的可能。
//只需要通过一个语句检查即可 
	return Ok;
}

void print(TSMatrix M)
{
	int k;
	printf("mu=%-2d,  nu=%-2d,  tu=%-2d",M.mu,M.nu,M.tu);
	cout<<endl;
	for(k=1;k<=M.tu;k++){
		printf("i=%-2d,  j=%-2d,  e=%-2d",M.data[k].i,M.data[k].j,M.data[k].e);
		cout<<endl;
	}
}

Status TransposeSMatrix(TSMatrix M,TSMatrix &T)
{
	T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
	if(T.tu){
		int i,j;
		int k=1;
		for(j=1;j<=M.nu;j++){
			for(i=1;i<=M.tu;i++){
				if(M.data[i].j==j){
					T.data[k].i=M.data[i].j;
					T.data[k].j=M.data[i].i;
					T.data[k].e=M.data[i].e;
					k++;
				}
			}
		}
	}	
	return Ok;
}

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
{
	T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
	if(T.tu){
		int col,p;
		int q;
		int a[MU+1]={0};//记录每一列有几个元素 
		int b[NU+1]={0,1};//记录每一列的首元素起始位置 
	//	int a[MU+1],b[NU+1];
		for(col=1;col<=M.nu;col++)a[col]=0;
		for(p=1;p<=M.tu;p++)a[M.data[p].j]++;
	//	b[1]=1;
		for(col=2;col<=M.nu;col++)b[col]=a[col-1]+b[col-1];
	//	col=1;
		for(p=1;p<=M.tu;p++){
			col=M.data[p].j;
			
			
			q=b[col];
		
		
			T.data[b[col]].i=M.data[p].j;
			T.data[b[col]].j=M.data[p].i;
			T.data[b[col]].e=M.data[p].e;
			b[col]++;
		}
	}
	return Ok;
}

Status Choice(int k,TSMatrix M,TSMatrix &T)
{
	if(k==1){
		TransposeSMatrix(M,T);
	}
	else{
		FastTransposeSMatrix(M,T);
	}
	return Ok;
}

int main ()
{
	TSMatrix M,T;
	CreateMatrix(M);
//	FastTransposeSMatrix(M,T);
	cout<<"输出稀疏矩阵 M：\n";
	print(M);
	cout<<"请输入 1 或者 2 ，分别表示使用普通转置或快速转置: ";
	int k;
	cin>>k;
	Choice(k,M,T); 
	cout<<"输出转置矩阵 T：\n";
	print(T);
	
	return 0;
}
