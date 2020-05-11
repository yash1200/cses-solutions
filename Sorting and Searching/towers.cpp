#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,j;
	cin>>n;
	vector<ll> v(n);
	multiset<ll> s;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++){
		auto itr=s.lower_bound(v[i]+1);
		if(itr==s.end())
			s.insert(v[i]);
		else
			s.erase(itr),s.insert(v[i]);
	}
	cout<<s.size()<<endl;
	return 0;
}