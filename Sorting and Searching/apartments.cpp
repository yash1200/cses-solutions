#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,m,k,count=0,i=0,j=0;
	cin>>n>>m>>k;
	vector<ll> a(n),b(m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(i<n&&j<m){
		if(a[i]+k>=b[j]&&a[i]-k<=b[j])
			count++,i++,j++;
		if(a[i]+k<b[j])
			i++;
		if(a[i]-k>b[j])
			j++;
	}
	cout<<count<<endl;
	return 0;
}