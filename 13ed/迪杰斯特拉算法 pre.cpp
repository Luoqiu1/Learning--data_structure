#include <iostream>

int main ()
{
//	for(int i=1;i<G.vexnum;++i){				
	//		i=0 应该是从0开始！
						//莫名其妙啊，怎么只有一重循环
						//意思是只对某一个特殊的顶点（我写的意思是只对第一个顶点）初始化吗？
						//其实也不是全错，上一行理解也不太完整
						//一重循环仅是不考虑路径关系的初始化！
						//如果要考虑路径的话，则还额外需要一重循环来初始化路径！
						//因为路径是二维数组，表示两条边之间的关系！false不存在，true存在
						
	
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
	//从 i=1开始循环即可！因为初始化时已经初始化了源点相关的数据！
	for(int i=1;i<G.vexnum;++i){
		int min=INFINITY;
		int vex;
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
			//	if(G.arcs[i][j]<min){
			//  这里不是看弧的长度啊！是找出当前下路径长度最短的路径！而不是比较弧长。。。
				if(D[j]<min){
				//	min=G.arcs[i][j]; 原因同上上行
					min=D[j]; 
					vex=j;
				}
			}
		}
		visited[vex]=true;//S+={Vvex}
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
				if(D[vex]+G.arcs[vex][j]<D[j]){//D[vex]值等于min 
					p[j]=p[vex];p[j][j]=true;
					D[j]=D[vex]+G.arcs[vex][j];
				}
			}
		}
	}
	return 0;
}
