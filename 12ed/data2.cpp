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
	
	//���������ˣ��ڽӱ��������������ͬһ�������µ��ڽӵĻ��ļ��ϣ�
	//ͨ��������������ݽṹ����Ϊ���ݽṹ��Ϊ������ĳһҪ���������������ģ� 
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
	//��ǰ����µĶ����������� һ����Ҫ���ǰ������� 
	int vexnum,arcnum;
}ALGraph;

int NextAdjVex(ALGraph G,int v,int w)
{
//	printf("NAdjǰ v=%d\n",v);
	ArcNode *p=G.vertices[v].firstarc;
//	if(p==nullptr)printf("  p==nullptr v=%d  ",v);
	while(p){
		if(p->adjvex==w){
		//	if(p->nextarc&&!visited[p->nextarc->adjvex]) 
							//��ȫ����Ҫ�ж��Ƿ��Ѿ����ʹ���
							//��Ϊ���������Ŀ�Ľ������ҵ���һ���ڽӶ��㣡
							//�ж��Ƿ���ʹ�����һ�㺯���У�if(!visited[w])��ʵ���ˣ� 
			if(p->nextarc) 
				return p->nextarc->adjvex;
		}
	//	else p=p->nextarc; ������������һ��������else���������������
					//���ڶ�λ���˵Ķ���λ�ã��򲻻�����ǰ�Һ�һ���ڽӶ����ˣ�������
		//ʵ���� ������һ��������else�� ��Ϊ��Ҫÿ����Ҫ������ȥ�� 
		//��ǿ������������⣡ 
							 
		p=p->nextarc;
	}
//	printf("NAdj�� v=%d\n",v);
	return -1;
}

int FirstAdjVex(ALGraph G,int v)
{
//	printf("FAdjǰ v=%d\n",v);
	if(G.vertices[v].firstarc){
		return G.vertices[v].firstarc->adjvex;
	}
//	printf("FAdj�� v=%d\n",v);
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
			pi->info=nullptr;
			pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;// �������ǲ�������
			G.vertices[i].firstarc=pi;// �����Ļ�����������ͷ������һ����λ�ã� 
	//	}
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
	//	else{
			pj->info=nullptr;
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

Status CreateUDN(ALGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	ArcNode *pi,*pj;
	printf("���붥���� G.vexnum��");scanf("%d",&G.vexnum);
	printf("������� G.arcnum��");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		printf("���붥�� G.vertices[%d].data:",i);
		scanf("%c",&G.vertices[i].data);getchar();
		G.vertices[i].firstarc=nullptr;
	}
	for(k=0;k<G.arcnum;++k){
		printf("������� %d ���ߵĶ��� v1��v2 �Լ�Ȩֵ w (int)��\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		//�ٴ����malloc��Ϊĳһָ�����һ�ռ䣬��ʵ���Ƿ�����һ������ĵ�ַ�� 
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
	printf("���붥���� G.vexnum��");scanf("%d",&G.vexnum);
	printf("���뻡�� G.arcnum��");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		printf("���붥�� G.vertices[%d].data��",i);scanf("%c",&G.vertices[i].data);getchar();
		G.vertices[i].firstarc=nullptr;//��仰һ������©������	�������Ұָ���ˣ���ַ�ǿգ�
						//ʹ��ָ��ǰһ��Ҫ���ָ���Ƿ������壨Ұָ�����������©����
						//����Ӧ���ڴ���ָ���ʱ�����ָ��Ϊ��ָ�룡 
	}
	for(k=0;k<G.arcnum;++k){
		printf("������� %d �����Ļ�βv1����ͷv2 �Լ�Ȩֵ w (int)��\n",k+1);
		scanf("%c %c %d",&v1,&v2,&w);getchar();
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		*pi->info=w;
	//	pi->adjvex=i;pi->nextarc=G.vertices[i].firstarc;
		//ע�⣡������û�г������ͼ��
		//���ڶ�����ڽӱ�vex->adjvex�ǹ���ĳһ�������µ����е��ڽӶ���ļ��ϣ� 
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
	printf("���붥���� G.vexnum��");scanf("%d",&G.vexnum);
	printf("���뻡�� G.arcnum��");scanf("%d",&G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;++i){
		G.vertices[i].firstarc=nullptr;
		printf("���붥�� G.vertices[%d].data��",i);scanf("%c",&G.vertices[i].data);getchar();
	}
	for(k=0;k<G.arcnum;++k){
		printf("������� %d �����Ļ�βv1����ͷv2��\n",k+1);
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
	printf("������ͼ�����ࣺ0 ��ʾ DG��1 ��ʾ DN��2 ��ʾ UDG��3 ��ʾ UDN\n");
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
	printf("����ڽӱ�\n\n");
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




