#include <cstdio>
int a[6]={0,5,3,2,1,7};
int main (){
	int n=6;
for(int i=0;i<n-1;++i){
	for(int j=0;j<n-i-1;++j){
		if(a[j]>a[j+1]){
			int mid=a[j];
			a[j]=a[j+1];
			a[j+1]=mid;
		}
	}}
	for(int i=0;i<n;++i)printf("%d ",a[i]);
	
 return 0;
}
