#include <iostream>
#include <cstdio>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define INFINITY 0x3f3f3f3f
#define MAX_VERTEX_NUM 20 
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
typedef enum{DG,DN,UDG,UDN}GraphKind; 

typedef struct AdjCell{
	VRType adj;//数组邻接表，用数组的一维、二维下标v1 v2表示一段有向图中的弧<v1,v2>!
				//对无权图来说，用 1或0 表示是否相邻！（v1 v2是否相邻）
				//对于带权图，则为权值类型！（无穷大则为非相邻！） 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//理解结构体的结构！为什么是这样！ 

typedef struct {
	AdjMatrix arcs;//数组邻接表的具体值直接表示是否存在这个弧！
					//其数组的一 二维下标则已代表了 弧v1 v2！是有向的！
									//无向图的话对称来，另[v2][v1]=[v1][v2]即可 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//因为上面的数组邻接表代表的是弧的关系！
						//	"	//需要能够直接访问顶点的数据结构！即设顶点的数组！ "	//
						//上面打引号的注释似乎有问题！并不是直接访问顶点的数据结构，设的也不是顶点的数组！
						//而是顶点下标及其数据的集合！方便查找顶点的位置（以及记录顶点自身所带的数据）！
						 
	int vexnum,arcnum;
}MGraph;//类似头结点的存在

int LocateVex(MGraph G,char v)//定位顶点的位置！ 
{
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.vexs[i]==v)return i;
	}
	return -1;//未找到符合条件的顶点！ 
}

Status CreateUDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	printf("输入顶点数 G.vexnum: ");scanf("%d",&G.vexnum);
	printf("输入边数 G.arcnum: ");scanf("%d",&G.arcnum);
	getchar();//吸收缓冲区的回车
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点G.vexs[%d]: ",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("输入第 %d 条边的顶点 vi、vj 以及权值 w (int):\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=G.arcs[j][i].adj=w;//无向网 
		//if(Inclnfo)scanf(G.arcs[i][j].info)//输入弧含有的相关信息 
	}
	return Ok; 
}

Status CreateDG(MGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	printf("输入顶点数 G.vexnum: ");scanf("%d",&G.vexnum);
	printf("输入弧数 G.arcnum: ");scanf("%d",&G.arcnum);
	getchar();//吸收缓冲区的回车
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点G.vexs[%d]：",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
		//	G.arcs[i][j]=0; 仔细！arcs是什么数据结构！
					//arcs[i][j]还只是指向了某一个大的结构体
					//还没有具体指向结构体中的哪一个细分结构！
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=nullptr;			 
		}
	}
	for(k=0;k<G.arcnum;++k){
	//	printf("输入弧尾v1，弧头v2：",);scanf("%c %c",&v1,&v2);
		printf("输入第 %d 条弧的弧尾 vi，弧头vj ：\n",k+1);
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=1;//有向图 
	}
	return Ok;
}

Status CreateUDG(MGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	printf("输入顶点数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入边数 G.arcnum：");scanf("%d",&G.arcnum);
	//怎么刚说这里 又错了！。。。。
//
	getchar(); 
	//仔细啊啊啊啊啊啊！！ 
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点 G.vexs[%d]：",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("输入第 %d 条边的顶点 v1、v2：\n",k+1);
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=G.arcs[j][i].adj=1;
	}
	return Ok;
}

Status CreateDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	printf("输入顶点个数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入弧个数 G.arcnum：");scanf("%d",&G.arcnum);
	///////
//	这里一定要仔细！！！ 
	///////
//	上一个数据输入的是%d 而下一个数据输入的是%c ！
//	中间一定要有将缓冲区的回车符刷新掉（吸收掉）的操作！ 
	getchar();
	///////
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点G.vexs[%d]：",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("输入第 %d 条弧的弧尾 vi，弧头vj 以及权值 w (int)：\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar(); 
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;
	}
	return Ok;
}

Status CreateGraph(MGraph &G)
{
	//采用数组（邻接矩阵）表示法，构造图G
	printf("请输入图的种类: 0 表示 DG, 1 表示 DN, 2 表示 UDG , 3 表示 UDN\n");
	scanf("%d",&G.kind);
	switch(G.kind){
		case DG:return CreateDG(G);
		case DN:return CreateDN(G);
		case UDG:return CreateUDG(G);
		case UDN:return CreateUDN(G);
		default:return Error;
	}
	return Ok;
}

void list(MGraph G)
{
	int i,j;
	printf("输出邻接矩阵：\n\n");
	printf(" ----");
	for(i=0;i<G.vexnum;++i){
		printf("%4c",G.vexs[i]);
	}
	printf("\n");
	for(i=0;i<G.vexnum;++i){
		printf("%c----",G.vexs[i]);
		for(j=0;j<G.vexnum;++j){
			if(G.arcs[i][j].adj==INFINITY)
				printf("%4s","∞");
			else
				printf("%4d",G.arcs[i][j].adj);
		}
		printf("\n");
	}
}

int main ()
{
	MGraph G;
	CreateGraph(G);
	list(G);
	return 0;
 } 
