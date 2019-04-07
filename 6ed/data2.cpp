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
	printf("����ַ������� chars: %s\n",chars);
	StrAssign(T,chars);
	printf("����һ����ֵ���ڴ����� chars �Ĵ� T: ");
	DispStr(T);
	StrCopy(S,T);
	printf("���� T ��ֵ���Ƶ��� S �У��� S ��ֵΪ: ");
	DispStr(S);
	printf("�� S �ĳ���Ϊ: %d\n",StrLength(S));
	printf("�Ƚϴ� S �ʹ� T �Ĵ�С: %d\n",StrCompare(S,T));
	printf("�� S ��Ϊ�մ���\n");
	ClearString(S);
	printf("�� S ��ֵΪ: ");
	DispStr(S);
	printf("�� T ��ֵΪ: ");
	DispStr(T);
	a=str;
	printf("���봮 S1: ");
	scanf("%s",a);
	StrAssign(S1,a);
	printf("�� S1 ��ֵΪ: ");
	DispStr(S1);
	printf("���봮 S2: ");
	scanf("%s",a);
	StrAssign(S2,a);
	printf("�� S2 ��ֵΪ: ");
	DispStr(S2);
	printf("������ S1 �� S2 ���Ӷ��ɵ��´� S: ");
	Concat(S,S1,S2);
	DispStr(S);
	printf("���� S ���Ӵ�����ʼ�ַ�λ��: ");
	scanf("%d",&pos);
	printf("���� S ���Ӵ��ĳ���: ");
	scanf("%d",&len);
	printf("�� Sub ���ش� S �ĵ�%d���ַ��𳤶�Ϊ%d���Ӵ�: ",pos,len);
	SubString(Sub,S,pos,len);
	DispStr(Sub);
	printf("���봮 S �Ĳ���λ��");
	cin>>pos;
	printf("�ڴ� S �ĵ�%d��λ�ò��봮T������� S ��ֵΪ: ",pos);
	StrInsert(S,pos,T);
	DispStr(S);
	printf("���봮 S ɾ�����Ӵ�����ʼ�ַ�λ��: ");
	cin>>pos;
	printf("���봮 S ɾ�����Ӵ��ĳ���: ");
	cin>>len;
	printf("�� S ��ɾ����%d���ַ��𳤶�Ϊ%d���Ӵ���ɾ���� S ��ֵΪ: ",pos,len);
	StrDelete(S,pos,len);
	DispStr(S); 
	return 0;
 } 
