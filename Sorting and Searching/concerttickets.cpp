#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,m,l,x;
	cin>>n>>m;
	multiset<int,greater<int>> s;
	while(n--){
		cin>>x;
		s.insert(x);
	}
	while(m--){
		cin>>x;
		auto l=s.lower_bound(x);
		if(l==s.end())
			cout<<-1<<endl;
		else
			cout<<*l<<endl,s.erase(l);
	}
	return 0;
}