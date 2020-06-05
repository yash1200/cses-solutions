#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
const int x=1024;
int f[x][x];
void update(int a,int b
	,int d){
	for(int i=a;i<x;i+=i&-i)
		for(int j=b;j<x;j+=j&-j)
			f[i][j]+=d;
}
int query(int a,int b){
	int ans=0;
	for(int i=a;i;i-=i&-i)
		for(int j=b;j;j-=j&-j)
			ans+=f[i][j];
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		for(int j=0;j<n;j++)
			if(v[i][j]=='*')
				update(i+1,j+1,1);
	}
	while(m--){
		int t,a,b,c,d;
		cin>>t;
		if(t==1){
			cin>>a>>b;
			if(v[a-1][b-1]=='*')
				update(a,b,-1),v[a-1][b-1]='.';
			else
				update(a,b,1),v[a-1][b-1]='*';
		}else{
			cin>>a>>b>>c>>d;
			cout<<query(c,d)+query(a-1,b-1)-query(c,b-1)-query(a-1,d)<<endl;
		}
	}
	return 0;
}