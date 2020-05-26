#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,c=0;
	cin>>n;
	while(n>0){
		ll i=(ll)log2(n);
		c+=(ll)pow(2,i-1)*i;
		c+=n-(ll)pow(2,i)+1;
		n-=(ll)pow(2,i);
	}
	cout<<c<<endl;
    return 0;
}