#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define p 1000000007
int main(){
	ll t=1;
	while(t--){
		int n,a;
		cin>>n;
		set<int> s;
		for(int i=0;i<n;i++){
			cin>>a;
			s.insert(a);
		}
		cout<<s.size()<<endl;
	}
	return 0;
}