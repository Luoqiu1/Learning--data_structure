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

bool final[MAX_VERTEX_NUM];

int LocateVex(MGraph G,VertexType e)
{
	for(int i=0;i<G.vexnum;++i){
		if(G.vexs[i]==e)return i;
	}
	return Error;
}

Status Search(MGraph G,int loc)
{
	for(int i=0;i<G.vexnum;++i){
		if(!final[loc])
	}
}

Status SearchGraph(MGraph G,VertexType e)
{
	int loc=LocateVex(G,e);
	for(int i=0;i<G.vexs;++i){
		Search(G,loc);
	}
}


Status Search(MGraph G,int loc)
{
	for(int j=0;j<G.vexnum;++j){
		if(!final[j]){
			if(G.arcs[loc][j]){
				printf("%c",G.vexs[j]);
				final[j]=true;
				Search(G,j);
			}
		}
	}
}

Status SearchGraph(MGraph G)
{
	for(int i=0;i<G.vexnum;++i){
		if(!final[i]){
			printf("%c",G.vexs[i]);
			final[i]=true;
			Search(G,i);
		} 
	}
}







