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
	
	//���������ˣ��ڽӱ��������������ͬһ�������µ��ڽӵĻ��ļ��ϣ�
	//ͨ��������������ݽṹ����Ϊ���ݽṹ��Ϊ������ĳһҪ���������������ģ� 
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
	//��ǰ����µĶ����������� һ����Ҫ���ǰ������� 
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

Status CreateUDG(ALGraph &G)//����ͼ 
{
	int i,j,k,Inclnfo;
	ArcNode *pi,*pj;
	VertexType v1,v2;
//scanf("%d %d %d",&G.vexnum,&G.arcnum,&IncInfo);
		//IncInfoΪ0������������������Ϣ 
	printf("���붥���� G.vexnum��");scanf("%d",&G.vexnum);
	printf("������� G.arcnum��");scanf("%d",&G.arcnum);
	getchar(); 
	for(i=0;i<G.vexnum;++i){
		G.vertices[i].firstarc=nullptr;
		printf("���붥�� G.vertices[%d].data��",i);
		scanf("%c",&G.vertices[i].data);getchar();
	} 
	for(k=0;k<G.arcnum;++k){
		printf("������� %d ���ߵĶ��� v1��v2��\n",k+1);
	//	scanf("%c %c",(*pi).data,(*pj).data);
		//��һ�в���Ҫ��������������ļ����Ѿ���������ˣ�
		//����ֻ��Ҫ�ҵ����� v1��v2�Ķ����λ�ã�
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{   ����else����Ϊ�������Ļ��Ѿ��˳��� 
			pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;// �������ǲ�������
			G.vertices[i].firstarc=pi;// �����Ļ�����������ͷ������һ����λ�ã� 
	//	}
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{
			pj->adjvex=i;pj->nextarc=G.vertices[j].firstarc;
			G.vertices[j].firstarc=pj;
	//	}
		/* if(IncInfo){
				printf("�����뻡�����������Ϣ�����\n");
				scanf("%d",pj->info);
				pi->info=pj->info; 
			}
		*/		
	}
	return Ok; 
}

Status CreateGraph(ALGraph &G)
{
	printf("������ͼ�����ࣺ0 ��ʾ DG��1 ��ʾ DN��2 ��ʾ UDG��3 ��ʾ UDN\n");
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
	printf("����ڽӱ�\n\n");
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




