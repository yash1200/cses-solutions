#include<bits/stdc++.h>
using namespace std;
int main(){
	string t;
	cin>>t;
	int N=t.length();
	if(N==0)
		return 0;
	N=2*N+1;
	int L[N]={0},C=1,R=2,i=0,m,mlps=0,mpos=0,d=-1;
	L[1]=1;
	for(i=2;i<N;i++){
		m=2*C-i;
		L[i]=0; 
		d=R-i;
		if(d>0)
			L[i]=min(L[m],d);
		while(((i+L[i])<N&&(i-L[i])>0)&&(((i+L[i]+1)%2==0)||(t[(i+L[i]+1)/2]==t[(i-L[i]-1)/2])))
			L[i]++;
		if(L[i]>mlps)
			mlps=L[i],mpos=i;
		if(i+L[i]>R)
			C=i,R=i+L[i];
	}
	int s=(mpos-mlps)/2,e=s+mlps-1;
	for(i=s;i<=e;i++)
		cout<<t[i];
	cout<<endl;
	return 0;
}