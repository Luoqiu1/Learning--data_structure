typedef struct ArcNode{
//	VertexType data;
	//����û���͸������ֻҪ��ʾ���ڵĶ����±꼴�ɣ�
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
typedef struct AdjCell{//��˼���ڽӵ�С��λ Adj Cell �����ǻ���С��λ��
								//�������������󰡣� 
	VRType data;
	InfoType *info;
//}ArcCell,Martrix[MAXVERTEXSIZE];
//						�����Ƕ�ά���顣������ʲô�أ� 
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// 

typedef struct{
	GraphKind kind;
//	Martrix arcs;
	AdjMatrix arcs;
	//Adj �ڽ� 
//	int vertexs,arcs;
	int vexnum,arcnum;
	//����Ҫһ�������������ҵ�ÿ�������Ӧ���±꣡
	VertexType vexs[MAX_VERTEX_NUM]; 
	 
//}Graph;
}MGraph;
