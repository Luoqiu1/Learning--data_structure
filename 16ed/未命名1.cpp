#include <cstdio>
int a[6]={0,5,3,2,1,7};
int main (){
	int n=6;
for(int i=0;i<n-1;++i){ /* ��ѭ��Ϊ����������n��������n-1�� */
	for(int j=0;j<n-i-1;++j){ /* ��ѭ��Ϊÿ�˱ȽϵĴ�������n�˱Ƚ�n-i�� */
		if(a[j]>a[j+1]){				//��Ϊ��Ҫ�õ� j+1 ���������� Ҫ���1 �� 
			int mid=a[j];
			a[j]=a[j+1];
			a[j+1]=mid;
		}
	}}
	for(int i=0;i<n;++i)printf("%d ",a[i]);
	
 return 0;
}
