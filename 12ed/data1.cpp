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
	VRType adj;//�����ڽӱ��������һά����ά�±�v1 v2��ʾһ������ͼ�еĻ�<v1,v2>!
				//����Ȩͼ��˵���� 1��0 ��ʾ�Ƿ����ڣ���v1 v2�Ƿ����ڣ�
				//���ڴ�Ȩͼ����ΪȨֵ���ͣ����������Ϊ�����ڣ��� 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���ṹ��Ľṹ��Ϊʲô�������� 

typedef struct {
	AdjMatrix arcs;//�����ڽӱ�ľ���ֱֵ�ӱ�ʾ�Ƿ�����������
					//�������һ ��ά�±����Ѵ����� ��v1 v2��������ģ�
									//����ͼ�Ļ��Գ�������[v2][v1]=[v1][v2]���� 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//��Ϊ����������ڽӱ������ǻ��Ĺ�ϵ��
						//	"	//��Ҫ�ܹ�ֱ�ӷ��ʶ�������ݽṹ�����趥������飡 "	//
						//��������ŵ�ע���ƺ������⣡������ֱ�ӷ��ʶ�������ݽṹ�����Ҳ���Ƕ�������飡
						//���Ƕ����±꼰�����ݵļ��ϣ�������Ҷ����λ�ã��Լ���¼�����������������ݣ���
						 
	int vexnum,arcnum;
}MGraph;//����ͷ���Ĵ���

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

Status CreateDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	printf("���붥�����G.vexnum ��\n");scanf("%d",&G.vexnum);
	printf("���뻡����G.arcnum ��\n");scanf("%d",&G.vexnum);
	for(i=0;i<G.vexnum;++i){
		printf("���붥��G.vexs[%d]��",i);
		scanf("%c",&G.vexs[i]);getchar();
	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=0;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
		printf("����� %d ������ ��βv1����ͷv2�Լ�Ȩֵ w(int)��\n",k+1);
		scanf("%c %c %d",&v1,&v2,w);
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
	//	case UDG:return CreateUDG(G);
		case UDN:return CreateUDN(G);
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

int main ()
{
	MGraph G;
	CreateGraph(G);
	list(G);
	return 0;
 } 
