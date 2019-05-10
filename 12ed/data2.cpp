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
bool visited[MAX_VERTEX_NUM];

typedef struct ArcNode{
	
	//还是忘记了，邻接表的特征啊！是在同一个顶点下的邻接的弧的集合！
	//通过特征来理解数据结构！因为数据结构是为了满足某一要求（特征）而建立的！ 
	int adjvex; 
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

int NextAdjVex(ALGraph G,int v,int w)
{
//	printf("NAdj前 v=%d\n",v);
	ArcNode *p=G.vertices[v].firstarc;
//	if(p==nullptr)printf("  p==nullptr v=%d  ",v);
	while(p){
		if(p->adjvex==w){
		//	if(p->nextarc&&!visited[p->nextarc->adjvex]) 
							//完全不需要判断是否已经访问过！
							//因为这个函数的目的仅仅是找到下一个邻接顶点！
							//判断是否访问过在上一层函数中！if(!visited[w])里实现了！ 
			if(p->nextarc) 
				return p->nextarc->adjvex;
		}
	//	else p=p->nextarc; 啊啊啊啊！！一定不能是else！这样会少情况！
					//对于定位到了的顶点位置，则不会再往前找后一个邻接顶点了！。。。
		//实质上 深搜是一定不能用else的 因为是要每个都要遍历过去！ 
		//加强对子条件的理解！ 
							 
		p=p->nextarc;
	}
//	printf("NAdj后 v=%d\n",v);
	return -1;
}

int FirstAdjVex(ALGraph G,int v)
{
//	printf("FAdj前 v=%d\n",v);
	if(G.vertices[v].firstarc){
		return G.vertices[v].firstarc->adjvex;
	}
//	printf("FAdj后 v=%d\n",v);
	else return -1;
}

void DFS(ALGraph G,int v)
{
//	printf("DFS v=%d\n",v);
	printf("%c",G.vertices[v].data);
	visited[v]=true;
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		if(!visited[w])DFS(G,w);
}

void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum;++v){
//		printf("DFSTraverse v=%d\n",v);
		if(!visited[v]) DFS(G,v);
	}
}

//void DFS(ALGraph G,int v)
//{
//	printf("%c",G.vertices[v].data);
//	visited[v]=true;
//	ArcNode *p=G.vertices[v].firstarc;
//	while(p){
//		if(!visited[p->adjvex]){
//			DFS(G,p->adjvex);
//		}
//		
//	}
//}
//
//void DFSTraverse(ALGraph G)
//{
//	int v;
//	for(v=0;v<G.vexnum;++V){
//		if(!visited[v])DFS(G,v);
//	}
//}


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
			pi->info=nullptr;
			pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;// 这两行是插入链表
			G.vertices[i].firstarc=pi;// 后来的弧插入在链表头结点的下一个链位置！ 
	//	}
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{
			pj->info=nullptr;
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

Status CreateUDN(ALGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	ArcNode *pi,*pj;
	printf("输入顶点数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入边数 G.arcnum：");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点 G.vertices[%d].data:",i);
		scanf("%c",&G.vertices[i].data);getchar();
		G.vertices[i].firstarc=nullptr;
	}
	for(k=0;k<G.arcnum;++k){
		printf("请输入第 %d 条边的顶点 v1、v2 以及权值 w (int)：\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		//再次理解malloc！为某一指针分配一空间，其实就是分配了一个具体的地址！ 
		*pi->info=w;
		pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=pi;
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pj->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		*pj->info=w;
		pj->adjvex=i;pj->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=pj;
	}
	return Ok;
}

Status CreateDN(ALGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	ArcNode *pi,*pj;
	printf("输入顶点数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入弧数 G.arcnum：");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		printf("输入顶点 G.vertices[%d].data：",i);scanf("%c",&G.vertices[i].data);getchar();
		G.vertices[i].firstarc=nullptr;//这句话一定不能漏掉啊！	否则就是野指针了，地址非空！
						//使用指针前一定要检查指针是否有意义（野指针会带来极大的漏洞）
						//甚至应该在创建指针的时候就另指针为空指针！ 
	}
	for(k=0;k<G.arcnum;++k){
		printf("请输入第 %d 条弧的弧尾v1、弧头v2 以及权值 w (int)：\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		*pi->info=w;
	//	pi->adjvex=i;pi->nextarc=G.vertices[i].firstarc;
		//注意！！还是没有彻底理解图！
		//关于顶点的邻接表！vex->adjvex是关于某一个顶点下的所有的邻接顶点的集合！ 
		pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=pi;
	}
	return Ok;
}

Status CreateDG(ALGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	ArcNode *pi,*pj;
	printf("输入顶点数 G.vexnum：");scanf("%d",&G.vexnum);
	printf("输入弧数 G.arcnum：");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		G.vertices[i].firstarc=nullptr;
		printf("输入顶点 G.vertices[%d].data：",i);scanf("%c",&G.vertices[i].data);getchar();
	}
	for(k=0;k<G.arcnum;++k){
		printf("请输入第 %d 条弧的弧尾v1、弧头v2：\n",k+1);
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		pi->info=nullptr;
		pi->nextarc=G.vertices[i].firstarc;pi->adjvex=j;
		G.vertices[i].firstarc=pi;
	}
	return Ok;
}

Status CreateGraph(ALGraph &G)
{
	printf("请输入图的种类：0 表示 DG，1 表示 DN，2 表示 UDG，3 表示 UDN\n");
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

void list(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("输出邻接表：\n\n");
	for(i=0;i<G.vexnum;++i){
		printf("%d: %c--->",i,G.vertices[i].data);
		p=G.vertices[i].firstarc;
		while(p){
			printf("%3d",p->adjvex);
			if(p->info){
				printf(",w=%4d ",*p->info);
			}
			p=p->nextarc;
			if(p){
				printf("--->");
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
	DFSTraverse(G);
	return 0;
}




