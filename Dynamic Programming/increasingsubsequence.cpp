#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a;
	cin>>n;
	vector<int> dp;
	for(int i=0;i<n;i++){
		cin>>a;
		auto itr=lower_bound(dp.begin(),dp.end(),a);
		if(itr==dp.end())
			dp.push_back(a);
		else
			*itr=a;
	}
	cout<<dp.size()<<endl;
	return 0;
}