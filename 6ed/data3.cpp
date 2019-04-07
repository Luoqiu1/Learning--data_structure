#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define True 1
#define Error 0
#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN+1];//0�ŵ�Ԫ��Ŵ��ĳ���
int cnt1=0;
int cnt2=0;
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

int Index(SString S,SString T,int pos)
{
	int i=pos;int j=1;
	while(i<=S[0]&&j<=T[0]){
		cnt1++;
		if(S[i]==T[j]){
			i++;j++;
		}
		else{
			i=i-j+2;j=1;
		}
	}
	if(j>T[0])return i-T[0];
	return 0;
}

int Index_KMP(SString S,SString T,int pos)
{
	int i=pos;int j=1;int st=pos;
	while(i<=S[0]&&j<=T[0]){
		cnt2++;
		if(S[i]==T[j]){
			i++;j++;st++;
		}
		else{
			i=i-j+1+st;j=1;st=0;
		}
	}
	if(j>T[0])return i-T[0];
	return 0;
}

int main ()
{
	SString T,S1,S2,S,Sub;
	int i,pos,len;
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
	cout<<"���봮T�ĳ��ȣ�"<<endl;
	scanf("%d",&T[0]);
	getchar();
	cout<<"���봮T��ֵ��"<<endl;
	for(i=1;i<=T[0];i++){
		scanf("%c",&T[i]);
	}
	cout<<"�����T��ֵ��"<<endl;
	for(i=1;i<=T[0];i++){
		cout<<T[i];
	}
	cout<<endl;
	cout<<"����ӵ�pos���ַ���ʼ�Ƚϵ�λ��pos\n";
	cin>>pos; 
	cout<<"����Ӵ�T������S�е�pos���ַ�֮���λ�ã������������0 : \n";
	pos=Index(S,T,pos);
	cout<<pos<<endl;;
	cout<<"���øĽ��㷨�ٴν����������� ��\n";
	pos=Index_KMP(S,T,pos);
	cout<<pos<<endl;
	printf("����ֱ�ʹ�õ�һ���㷨�͵ڶ����㷨����Ҫ�����Ĵ�����%d %d \n",cnt1,cnt2); 
	return 0; 
 } 
