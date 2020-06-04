#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> seg,v;
void build(int l,int r,int pos){
	if(r==l){
		seg[pos]=v[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,pos*2+1);
	build(m+1,r,pos*2+2);
	seg[pos]=max(seg[pos*2+1],seg[pos*2+2]);
}
int query(int pos,int l,int r,int a){
	if(r==l){
		seg[pos]-=a;
		return l;
	}
	int m=(l+r)/2,p1=pos*2+1,p2=pos*2+2;
	int i=seg[p1]>=a?query(p1,l,m,a):query(p2,m+1,r,a);
	seg[pos]=max(seg[p1],seg[p2]);
	return i;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,g,x;
	cin>>n>>g;
	seg.resize(4*n);
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	build(0,n-1,0);
	for(int i=0;i<g;i++){
		cin>>a;
		x=seg[0]>=a?query(0,0,n-1,a)+1:0;
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}