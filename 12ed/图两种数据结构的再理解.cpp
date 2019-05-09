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
	int adjvex;//ǿ���� adj �ڽӣ������λ�ã���ǿ��ͬһ�������µĲ�ͬ��ͷ�� 
//	 data; ������ 
//	struct ArcCell *nextarc;
	struct ArcNode *nextarc; 
	InfoType *info;
//}ArcCell; 
}ArcNode; 

typedef struct AdjList{
//	 data;
	VertexType data;//���м�ʵ���� 32�� ע�ʹ�д�ġ���Ч���Ѱ����˹��ڶ�������飡 �� 
//	ArcCell *fristarc;
	ArcNode *firstarc; 
//}AdjList[MAX_VERTEX_NUM];
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	GraphKind kind;
//	VertexType vexs[MAX_VERTEX_NUM]; ���ж��࣡��Ϊ�Ѿ������˶�����ڽӱ�36�У�����Ч���Ѱ����˹��ڶ�������飡 
	int vexnum,arcnum;
//	AdjList arcs;  �����ǻ����ڽӱ�����⡣�����ǹ���������ڽӱ�ÿһ����������Ļ�֮�乹������
																	//�� ÿһ��������蹹��һ������	
	AdjList vertices; 
}ALGraph;
