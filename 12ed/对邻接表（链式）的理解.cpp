#include <iostream>
using namespace std;

typedef struct ArcNode{
	int adjvex;// 在大前提下（确定的某个顶点），通过弧与之链接的另一个顶点的位置！ 
	struct ArcNode *nextarc;//指向下一条在大前提下（顶点确定，即弧尾确定）的下一条弧 
	InfoType *info;
}ArcNode;
typedef struct VNode{
	VertexType data;
//	struct VNode *firstarc;  
	//上条语句有问题，为什么需要有一个指针指向另一个顶点呢？（按其定义的语句判断出是这个意思
	//顶点的集合已经在邻接表中体现了！ AdjList[MAX_VERTEX_NUM]中每一个元素就是一个顶点下的单链表！（链接弧） 
	ArcNode *firstarc;//指向第一条依附于该顶点的指针！ 
	
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct ALGraph{
	int kind;
	AdjList vertices;//邻接表 （链式） 
	
	int vexnum,arcnum;// 图的当前顶点数和弧数 ！不能缺少这个 记得！
					//该条件是判断是否提前结束 或者上限（界限）的重要条件！ 
}ALGraph;//类似头结点的功能 
int main ()
{
	return 0;
}
