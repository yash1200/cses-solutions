#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,last=0,max1=-1,i;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	set<ll> s;
	for(int i=0;i<n;i++)
		if(s.count(v[i])){
			max1=max(max1,i-last);
			while(v[i]!=v[last])
				s.erase(v[last++]);
			last++;
		}
		else
			s.insert(v[i]);
	max1=max(max1,n-last);
	cout<<max1<<endl;
	return 0;
}