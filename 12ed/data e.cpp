#include <iostream>
using namespace std;
#define INT_MAX 0x3f3f3f3f
#define INFINITY INT_MAX
typedef enum{DG,DN,UDG,UDN} GraphKind; 
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
	VRType adj;//�����ڽӱ��������һά����ά�±�v1 v2��ʾһ������ͼ�еĻ�<v1,v2>!
				//����Ȩͼ��˵���� 1��0 ��ʾ�Ƿ����ڣ���v1 v2�Ƿ����ڣ�
				//���ڴ�Ȩͼ����ΪȨֵ���ͣ����������Ϊ�����ڣ��� 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���ṹ��Ľṹ��Ϊʲô�������� 
typedef struct MGraph{//����ͷ���Ĵ��� 
	AdjMatrix arcs;//�����ڽӱ�ľ���ֱֵ�ӱ�ʾ�Ƿ�����������
					//�������һ ��ά�±����Ѵ����� ��v1 v2��������ģ�
									//����ͼ�Ļ��Գ�������[v2][v1]=[v1][v2]���� 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//��Ϊ����������ڽӱ������ǻ��Ĺ�ϵ��
								//��Ҫ�ܹ�ֱ�ӷ��ʶ�������ݽṹ�����趥������飡 
	int vexnum,arcnum;
};
int main ()
{
	return 0;
 } 
