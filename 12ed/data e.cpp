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
	VRType adj;//邻接表，用数组的一维、二维下标v1 v2表示一段有向图中的弧<v1,v2>!
				//对无权图来说，用 1或0 表示是否相邻！（v1 v2是否相邻）
				//对于带权图，则为权值类型！（无穷大则为非相邻！） 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//理解结构体的结构！为什么是这样！ 
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
