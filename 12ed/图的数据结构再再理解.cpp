//typedef struct ArcCell{
typedef struct AdjCell{ //���ڽӶ����Cell��С�飩�����ǻ���Cell���� 
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
	int adjvex;//��Сд����д����
		//�ڽӶ������˼ 
		//adj ���� vex ����ļ�д�� 
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;
//typedef struct {
typedef struct VNode{ // ���Ƕ���ļ��ϣ�
					//�ٶ�ÿ�������¶��趥���µ����� 
	VertexType data;
	ArcNode *firstarc;
//};
}VNode,AdjList[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	GraphKind kind;
	int vexnum,arcnum;
//	 vertices[MAX_VERTEX_NUM]; 
	AdjList vertices;// �ڽӱ� -> AdjList ! 
}ALGraph;
