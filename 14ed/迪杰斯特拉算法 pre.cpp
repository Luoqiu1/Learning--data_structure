#include <iostream>

int main ()
{
//	for(int i=1;i<G.vexnum;++i){				
	//		i=0 Ӧ���Ǵ�0��ʼ��
						//Ī���������ôֻ��һ��ѭ��
						//��˼��ֻ��ĳһ������Ķ��㣨��д����˼��ֻ�Ե�һ�����㣩��ʼ����
						//��ʵҲ����ȫ����һ�����Ҳ��̫����
						//һ��ѭ�����ǲ�����·����ϵ�ĳ�ʼ����
						//���Ҫ����·���Ļ����򻹶�����Ҫһ��ѭ������ʼ��·����
						//��Ϊ·���Ƕ�ά���飬��ʾ������֮��Ĺ�ϵ��false�����ڣ�true����
						
	
//		if(G.arcs[0][i]<INFINITY){
//			D[i]=G.arcs[0][i];
//			p[i][0]=true;p[i][i]=true;
//		}
//	}
	
	for(int i=0;i<G.vexnum;++i){
		visited[i]=false;D[i]=arc[0][i];
		for(int j=0;j<G.vexnum;++j){
			
		}
	}
	
	
	D[0]=0;visited[0]=true;//S={V0};
//	for(int i=0;i<G.vexnum;++i){
	//�� i=1��ʼѭ�����ɣ���Ϊ��ʼ��ʱ�Ѿ���ʼ����Դ����ص����ݣ�
	for(int i=1;i<G.vexnum;++i){
		int min=INFINITY;
		int vex;
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
			//	if(G.arcs[i][j]<min){
			//  ���ﲻ�ǿ����ĳ��Ȱ������ҳ���ǰ��·��������̵�·���������ǱȽϻ���������
				if(D[j]<min){
				//	min=G.arcs[i][j]; ԭ��ͬ������
					min=D[j]; 
					vex=j;
				}
			}
		}
		visited[vex]=true;//S+={Vvex}
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
				if(D[vex]+G.arcs[vex][j]<D[j]){//D[vex]ֵ����min 
					p[j]=p[vex];p[j][j]=true;
					D[j]=D[vex]+G.arcs[vex][j];
				}
			}
		}
	}
	return 0;
}
