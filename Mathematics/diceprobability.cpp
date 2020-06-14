#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	ll sum=0;
	cin>>n>>a>>b;
	vector<ll> v(b+1);
	v[0]=1;
	for(int i=0;i<n;i++)
		for(int j=b;j>=0;j--){
			v[j]=0;
			for(int k=1;k<=6;k++)
				if(j>=k)
					v[j]+=v[j-k];
		}
	for(int i=a;i<=b;i++)
		sum+=v[i];
	cout<<fixed<<setprecision(6)<<sum/pow(6,n)<<endl;
	return 0;
}