#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a>b){
			int d=a-b;
			a-=2*d;
			b-=d;
		}else if(b>a){
			int d=b-a;
			b-=2*d;
			a-=d;
		}
		if(a<0||b<0){
			cout<<"NO\n";
			continue;
		}
		if(a%3==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}