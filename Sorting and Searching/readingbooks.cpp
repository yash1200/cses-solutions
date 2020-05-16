#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll n,i=0,ans=0;
	cin>>n;
	vector<ll> v(n),pre(n+1,0),suff(n+1,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	if(n==1){
		cout<<2*v[0]<<endl;
		return 0;
	}
	sort(v.begin(),v.end());
	pre[0]=v[0];
	suff[n-1]=v[n-1];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+v[i];
	for(int i=n-2;i>=0;i--)
		suff[i]=suff[i+1]+v[i];
	for(i=0;i<n;i++)
		if(suff[i]<pre[i])
			break;
	i--;
	ans=pre[n-1];
	if(i==n-2)
		ans+=suff[i+1]-pre[i];
	cout<<ans<<endl;
	return 0;
}