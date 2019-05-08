#include <iostream>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define MAX_VERTEX_NUM 20 
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
typedef enum{DG,DN,UDG,UDN}GraphKind; 

typedef struct AdjCell{
	VRType adj;//�����ڽӱ��������һά����ά�±�v1 v2��ʾһ������ͼ�еĻ�<v1,v2>!
				//����Ȩͼ��˵���� 1��0 ��ʾ�Ƿ����ڣ���v1 v2�Ƿ����ڣ�
				//���ڴ�Ȩͼ����ΪȨֵ���ͣ����������Ϊ�����ڣ��� 
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���ṹ��Ľṹ��Ϊʲô�������� 

typedef struct { 
	AdjMatrix arcs;//�����ڽӱ�ľ���ֱֵ�ӱ�ʾ�Ƿ�����������
					//�������һ ��ά�±����Ѵ����� ��v1 v2��������ģ�
									//����ͼ�Ļ��Գ�������[v2][v1]=[v1][v2]���� 
	GraphKind kind;
	VertexType vexs[MAX_VERTEX_NUM];//��Ϊ����������ڽӱ������ǻ��Ĺ�ϵ��
						//	"	//��Ҫ�ܹ�ֱ�ӷ��ʶ�������ݽṹ�����趥������飡 "	//
						//��������ŵ�ע���ƺ������⣡������ֱ�ӷ��ʶ�������ݽṹ�����Ҳ���Ƕ�������飡
						//���Ƕ����±꼰�����ݵļ��ϣ�������Ҷ����λ�ã��Լ���¼�����������������ݣ���
						 
	int vexnum,arcnum;
}MGraph;//����ͷ���Ĵ���

int LocateVex(MGraph G,char v)//��λ�����λ�ã� 
{
	int i;
	for(i=0;i<G.vexnum;++i){
		if(G.vexs[i]==v)return i;
	}
	return -1;//δ�ҵ����������Ķ��㣡 
}
int main ()
{
	return 0;
 } 
