#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b,count=0;
	cin>>n;
	while(n){
		a=n,b=0;
		while(a){
			b=max(b,a%10);
			a/=10;
		}
		n-=b;
		count++;
	}
	cout<<count<<endl;
	return 0;
}