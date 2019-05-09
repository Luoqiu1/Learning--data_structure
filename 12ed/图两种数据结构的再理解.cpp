typedef struct AdjCell{
//	ArcType adj;
	VRType adj;
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	GraphKind kind;
	int vexnum,arcnum;
	VertexType vexs[MAX_VERTEX_NUM];
//	AdjMatrix adj;
	AdjMatrix arcs;
}MGraph;




typedef struct ArcNode{
//	int vex;
	int adjvex;//强调是 adj 邻接（顶点的位置）！强调同一个顶点下的不同弧头！ 
//	 data; 无数据 
//	struct ArcCell *nextarc;
	struct ArcNode *nextarc; 
	InfoType *info;
//}ArcCell; 
}ArcNode; 

typedef struct AdjList{
//	 data;
	VertexType data;//该行即实现了 32行 注释处写的“其效果已包含了关于顶点的数组！ ” 
//	ArcCell *fristarc;
	ArcNode *firstarc; 
//}AdjList[MAX_VERTEX_NUM];
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	GraphKind kind;
//	VertexType vexs[MAX_VERTEX_NUM]; 该行多余！因为已经构成了顶点的邻接表（36行）！其效果已包含了关于顶点的数组！ 
	int vexnum,arcnum;
//	AdjList arcs;  并不是弧的邻接表！再理解。。。是构建顶点的邻接表！每一个顶点下面的弧之间构成链表！
																	//即 每一个顶点均需构造一个链表	
	AdjList vertices; 
}ALGraph;
