
//typedef struct AdjVex{
typedef struct AdjCell{
//	int adj;
	VRType adj;
	InfoType *info;
//}AdjVex,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph{
	GraphKind kind;
	int vexnum,arcnum;
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
}MGraph; 

typedef struct ArcNode{
	InfoType *info;
//	int vertex; //Ҫǿ�����ڽӡ���
	int adjvex;//adj ���ڵļ�д! 
	struct ArcNode *nextarc; 
}ArcNode;
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct ALGraph{
	GraphKind kind;
	int vexnum,arcnum;
	AdjList vertices; 
}ALGraph;








