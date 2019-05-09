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

typedef struct ArcNode{
	
	//���������ˣ��ڽӱ��������������ͬһ�������µ��ڽӵĻ��ļ��ϣ�
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

int main ()
{
	return 0;
}




