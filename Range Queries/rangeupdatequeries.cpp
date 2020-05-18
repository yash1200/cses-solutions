#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> seg,vi,lazy;
void updateTree(int pos,int l,int h,int ql,int qh,int diff){
	if(lazy[pos]!=0){
		seg[pos]+=(h-l+1)*lazy[pos];
		if(l!=h){
			lazy[pos*2+1]+=lazy[pos];
			lazy[pos*2+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(l>qh||h<ql)
		return;
	if(l>=ql&&h<=qh){
		seg[pos]+=(h-l+1)*diff;
		if(l!=h){
			lazy[pos*2+1]+=diff;
			lazy[pos*2+2]+=diff;
		}
		return;
	}
	int mid=(l+h)/2;
	updateTree(pos*2+1,l,mid,ql,qh,diff);
	updateTree(pos*2+2,mid+1,h,ql,qh,diff);
	seg[pos]=seg[pos*2+1]+seg[pos*2+2];
}
void constructTree(int l,int h,int pos){
	if(l==h){
		seg[pos]=vi[l];
		return;
	}
	int mid=(l+h)/2;
	constructTree(l,mid,(2*pos)+1);
	constructTree(mid+1,h,(2*pos)+2);
	seg[pos]=seg[(2*pos)+1]+seg[(2*pos)+2];
}
ll rangeQuery(int ql,int qh,int l,int h,int pos){
	if(lazy[pos]!=0){
		seg[pos]+=(h-l+1)*lazy[pos];
		if(l!=h){
			lazy[pos*2+1]+=lazy[pos];
			lazy[pos*2+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(ql<=l&&qh>=h)
		return seg[pos];
	if(ql>h||qh<l)
		return 0;
	int mid=(l+h)/2;
	return rangeQuery(ql,qh,l,mid,(2*pos)+1)+rangeQuery(ql,qh,mid+1,h,(2*pos)+2);
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n,q,a,b,o,u;
	cin>>n>>q;
	vector<ll> ar(n);
	int x=ceil((double)log2(n));
	vector<ll> g(2*(int)pow(2,x)-1);
	lazy=g;
	seg=g;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	vi=ar;
	constructTree(0,n-1,0);
	while(q--){
		cin>>o;
		if(o==1){
			cin>>a>>b>>u;
			updateTree(0,0,n-1,a-1,b-1,u);
		}else{
			cin>>a;
			cout<<rangeQuery(a-1,a-1,0,n-1,0)<<endl;
		}
	}
	return 0;
}