#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,s=0,count=0;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].second>>v[i].first;
	sort(v.begin(),v.end());
	for(auto x:v)
		if(x.second>=s)
			s=x.first,count++;
	cout<<count<<endl;
	return 0;
}