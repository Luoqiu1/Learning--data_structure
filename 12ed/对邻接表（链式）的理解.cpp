#include <iostream>
using namespace std;

typedef struct ArcNode{
	int adjvex;// �ڴ�ǰ���£�ȷ����ĳ�����㣩��ͨ������֮���ӵ���һ�������λ�ã� 
	struct ArcNode *nextarc;//ָ����һ���ڴ�ǰ���£�����ȷ��������βȷ��������һ���� 
	InfoType *info;
}ArcNode;
typedef struct VNode{
	VertexType data;
//	struct VNode *firstarc;  
	//������������⣬Ϊʲô��Ҫ��һ��ָ��ָ����һ�������أ������䶨�������жϳ��������˼
	//����ļ����Ѿ����ڽӱ��������ˣ� AdjList[MAX_VERTEX_NUM]��ÿһ��Ԫ�ؾ���һ�������µĵ����������ӻ��� 
	ArcNode *firstarc;//ָ���һ�������ڸö����ָ�룡 
	
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct ALGraph{
	int kind;
	AdjList vertices;//�ڽӱ� ����ʽ�� 
	
	int vexnum,arcnum;// ͼ�ĵ�ǰ�������ͻ��� ������ȱ����� �ǵã�
					//���������ж��Ƿ���ǰ���� �������ޣ����ޣ�����Ҫ������ 
}ALGraph;//����ͷ���Ĺ��� 
int main ()
{
	return 0;
}
