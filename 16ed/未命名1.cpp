#include <cstdio>
int a[6]={0,5,3,2,1,7};
int main (){
	int n=6;
for(int i=0;i<n-1;++i){ /* 外循环为排序趟数，n个数进行n-1趟 */
	for(int j=0;j<n-i-1;++j){ /* 内循环为每趟比较的次数，第n趟比较n-i次 */
		if(a[j]>a[j+1]){				//因为是要用到 j+1 所以条件中 要多减1 ！ 
			int mid=a[j];
			a[j]=a[j+1];
			a[j+1]=mid;
		}
	}}
	for(int i=0;i<n;++i)printf("%d ",a[i]);
	
 return 0;
}
