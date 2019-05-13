#include <iostream>

int main ()
{
	for(int i=1;i<G.vexnum;++i){
		if(G.arcs[0][i]<INFINITY){
			D[i]=G.arcs[0][i];
			p[i][0]=true;p[i][i]=true;
		}
	}
	D[0]=0;visited[0]=true;//S={V0};
	int mid=INFINITY;
	for(int i=0;i<G.vexnum;++i){
		int vex;
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
				if(G.arcs[i][j]<mid){
					mid=G.arcs[i][j];
					vex=j;
				}
			}
		}
		visited[vex]=true;//S+={Vvex}
		for(int j=0;j<G.vexnum;++j){
			if(!visited[j]){
				if(D[v]+G.arcs[vex][j]<D[j]){
					p[j]=p[vex];
					D[j]=D[vex]+G.arcs[vex][j];
				}
			}
		}
	}
	return 0;
}
