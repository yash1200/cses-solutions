#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool get(vector<ll> v,ll mid,ll k){
	ll count=0,sum=0;
	for(int i=0;i<v.size();i++){
		if(v[i]>mid)
			return false;
		sum+=v[i];
		if(sum>mid)
			count++,sum=v[i];
	}
	count++;
	if(count<=k)
		return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    ll n,k,h=0,l=1,ans=0;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i],h+=v[i];
    while(l<=h){
    	ll mid=(l+h)/2;
    	if(get(v,mid,k)){
    		ans=mid;
    		h=mid-1;
    	}else
    	l=mid+1;
    }
    cout<<ans<<endl;
	return 0;
}