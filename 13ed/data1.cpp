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

int LocateVex(MGraph G,char v)//��λ�����λ�ã� 
{
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.vexs[i]==v)return i;
	}
	return -1;//δ�ҵ����������Ķ��㣡 
}

Status CreateUDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	printf("���붥���� G.vexnum: ");scanf("%d",&G.vexnum);
	printf("������� G.arcnum: ");scanf("%d",&G.arcnum);
	getchar();//���ջ������Ļس�
	for(i=0;i<G.vexnum;++i){
		printf("���붥��G.vexs[%d]: ",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("����� %d ���ߵĶ��� vi��vj �Լ�Ȩֵ w (int):\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=G.arcs[j][i].adj=w;//������ 
		//if(Inclnfo)scanf(G.arcs[i][j].info)//���뻡���е������Ϣ 
	}
	return Ok; 
}

Status CreateDG(MGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	printf("���붥���� G.vexnum: ");scanf("%d",&G.vexnum);
	printf("���뻡�� G.arcnum: ");scanf("%d",&G.arcnum);
	getchar();//���ջ������Ļس�
	for(i=0;i<G.vexnum;++i){
		printf("���붥��G.vexs[%d]��",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
		//	G.arcs[i][j]=0; ��ϸ��arcs��ʲô���ݽṹ��
					//arcs[i][j]��ֻ��ָ����ĳһ����Ľṹ��
					//��û�о���ָ��ṹ���е���һ��ϸ�ֽṹ��
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=nullptr;			 
		}
	}
	for(k=0;k<G.arcnum;++k){
	//	printf("���뻡βv1����ͷv2��",);scanf("%c %c",&v1,&v2);
		printf("����� %d �����Ļ�β vi����ͷvj ��\n",k+1);
		scanf("%c %c",&v1,&v2);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=1;//����ͼ 
	}
	return Ok;
}

Status CreateUDG(MGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	printf("���붥���� G.vexnum��");scanf("%d",&G.vexnum);
	printf("������� G.arcnum��");scanf("%d",&G.arcnum);
	//��ô��˵���� �ִ��ˣ���������
//
	getchar(); 
	//��ϸ���������������� 
	for(i=0;i<G.vexnum;++i){
		printf("���붥�� G.vexs[%d]��",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("����� %d ���ߵĶ��� v1��v2��\n",k+1);
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
	printf("���붥����� G.vexnum��");scanf("%d",&G.vexnum);
	printf("���뻡���� G.arcnum��");scanf("%d",&G.arcnum);
	///////
//	����һ��Ҫ��ϸ������ 
	///////
//	��һ�������������%d ����һ�������������%c ��
//	�м�һ��Ҫ�н��������Ļس���ˢ�µ������յ����Ĳ����� 
	getchar();
	///////
	for(i=0;i<G.vexnum;++i){
		printf("���붥��G.vexs[%d]��",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("����� %d �����Ļ�β vi����ͷvj �Լ�Ȩֵ w (int)��\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar(); 
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;
	}
	return Ok;
}

Status CreateGraph(MGraph &G)
{
	//�������飨�ڽӾ��󣩱�ʾ��������ͼG
	printf("������ͼ������: 0 ��ʾ DG, 1 ��ʾ DN, 2 ��ʾ UDG , 3 ��ʾ UDN\n");
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
	printf("����ڽӾ���\n\n");
	printf(" ----");
	for(i=0;i<G.vexnum;++i){
		printf("%4c",G.vexs[i]);
	}
	printf("\n");
	for(i=0;i<G.vexnum;++i){
		printf("%c----",G.vexs[i]);
		for(j=0;j<G.vexnum;++j){
			if(G.arcs[i][j].adj==INFINITY)
				printf("%4s","��");
			else
				printf("%4d",G.arcs[i][j].adj);
		}
		printf("\n");
	}
}

typedef struct mini{
	VertexType adjvex;//������������������ݽṹ��
					//���adjvex ������ǻ�β��ֵ�ˣ� 
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

Status MiniSpanTree_PRIM(MGraph G,VertexType u)
{
	int k=LocateVex(G,u);closedge Aid;
	for(int i=0;i<G.vexnum;++i){
		if(i!=k){
			Aid[i].lowcost=G.arcs[k][i].adj;
			Aid[i].adjvex=G.vexs[i];
		}
	}
	Aid[k].lowcost=0;Aid[k].adjvex=u;
	for(int i=1;i<G.vexnum;++i){
		for(int j=0;j<G.vexnum;++j){//�ҳ���С���ڱߣ� 
			int min=INFINITY;
			if(Aid[j].lowcost<min&&Aid[j].lowcost){
				min=Aid[j].lowcost;k=j;
			}
		}
		printf("%c%c ",G.vexs[k],Aid[k].adjvex);
		for(int i=0;i<G.vexnum;++i){
			if(Aid[i].lowcost>G.arcs[k][i].adj){
				Aid[i].lowcost=G.arcs[k][i].adj;
				Aid[i].adjvex=G.vexs[k];
			}
		}
	}
	return Ok;
}

int main()
{
	MGraph G;
	CreateGraph(G);
	list(G);
	printf("�����С��������\n");
	MiniSpanTree_PRIM(G,'a');
	printf("\n");
	return 0;
}











