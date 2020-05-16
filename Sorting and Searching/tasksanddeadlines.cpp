#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll n,a=0,ans=0;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end());
	for(auto x:v){
		ans+=x.second-(x.first+a);
		a+=x.first;
	}
	cout<<ans<<endl;
	return 0;
}