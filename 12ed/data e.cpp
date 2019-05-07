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
	VRType adj;//数组邻接表，用数组的一维、二维下标v1 v2表示一段有向图中的弧<v1,v2>!
				//对无权图来说，用 1或0 表示是否相邻！（v1 v2是否相邻）
				//对于带权图，则为权值类型！（无穷大则为非相邻！） 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//理解结构体的结构！为什么是这样！ 
typedef struct MGraph{//类似头结点的存在 
	AdjMatrix arcs;//数组邻接表的具体值直接表示是否存在这个弧！
					//其数组的一 二维下标则已代表了 弧v1 v2！是有向的！
									//无向图的话对称来，另[v2][v1]=[v1][v2]即可 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//因为上面的数组邻接表代表的是弧的关系！
								//需要能够直接访问顶点的数据结构！即设顶点的数组！ 
	int vexnum,arcnum;
};
int main ()
{
	return 0;
 } 
