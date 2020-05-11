#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define p 1000000007
ll power(ll x,ll y){
	int res = 1;
	x = x % p;
	if (x == 0) return 0;
	while(y>0){
		if (y & 1)
			res = (res*x) % p;
		y=y>>1;  
		x=(x*x)%p;
	}
	return res;
}
int main(){
	ll n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(a==0&&b==0){
			cout<<1<<endl;
			continue;
		}
		cout<<power(a,b)<<endl;
	}
	return 0;
}