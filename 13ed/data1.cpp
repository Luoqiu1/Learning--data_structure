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

bool P[MAX_VERTEX_NUM][MAX_VERTEX_NUM],final[MAX_VERTEX_NUM];
int D[MAX_VERTEX_NUM];

Status ShortestPath_DIJ(MGraph G,int v0)
{
	int i,j,min=INFINITY,k;
	final[v0]=true;P[v0][v0]=true;
	for(i=0;i<G.vexnum;++i){
		if(i==v0)continue;
		D[i]=G.arcs[v0][i].adj;
	//	if(D[i]<min){						�� 
	//		min=D[i];k=i;					
	//	}						��ע�͵��⼸�д���û����ȷ����ʼ�����ѭ����Ҫ��ʲô��
						// 		�ǳ�ʼ���ʼ���й���v0������·������ʼ��ʱ����Ҫ����С�ıߣ� 
						
		if(D[i]<INFINITY){
			P[i][v0]=true;P[i][i]=true;
		}
		
	}
//	final[k]=true;P[v0][k]=true;			�� 
	for(i=1;i<G.vexnum;++i){
		min=INFINITY;
		for(j=0;j<G.vexnum;++j){
			if(!final[j]){
			//	if(G.arcs[i][j].adj<min){
			//		min=G.arcs[i][j].adj;k=j;		//  ���ﲻ�ǿ����ĳ��Ȱ���
												//��Ҫ�ҳ���ǰ��·��������̵�·���������ǱȽϻ�����
			//	}									
				if(D[j]<min){
					min=D[j];k=j;
				}
			}
		}
	//	P[k][k]=true;���·����û�����أ������������ѭ���вŸ������·���Ķ��㣡 
		final[k]=true;
		for(j=0;j<G.vexnum;++j){
			// ����©��һ���ж����������¶����Ƿ��Ѿ���ѡ������·���� �� 
			if(!final[j])
			//
		//		if(G.arcs[v0][j].adj+G.arcs[j][k].adj<D[k]){
		//			D[k]=G.arcs[v0][j].adj+G.arcs[j][k].adj; //�����жϻ��뻡�Ĺ�ϵ��
												//��Ҫ�жϵ��µ����µ����·��������صĶ���Ļ�
												//���֮����v0��������·����صĶ����·����Ƚϣ�
												//���ж� ���·��+���������ص���һ�����Ȩֵ
												//       ��v0��	���������ص���һ�����Ȩֵ
												//				��Ƚϣ�	 
		//		}
				if(min+G.arcs[k][j].adj<D[j]){
					D[j]=min+G.arcs[k][j].adj;
					for(int z=0;z<G.vexnum;++z)P[j][z]=P[k][z];//    ���������Ҫ�� ���Ƚ� ��v0��k��·��������v0��j��·���ϣ� 
					P[j][j]=true;    			//�ټ��� k��j��·�� j�� 
				}
		}
	}
	for(i=1;i<G.vexnum;++i){
		printf("�� v0 �� v%d ��\n",i);
		if(final[i]){
			printf("���·��Ϊ����˳�����У���");
			for(j=0;j<G.vexnum;++j){
				if(P[i][j])
					printf("%c",G.vexs[j]);
			}
			printf("\n���·������Ϊ��%d\n\n",D[i]);
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
	ShortestPath_DIJ(G,LocateVex(G,ch));
//	MiniSpanTree_PRIM(G,'a');
	printf("\n");
	return 0;
}











