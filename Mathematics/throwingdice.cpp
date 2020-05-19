#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
vector<vector<ll>> mul(vector<vector<ll>> v,vector<vector<ll>> f){
	vector<vector<ll>> m(6,vector<ll>(6,0));
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			for(int k=0;k<6;k++)
				m[i][j]=(m[i][j]+(v[i][k]*f[k][j])%mod)%mod;
	return m;
}
vector<vector<ll>> power(vector<vector<ll>> v,ll n){
	vector<vector<ll>> f={{0,0,0,0,0,1}
	,{1,0,0,0,0,1},{0,1,0,0,0,1},
	{0,0,1,0,0,1},{0,0,0,1,0,1},
	{0,0,0,0,1,1}};
	if(n==1)
		return v;
	v=power(v,n/2);
	v=mul(v,v);
	if(n%2==1)
		v=mul(v,f);
	return v;
}
ll findTerm(ll n){
	vector<vector<ll>> v={{0,0,0,0,0,1}
	,{1,0,0,0,0,1},{0,1,0,0,0,1},
	{0,0,1,0,0,1},{0,0,0,1,0,1},
	{0,0,0,0,1,1}};
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(n==4) return 8;
	if(n==5) return 16;
	if(n==6) return 32;
	v=power(v,n-6);
	return ((v[0][5])%mod+(2*v[1][5])%mod+(4*v[2][5])%mod+(8*v[3][5])%mod+(16*v[4][5])%mod+(32*v[5][5])%mod)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    cout<<findTerm(n)<<endl;
	return 0;
}