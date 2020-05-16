#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getAll(vector<int> v,ll k){
	ll s=0;
	for(int x:v)
		s+=k/x;
	return s;
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll n,t,ans;
	cin>>n>>t;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	ll h=(*min_element(v.begin(),v.end()))*t,l=1,mid;
	while(l<=h){
		mid=(l+h)/2;
		if(getAll(v,mid)<t)
			l=mid+1;
		else
			h=mid-1,ans=mid;
	}
	cout<<ans<<endl;
	return 0;
}