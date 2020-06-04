#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> seg;
void build(int l,int r,int pos){
	seg[pos]=r-l;
	if(r-l>1){
		int m=(l+r)/2;
		build(l,m,pos*2+1);
		build(m,r,pos*2+2);
	}
}
int query(int pos,int l,int r,int a){
	seg[pos]--;
	if(r-l==1)
		return r;
	int m=(l+r)/2,p1=pos*2+1,p2=pos*2+2;
	if(seg[p1]>=a)
		return query(p1,l,m,a);
	return query(p2,m,r,a-seg[p1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a;
	cin>>n;
	seg.resize(4*n);
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	build(0,n,0);
	for(int i=0;i<n;i++){
		cin>>a;
		int x=query(0,0,n,a)-1;
		cout<<v[x]<<" ";
	}
	cout<<endl;
	return 0;
}