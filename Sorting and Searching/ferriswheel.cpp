#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,x,i=0,j,count=0;
	cin>>n>>x;
	j=n-1;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	while(i<=j){
		if(v[i]+v[j]<=x)
			count++,i++,j--;
		else
			count++,j--;
	}
	cout<<count<<endl;
	return 0;
}