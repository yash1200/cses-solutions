#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,a;
	cin>>n;
	map<int,int> m;
	for(int i=1;i<n;i++){
		cin>>a;
		m[a]++;
	}
	for(int i=1;i<=n;i++)
		if(m[i]==0){
			cout<<i<<endl;
			break;
		}
	return 0;
}