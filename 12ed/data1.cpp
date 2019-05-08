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





int main ()
{
	return 0;
 } 
