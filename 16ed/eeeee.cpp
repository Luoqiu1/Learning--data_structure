//#include <stdio.h>
//int main ()
//{
//	int a[3][3];
//	int sum=0;
//	int i,j;
////	for(i=0;i<3;++i){
////		for(j=0;j<3;++j){
////			scanf("%d",&a[i][j]);
////		}
////	}
//	
//	for(i=0;i<3;++i){
//		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
//	}
//	
//	for(i=0;i<3;++i){
//		sum+=a[i][i];
//	}
//	printf("%d",sum);
//	return 0;
//}


#include <stdio.h>
int main ()
{
	int a[3][3],i,j,sum=0;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			scanf("%3d",&a[i][j]);
		}
	}
	for(i=0;i<3;++i){
		sum=sum+a[i][i];
	}
	printf("%d",sum);
	return 0;
}
