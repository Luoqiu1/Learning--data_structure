#include <bits/stdc++.h>
using namespace std;
typedef int Status;
#define Overflow -2
#define Ok 1
#define Error 0
typedef struct {
	char *ch;
	int length;
}HString;

Status StrAssign(HString &T,char *chars)
{
	if(T.ch) free(T.ch);
	int i;
	for(i=0;chars[i]!='\0';i++);
	if(!i){
		T.ch=NULL;T.length=i;return Ok;
	}
	T.length=i;
	T.ch=(char*)malloc((T.length+1)*sizeof(char));
	if(!T.ch)exit(Overflow);
	for(i=0;i<=T.length;i++){
		T.ch[i]=chars[i];
	}
	return Ok;
}

Status DispStr(HString T)
{
	if(!T.ch)return Error;
	for(int i=0;i<T.length;i++)cout<<T.ch[i];
	return Ok;
}

Status StrCopy(HString &S,HString T)
{
	if(!T.ch)exit(Overflow);
	if(S.ch) free(S.ch);
	if(!(S.ch=( char* )malloc( (T.length+1) * sizeof ( char ) ) ) ) exit(Overflow);
	for(int i=0;i<=T.length;i++){
		S.ch[i]=T.ch[i];
	}
	S.length=T.length; 
	return Ok;
}

Status ClearString(HString &S)
{
	if(!S.ch)return Error;
	free(S.ch);S.ch=NULL;
	return Ok;
}

Status Concat(HString &S,HString S1,HString S2)
{
	if(S.ch) free(S.ch);
	if(!(S.ch=(char*)malloc( (S1.length+S2.length+1)*sizeof(char) )))exit(Overflow);
	for(int i=0;i<S1.length;i++){
		S.ch[i]=S1.ch[i];
	}
	for(int i=S1.length,j=0;j<=S2.length;i++,j++){
		S.ch[i]=S2.ch[j];
	}
	S.length=S1.length+S2.length;
	return Ok;
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
	if(pos<1||pos>S.length||pos+len-1>S.length)return Error;
	if(Sub.ch) free(Sub.ch);
	if(!(Sub.ch=(char*)malloc((len+1)*sizeof(char))))exit(Overflow);
	Sub.length=len;
//	cout<<"here";
	for(int i=0,j=pos-1;i<len;i++,j++){
//		cout<<S.ch[j];
		Sub.ch[i]=S.ch[j];
//		cout<<"here3";
	}
	Sub.ch[len]='\0';
//	cout<<"here2";
	return Ok;
}

Status StrInsert(HString &S,int pos,HString T)
{
	if(pos<1||pos>S.length+1)exit(Overflow);
	S.ch=(char*)realloc(S.ch,(S.length+T.length+1)*sizeof(char));
	if(!S.ch)exit(Overflow);
	for(int i=S.length;i>=pos-1;i--){
		S.ch[i+T.length]=S.ch[i];
	}
	for(int i=pos-1,j=0;j<T.length;i++,j++){
		S.ch[i]=T.ch[j];
	}
	S.length=S.length+T.length;
	return Ok;
}

Status StrDelete(HString &S,int pos,int len)
{
	if(pos<1||pos>S.length)exit(Overflow);
	for(int i=pos-1,j=0;j<S.length-pos;i++,j++){
		S.ch[i]=S.ch[i+len];
	}
	S.length=S.length-len;
}

Status StrLength(HString S)
{
	int i;
	for(i=0;S.ch[i]!='\0';i++);
	return i;
}

Status StrCompare(HString S,HString T)
{
	for(int i=0;i<S.length&&i<T.length;i++){
		if(S.ch[i]!=T.ch[i])return S.ch[i]-T.ch[i];
	}
	return 0;
}

int main ()
{
	int pos,len;
	HString T,S,S1,S2,Sub;
	char *a,str[100],chars[]="House";
	T.ch=NULL;
	S.ch=NULL;
	S1.ch=NULL;
	S2.ch=NULL;
	Sub.ch=NULL;
	printf("输出字符串常量 chars: %s\n",chars);
	StrAssign(T,chars);
	printf("生成一个其值等于串常量 chars 的串 T: ");
	DispStr(T);
	StrCopy(S,T);
	printf("将串 T 的值复制到串 S 中，串 S 的值为: ");
	DispStr(S);
	printf("串 S 的长度为: %d\n",StrLength(S));
	printf("比较串 S 和串 T 的大小: %d\n",StrCompare(S,T));
	printf("将 S 清为空串！\n");
	ClearString(S);
	printf("串 S 的值为: ");
	DispStr(S);
	printf("串 T 的值为: ");
	DispStr(T);
	a=str;
	printf("输入串 S1: ");
	scanf("%s",a);
	StrAssign(S1,a);
	printf("串 S1 的值为: ");
	DispStr(S1);
	printf("输入串 S2: ");
	scanf("%s",a);
	StrAssign(S2,a);
	printf("串 S2 的值为: ");
	DispStr(S2);
	printf("返回由 S1 和 S2 联接而成的新串 S: ");
	Concat(S,S1,S2);
	DispStr(S);
	printf("输入 S 的子串的起始字符位置: ");
	scanf("%d",&pos);
	printf("输入 S 的子串的长度: ");
	scanf("%d",&len);
	printf("用 Sub 返回串 S 的第%d个字符起长度为%d的子串: ",pos,len);
	SubString(Sub,S,pos,len);
	DispStr(Sub);
	printf("输入串 S 的插入位置");
	cin>>pos;
	printf("在串 S 的第%d个位置插入串T，插入后串 S 的值为: ",pos);
	StrInsert(S,pos,T);
	DispStr(S);
	printf("输入串 S 删除的子串的起始字符位置: ");
	cin>>pos;
	printf("输入串 S 删除的子串的长度: ");
	cin>>len;
	printf("串 S 中删除第%d个字符起长度为%d的子串，删除后 S 的值为: ",pos,len);
	StrDelete(S,pos,len);
	DispStr(S); 
	return 0;
 } 
