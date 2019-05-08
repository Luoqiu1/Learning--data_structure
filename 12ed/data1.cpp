#include <iostream>
using namespace std;
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

typedef struct AdjCell{
	VRType adj;//数组邻接表，用数组的一维、二维下标v1 v2表示一段有向图中的弧<v1,v2>!
				//对无权图来说，用 1或0 表示是否相邻！（v1 v2是否相邻）
				//对于带权图，则为权值类型！（无穷大则为非相邻！） 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//理解结构体的结构！为什么是这样！ 

typedef struct { 
	AdjMatrix arcs;//数组邻接表的具体值直接表示是否存在这个弧！
					//其数组的一 二维下标则已代表了 弧v1 v2！是有向的！
									//无向图的话对称来，另[v2][v1]=[v1][v2]即可 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//因为上面的数组邻接表代表的是弧的关系！
						//	"	//需要能够直接访问顶点的数据结构！即设顶点的数组！ "	//
						//上面打引号的注释似乎有问题！并不是直接访问顶点的数据结构，设的也不是顶点的数组！
						//而是顶点下标及其数据的集合！方便查找顶点的位置（以及记录顶点自身所带的数据）！
						 
	int vexnum,arcnum;
}MGraph;//类似头结点的存在

int LocateVex(MGraph G,char v)//定位顶点的位置！ 
{
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.vexs[i]==v)return i;
	}
	return -1;//未找到符合条件的顶点！ 
}
int main ()
{
	return 0;
 } 
