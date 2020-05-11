#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	ll t=(n*(n+1))/2;
	if(t%2==1)
		cout<<"NO\n";
	else{
		t/=2;
		vector<ll> v;
		ll sum=0,e=0,i=n;
		while(1){
			v.push_back(i);
			sum+=i;
			i--;
			e=t-sum;
			if(e==0)
				break;
			if(e<=i){
				v.push_back(e);
				break;
			}
		}
		cout<<"YES\n";
		cout<<v.size()<<endl;
		for(int x:v)
			cout<<x<<" ";
		cout<<endl;
		cout<<n-v.size()<<endl;
		for(int j=i;j>0;j--){
			if(j==e)
				continue;
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}