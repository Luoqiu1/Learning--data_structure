typedef struct ArcNode{
//	VertexType data;
	//这里没理解透彻。。只要表示相邻的顶点下标即可！
	int adjvex; 
	 
	InfoType *info;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	VertexType data;
//	ArcNode *fristarc;
	ArcNode *firstarc;
//}VNode,AdjMartrix[MAXVERTEXSIZE];
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct {
	GraphKind kind;
//	AdjMartrix vecs;
	AdjList vertices;
//	int vertexs,arcs;
	int vexnum,arcnum;
}ALGraph;

//typedef struct ArcCell{
typedef struct AdjCell{//意思是邻接的小单位 Adj Cell 而不是弧的小单位！
								//弧不可用作矩阵啊！ 
	VRType data;
	InfoType *info;
//}ArcCell,Martrix[MAXVERTEXSIZE];
//						矩阵是二维数组。。在想什么呢！ 
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// 

typedef struct{
	GraphKind kind;
//	Martrix arcs;
	AdjMatrix arcs;
	//Adj 邻接 
//	int vertexs,arcs;
	int vexnum,arcnum;
	//还需要一个数组来快速找到每个顶点对应的下标！
	VertexType vexs[MAX_VERTEX_NUM]; 
	 
//}Graph;
}MGraph;
