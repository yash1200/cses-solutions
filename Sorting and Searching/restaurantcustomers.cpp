#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,x,y,max1=INT_MIN,cur=0;
	cin>>n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.push_back({x,1});
		v.push_back({y,-1});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cur+=v[i].second;
		max1=max(max1,cur);
	}
	cout<<max1<<endl;
	return 0;
}