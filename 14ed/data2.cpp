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
	VRType adj;
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph{
	GraphKind kind;
	int vexnum,arcnum;
	AdjMatrix arcs;
	VertexType vexs[MAX_VERTEX_NUM];
}MGraph; 

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

bool P[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

Status ShortestPath_FLOYD(MGraph G,int v0)
{
	int i,j,k;
//	for(i=0;i<G.vexnum;++i){
//		D[v0][i]=G.arcs[v0][i].adj;			
//		if								//该算法与dij算法不同！
										//dij是先初始化关于顶点v0的所有边！
										//该算法则是比较直观，直接对所有的顶点进行记录！ 
//	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			D[i][j]=G.arcs[i][j].adj;
			if(D[i][j]<INFINITY){
				P[i][j][i]=true;P[i][j][j]=true;
			}
		}
	}
	for(k=0;k<G.vexnum;++k){
		for(i=0;i<G.vexnum;++i){
			for(j=0;j<G.vexnum;++j){
				if(D[i][k]+D[k][j]<D[i][j]){
					D[i][j]=D[i][k]+D[k][j];
					for(int z=0;z<G.vexnum;++z){
						P[i][j][z]=P[i][k][z];
					}
				}
			}
		}	
	}
	for(i=1;i<G.vexnum;++i){
		printf("从 v0 到 v%d ：\n",i);
		bool flag=false;
		for(j=0;j<G.vexnum;++j){
			for(k=0;k<G.vexnum;++k){
				if(P[v0][j][k]){
					flag=true;break;
				}
			}
			if(flag)break;
		}
		if(flag){
			printf("最短路径为（非顺序排列）：");
				for(k=0;k<G.vexnum;++k){
					if(P[v0][i][k]){
						printf("%c",G.vexs[k]);
				}
			}
		}
			printf("\n最短路径长度为：%d\n\n",D[v0][i]);
		}
		else printf("两顶点之间无路径\n\n"); 
	} 
	return Ok;
}

int main()
{
	MGraph G;
	CreateGraph(G);
	list(G);
	printf("\n请输入 顶点v0，以便开始计算从 顶点v0 开始到 其余顶点 的最短路径即其路径长度：v0=");
	char ch;scanf("%c",&ch); 
	printf("输出最短路径所经过的顶点（非顺序排列）以及最短路径长度：\n");
	ShortestPath_FLOYD(G,LocateVex(G,ch));
//	MiniSpanTree_PRIM(G,'a');
	printf("\n");
	return 0;
}











