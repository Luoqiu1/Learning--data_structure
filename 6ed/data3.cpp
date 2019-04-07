#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define True 1
#define Error 0
#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN+1];//0号单元存放串的长度
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
	cout<<"输入串S的长度："<<endl;
	scanf("%d",&S[0]);
	getchar();
	cout<<"输入串S的值："<<endl;
	for(i=1;i<=S[0];i++){
		scanf("%c",&S[i]);
	}
	cout<<"输出串S的值："<<endl;
	for(i=1;i<=S[0];i++){
		cout<<S[i];
	} 
	cout<<endl;
	cout<<"输入串T的长度："<<endl;
	scanf("%d",&T[0]);
	getchar();
	cout<<"输入串T的值："<<endl;
	for(i=1;i<=T[0];i++){
		scanf("%c",&T[i]);
	}
	cout<<"输出串T的值："<<endl;
	for(i=1;i<=T[0];i++){
		cout<<T[i];
	}
	cout<<endl;
	cout<<"输入从第pos个字符开始比较的位置pos\n";
	cin>>pos; 
	cout<<"输出子串T在主串S中第pos个字符之后的位置，若不存在输出0 : \n";
	pos=Index(S,T,pos);
	cout<<pos<<endl;;
	cout<<"利用改进算法再次进行上述操作 ：\n";
	pos=Index_KMP(S,T,pos);
	cout<<pos<<endl;
	printf("输出分别使用第一种算法和第二种算法所需要操作的次数：%d %d \n",cnt1,cnt2); 
	return 0; 
 } 
