#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> seg,v,p,s,t;
void init(int pos,int a){
	seg[pos]=a;
	t[pos]=p[pos]=s[pos]=max(a,0);
}
void pull(int pos,int p1,int p2){
	seg[pos]=seg[p1]+seg[p2];
	p[pos]=max(p[p1],seg[p1]+p[p2]);
	s[pos]=max(s[p2],seg[p2]+s[p1]);
	t[pos]=max(max(t[p1],t[p2]),s[p1]+p[p2]);
}
void build(int l,int r,int pos){
	if(r==l){
		init(pos,v[l]);
		return;
	}
	int m=(l+r)/2;
	build(l,m,pos*2+1);
	build(m+1,r,pos*2+2);
	pull(pos,pos*2+1,pos*2+2);
}
void query(int pos,int l,int r,int a,int b){
	if(r==l){
		init(pos,b);
		return;
	}
	int m=(l+r)/2,p1=pos*2+1,p2=pos*2+2;
	if(a<=m)
		query(p1,l,m,a,b);
	else
		query(p2,m+1,r,a,b);
	pull(pos,p1,p2);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,g,x,b;
	cin>>n>>g;
	seg.resize(4*n);
	p.resize(4*n);
	s.resize(4*n);
	t.resize(4*n);
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	build(0,n-1,0);
	for(int i=0;i<g;i++){
		cin>>a>>b;
		query(0,0,n-1,a-1,b);
		cout<<t[0]<<" ";
	}
	cout<<endl;
	return 0;
}