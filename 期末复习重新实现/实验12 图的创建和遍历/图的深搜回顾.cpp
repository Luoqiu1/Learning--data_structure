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



int LocateVex(ALGraph G,VertexType e){
	for(int i=0;i<G.vexnum;++i){
		if(G.vertices[i].data==e)return i;
	}
	return Error;
}

Status DFS(ALGraph G,int loc)
{
	printf("%c",G.vertices[loc].data);
	visited[loc]=true;
	ArcNode *p=G.vertices[loc].firstarc;
	while(p){
		if(!final[p->adjvex]){
			DFS(G,p->adjvex);
		}
		p=p->nextarc;
	}
	return Ok;
}

Status DFSTraverse(ALGraph G,VertexType e)//从顶点的数据为e开始深搜遍历 
{
	memset(visited,0,sizeof(visited));
	//清空数组visited!
	 
	int loc=LocateVex(G,e);
	DFS(G,loc);//不够完善！这才一次，倘若在loc结点下不能一次遍历完，则会有结点未遍历到！
	for(int i=0;i<G.vexnum++i){
	//	if(i!=loc){//loc这个顶点已经遍历过了！
		//傻了 这个顶点有没有被访问过 忘记写了吗！。。
		if(!visited[i]&&i!=loc){
			DFS(G,i); 
		}
	} 
	return Ok;
 } 


Status BFSTraverse(ALGraph G,VertexType e)
{
	//先清空数组visited别忘了！
	memset(visited,0,sizeof(visited));
	 
	int loc=LocateVex(G,e);
	LinkQueue Q;InitQueue(Q);
	printf("%c",G.vertices[loc].data);
	ArcNode *p=G.vertices[loc].firstarc;
	while(p){
		if(!visited[p->adjvex]){
			visited[p->adjvex]=true;
			EnQueue(p->adjvex);
		}
		p=p->nextarc;
	}
	
//	printf("%c",G.vertices[loc].data);

	for(int i=0;i<G.vexnum;++i){
	//	if(i!=loc){
			//不够完善和严谨。。。记得一定要判断该结点是否访问过啊！
		if(!visited[i]&&i!=loc){
			//这里少了语句。。。
			//当第一次广搜没有搜完的时候，要插入到队尾！
			EnQueue(Q,i);visited[i]=true; 
 
			while(!QueueEmpty(Q)){
				int j;
				DeQueue(Q,j);
				printf("%c",G.vertices[j].data);
				p=G.vertices[j].firstarc;
				while(p){
					if(!visited[p->adjvex]){
						visited[p->adjvex]=true;
						EnQueue(p->adjvex);
					}
					p=p->nextarc;
				}
			}
		}
	}
}













