#include <iostream>
using namespace std;
//typedef struct AdjMrathx{
//	InfoType *info;
//	struct AdjMrathx *nextarc;
//	
//}AdjNode,AdjMrathx[N][N];
//
//typedef struct Graph{
//	GraphType kind;
//	AdjMrathx adj;
//	int vexnum,arcnum;
//};

typedef struct AdjCell{
	VRType adj;//�ڽӱ��������һά����ά�±�v1 v2��ʾһ������ͼ�еĻ�<v1,v2>!
				//����Ȩͼ��˵���� 1��0 ��ʾ�Ƿ����ڣ���v1 v2�Ƿ����ڣ�
				//���ڴ�Ȩͼ����ΪȨֵ���ͣ����������Ϊ�����ڣ��� 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���ṹ��Ľṹ��Ϊʲô�������� 
typedef struct MGraph{
	AdjMatrix arcs;
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];
	int vexnum,arcnum;
};
int main ()
{
	return 0;
 } 
