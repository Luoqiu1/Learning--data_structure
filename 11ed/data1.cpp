#include <bits/stdc++.h>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

Status Select(HuffmanTree HT,int u,int &s1,int &s2)
{
	int j=1;
	while(j<=u&&HT[j].parent!=0)j++;
	s1=j;
	while(j<=u){
		if(HT[j].parent==0&&HT[j].weight<HT[s1].weight)
			s1=j;
		j++;
	}
	HT[s1].parent=u+1;
	j=1;
	while(j<=u&&HT[j].parent!=0)j++;
	s2=j;
	while(j<=u){
		if(HT[j].parent==0&&HT[j].weight<HT[s2].weight)
			s2=j;
		j++;
	}
	if(s1>s2){
		j=s1;s1=s2;s2=j;
	}
	return Ok;
}

Status HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
	int i,j,m,s1,s2,start;
	char *cd;
	unsigned int c,f;
	if(n<=1)return Error;
	m=2*n-1;
	HT=(HTNode*)malloc(sizeof(HTNode)*(m+1));
	if(!HT)exit(Overflow);
	for(i=1;i<=n;i++){
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(i=n+1;i<=m;i++){
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	printf("\n HuffmanTree构造过程如下所示：\n");
	printf("\nHT 初态：\n  结点  weight  parent  lchild  rchild");
	for(i=1;i<=m;i++)
		printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;HT[s2].parent=i;
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		printf("\nSelect: s1=%d  s2=%d\n",s1,s2);
		printf("  结点  weight  parent  lchild  rchild");
		for(j=1;j<=i;j++)
			printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,HT[j].parent,HT[j].lchild,HT[j].rchild);
	//		cout<<"here";
	}
	printf("\n\nHT 末态：\n  结点  weight  parent  lchild  rchild");
	for(i=1;i<=m;i++)
		printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
//	cout<<"here";
	printf("\n");
	//逆序构建Huffman编码 
	
//	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
//	cd=(char*)malloc(n*sizeof(char));
//	cd[n-1]='\0';
//	for(i=1;i<=n;i++){
//	//	cout<<"here";
//		start=n-1;
//		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
//			if(HT[f].lchild==c)cd[--start]='0';
//			else cd[--start]='1';
//		HC[i]=(char*)malloc((n-start)*sizeof(char));
//		strcpy(HC[i],&cd[start]);
//	}
//	free(cd);
//	printf("输出各结点的Huffman编码：\n");
//	for(i=1;i<=n;i++)
//		printf("%2d  %2d  %s\n",i,w[i-1],HC[i]); 
		
	//从根结点开始构建Huffman编码
	
//	cout<<"here1";
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
//	cout<<"here2";
	int p=m,cdlen=0;
	for(i=1;i<=m;i++)HT[i].weight=0;
//	cout<<"here3";
	while(p){
//		cout<<"here4";
		if(HT[p].weight==0){
			HT[p].weight=1;
			if(HT[p].lchild!=0){
				cd[cdlen++]='0';
				p=HT[p].lchild;
			}
			else if(HT[p].rchild==0){
				HC[p]=(char*)malloc(sizeof(char)*(cdlen+1));
				cd[cdlen]='\0';
				strcpy(HC[p],cd);
			}
		}
		else if(HT[p].weight==1){
			HT[p].weight=2;
			if(HT[p].rchild!=0){
				cd[cdlen++]='1';
				p=HT[p].rchild;
			}
		}
		else{
			HT[p].weight=0; 
			p=HT[p].parent;cdlen--;
		}
	}
//	cout<<"here5";
	
//	free(cd);    //这个算法中没有使用到数组指针！非法释放！ 
	
	printf("输出各结点的Huffman编码：\n");
//	cout<<"here6";
	for(i=1;i<=n;i++)
	printf("%2d  %2d  %s\n",i,w[i-1],HC[i]);
//	cout<<"here7";
}

int main()
{
	int w[]={5,29,7,8,14,23,3,11},n=8;
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT,HC,w,n);
	return 0;
}











