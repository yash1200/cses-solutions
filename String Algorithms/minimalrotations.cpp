//Booths Algorithm
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int x=a.length(),j;
	a+=a;
	int f[a.length()]={-1},k=0;
	for(int i=1;i<a.length();i++){
		char ch=a[i];
		j=f[i-k-1];
		while(j!=-1&&ch!=a[k+j+1]){
			if(ch<a[k+j+1])
				k=i-j-1;
			j=f[j];
		}
		if(ch!=a[k+j+1]){
			if(ch<a[k])
				k=i;
			f[i-k]=-1;
		}else
			f[i-k]=j+1;
	}
	for(int i=0;i<x;i++)
		cout<<a[i+k];
	cout<<endl;
	return 0;
}