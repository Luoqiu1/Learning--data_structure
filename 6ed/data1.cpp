#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define True 1
#define Error 0
#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN+1];//0�ŵ�Ԫ��Ŵ��ĳ���

Status Concat(SString &T,SString S1,SString S2)
{
	if(S1[0]+S2[0]<=MAXSTRLEN){
		T[0]=S1[0]+S2[0];
	//	printf("%d",T[0]);
		int i;for(i=1;i<=S1[0];i++)T[i]=S1[i];
		for(i=1;i<=S2[0];i++)T[i+S1[0]]=S2[i];
	}
	else if(S1[0]>MAXSTRLEN){
		T[0]=MAXSTRLEN;
		int i;for(i=1;i<=MAXSTRLEN;i++)T[i]=S1[i];
	}
	else{
		T[0]=MAXSTRLEN;
		int i;for(i=1;i<=S1[0];i++)T[i]=S1[i];
		for(i=1;i<=MAXSTRLEN-S1[0];i++)T[MAXSTRLEN+i]=S2[i];
	}
	return True;
}

Status SubString(SString &Sub,SString S,int pos,int len)
{
	if(pos<1||len>MAXSTRLEN||len>MAXSTRLEN-pos) return Error;
	Sub[0]=len;
	int i,j=1;for(i=pos;i<=pos+len;i++)Sub[j++]=S[i];
	return True;
}

int main ()
{
	SString T,S1,S2,S,Sub;
	int i,pos,len;
	cout<<"���봮S1�ĳ��ȣ�"<<endl;
	scanf("%d",&S1[0]);
	getchar();
	cout<<"���봮S1��ֵ��"<<endl;
	for(i=1;i<=S1[0];i++){
		scanf("%c",&S1[i]);
	}
	cout<<"�����S1��ֵ��"<<endl;
	for(i=1;i<=S1[0];i++){
		cout<<S1[i];
	} 
	cout<<endl;
	cout<<"���봮S2�ĳ��ȣ�"<<endl;
	scanf("%d",&S2[0]);
	getchar();
	cout<<"���봮S2��ֵ��"<<endl;
	for(i=1;i<=S2[0];i++){
		scanf("%c",&S2[i]);
	}
	cout<<"�����S2��ֵ��"<<endl;
	for(i=1;i<=S2[0];i++){
		cout<<S2[i];
	} 
	cout<<endl;
	Concat(T,S1,S2);
	cout<<"�����S1�ʹ�S2�����Ӵ�T��ֵ��"<<endl;
//	printf("%d",T[0]);
	for(i=1;i<=T[0];i++){
	//	printf("%d",T[0]);
		cout<<T[i];
	}
	cout<<endl;
	cout<<"���봮S�ĳ��ȣ�"<<endl;
	scanf("%d",&S[0]);
	getchar();
	cout<<"���봮S��ֵ��"<<endl;
	for(i=1;i<=S[0];i++){
		scanf("%c",&S[i]);
	}
	cout<<"�����S��ֵ��"<<endl;
	for(i=1;i<=S[0];i++){
		cout<<S[i];
	} 
	cout<<endl;
	cout<<"���봮S���Ӵ�Sub�Ŀ�ʼ�ַ�λ�ã�";
	cin>>pos;
	cout<<"���봮S���ִ�Sub�ĳ���";
	cin>>len;
	SubString(Sub,S,pos,len);
	cout<<"����Ӵ�Sub��ֵ��\n";
	for(i=1;i<=Sub[0];i++){
		cout<<Sub[i];
	} 
	cout<<endl;
	return 0;
 } 
