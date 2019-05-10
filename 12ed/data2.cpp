#include <cstdio>
#include <cstdlib>
using namespace std;
#define INFINITY 0x3f3f3f3f
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define MAX_VERTEX_NUM 20 
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
typedef enum{DG,DN,UDG,UDN}GraphKind;

typedef struct ArcNode{
	
	//还是忘记了，邻接表的特征啊！是在同一个顶点下的邻接的弧的集合！
	//通过特征来理解数据结构！因为数据结构是为了满足某一要求（特征）而建立的！ 
	int adjvex; 
	//	
	InfoType *info;
	struct ArcNode *nextarc;
}ArcNode;
//typedef struct AdjList{
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	GraphKind kind;
	AdjList vertices;
	//当前情况下的顶点数及弧数 一定不要忘记啊。。。 
	int vexnum,arcnum;
}ALGraph;

int LocateVex(ALGraph G,char v)
{
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.vertices[i].data==v)return i;
	}
	return -1;
}

Status CreateUDG(ALGraph &G)//无向图 
{
	int i,j,k,Inclnfo;
	ArcNode *pi,*pj;
	VertexType v1,v2;
//scanf("%d %d %d",&G.vexnum,&G.arcnum,&IncInfo);
		//IncInfo为0表明各弧不含其他信息 
	printf("输入顶点数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入边数 G.arcnum：");scanf("%d",&G.arcnum);
	getchar(); 
	for(i=0;i<G.vexnum;++i){
		G.vertices[i].firstarc=nullptr;
		printf("输入顶点 G.vertices[%d].data：",i);
		scanf("%c",&G.vertices[i].data);getchar();
	} 
	for(k=0;k<G.arcnum;++k){
		printf("请输入第 %d 条边的顶点 v1、v2：\n",k+1);
	//	scanf("%c %c",(*pi).data,(*pj).data);
		//上一行不需要这样操作！顶点的集合已经构造完成了！
		//现在只需要找到代表 v1、v2的顶点的位置！
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{   不必else，因为如果满足的话已经退出了 
			pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;// 这两行是插入链表
			G.vertices[i].firstarc=pi;// 后来的弧插入在链表头结点的下一个链位置！ 
	//	}
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{
			pj->adjvex=i;pj->nextarc=G.vertices[j].firstarc;
			G.vertices[j].firstarc=pj;
	//	}
		/* if(IncInfo){
				printf("请输入弧包含的相关信息情况：\n");
				scanf("%d",pj->info);
				pi->info=pj->info; 
			}
		*/		
	}
	return Ok; 
}

Status CreateGraph(ALGraph &G)
{
	printf("请输入图的种类：0 表示 DG，1 表示 DN，2 表示 UDG，3 表示 UDN\n");
	scanf("%d",&G.kind);
	switch(G.kind){
	//	case DG:return CreateDG(G);
	//	case DN:return CreateDN(G);
		case UDG:return CreateUDG(G);
	//	case UDN:return CreateUDN(G);
		default:return Error;
	}
	return Ok; 
}

void list(ALGraph G)
{
//	int i,j;
	int i;
	ArcNode *p;
	printf("输出邻接表：\n\n");
//	printf(" ----");
//	for(i=0;i<G.vexnum;++i){
//		printf("%4c",G.vertices[i].data);
//	}
//	printf("\n");
//	for(i=0;i<G.vexnum;++i){
//		printf("%c----".G.vertices[i].data);
//		p=G.vertices[i].firstarc;
//		
//		for(j=0;j<G.vexnum;++j){
//			while(p)
//		}
//	}
	for(i=0;i<G.vexnum;++i){
		printf("%d: %c--->",i,G.vertices[i].data);
		p=G.vertices[i].firstarc;
		while(p){
			printf("%3d",p->adjvex);
			p=p->nextarc;
			if(p){
				printf(" --->");
			}
		}
		printf("\n");
	}
}

int main ()
{
	ALGraph G;
	CreateGraph(G);
	list(G);
	return 0;
}




