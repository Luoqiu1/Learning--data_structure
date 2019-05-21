//typedef struct ArcCell{
typedef struct AdjCell{ //是邻接顶点的Cell（小块）！不是弧的Cell。。 
	VRType adj;
	InfoType *info;
//}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph{
	GraphKind kind;
	int vexnum,arcnum;
	AdjMatrix arcs;
	VertexType vexs[MAX_VERTEX_NUM];
}MGraph; 

typedef struct ArcNode{
//	int AdjVertex;
	int adjvex;//用小写、简写即可
		//邻接顶点的意思 
		//adj 相邻 vex 顶点的简写！ 
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;
//typedef struct {
typedef struct VNode{ // 先是顶点的集合！
					//再对每个顶点下都设顶点下的链表！ 
	VertexType data;
	ArcNode *firstarc;
//};
}VNode,AdjList[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	GraphKind kind;
	int vexnum,arcnum;
//	 vertices[MAX_VERTEX_NUM]; 
	AdjList vertices;// 邻接表 -> AdjList ! 
}ALGraph;
