#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> seg,vi;
void updateTree(int l,int h,int pos,int val,int node){
	if(l==h){
		vi[pos]=val;
		seg[node]=val;
		return;
	}
	int mid=(l+h)/2;
	if(pos>=l&&pos<=mid)
		updateTree(l,mid,pos,val,2*node+1);
	else
		updateTree(mid+1,h,pos,val,2*node+2);
	seg[node]=min(seg[2*node+1],seg[2*node+2]);
}
void constructTree(int l,int h,int pos){
	if(l==h){
		seg[pos]=vi[l];
		return;
	}
	int mid=(l+h)/2;
	constructTree(l,mid,(2*pos)+1);
	constructTree(mid+1,h,(2*pos)+2);
	seg[pos]=min(seg[(2*pos)+1],seg[(2*pos)+2]);
}
ll rangeQuery(int ql,int qh,int l,int h,int pos){
	if(ql<=l&&qh>=h)
		return seg[pos];
	if(ql>h||qh<l)
		return INT_MAX;
	int mid=(l+h)/2;
	return min(rangeQuery(ql,qh,l,mid,(2*pos)+1),rangeQuery(ql,qh,mid+1,h,(2*pos)+2));
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n,q,a,b,o;
	cin>>n>>q;
	vector<ll> ar(n);
	int x=ceil((double)log2(n));
	vector<ll> g(2*(int)pow(2,x)-1);
	seg=g;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	vi=ar;
	constructTree(0,n-1,0);
	while(q--){
		cin>>o;
		if(o==1){
			cin>>a>>b;
			updateTree(0,n-1,a-1,b,0);
		}else{
			cin>>a>>b;
			cout<<rangeQuery(a-1,b-1,0,n-1,0)<<endl;
		}
	}
	return 0;
}