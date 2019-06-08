#include <bits/stdc++.h>
using namespace std;

int main ()
{
	char a[99];int n;
	while(cin>>a){
		if(a[0]=='[')n++;
		memset(a,0,sizeof(a));
	}
	cout<<n;
 } 
