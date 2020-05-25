#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
void getSetBitsFromOneToN(ll N){
	ll two=2,ans=0;
	ll n=N;
	while(n){
		ans+=(N/two)*(two>>1);
		if((N&(two-1))>(two>>1)-1)
			ans+=(N&(two-1))-(two>>1)+1;
		two<<=1;
		n>>=1;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	getSetBitsFromOneToN(n);
	return 0;
}