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

bool P[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

Status ShortestPath_FLOYD(MGraph G,int v0)
{
	int i,j,k;
//	for(i=0;i<G.vexnum;++i){
//		D[v0][i]=G.arcs[v0][i].adj;			
//		if								//���㷨��dij�㷨��ͬ��
										//dij���ȳ�ʼ�����ڶ���v0�����бߣ�
										//���㷨���ǱȽ�ֱ�ۣ�ֱ�Ӷ����еĶ�����м�¼�� 
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
		printf("�� v0 �� v%d ��\n",i);
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
			printf("���·��Ϊ����˳�����У���");
				for(k=0;k<G.vexnum;++k){
					if(P[v0][i][k]){
						printf("%c",G.vexs[k]);
				}
			}
		}
			printf("\n���·������Ϊ��%d\n\n",D[v0][i]);
		}
		else printf("������֮����·��\n\n"); 
	} 
	return Ok;
}

int main()
{
	MGraph G;
	CreateGraph(G);
	list(G);
	printf("\n������ ����v0���Ա㿪ʼ����� ����v0 ��ʼ�� ���ඥ�� �����·������·�����ȣ�v0=");
	char ch;scanf("%c",&ch); 
	printf("������·���������Ķ��㣨��˳�����У��Լ����·�����ȣ�\n");
	ShortestPath_FLOYD(G,LocateVex(G,ch));
//	MiniSpanTree_PRIM(G,'a');
	printf("\n");
	return 0;
}











