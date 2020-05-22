#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,a;
	cin>>x>>n;
	multiset<int> m;
	set<int> s;
	s.insert(0);
	s.insert(x);
	for(int i=0;i<n;i++){
		cin>>a;
		auto l=s.lower_bound(a),r=--s.upper_bound(a);
		if(*l>a) --l;
		if(*r<a) ++r;
		auto t=m.find(*r - *l);
		if(t!=m.end())
			m.erase(t);
		m.insert(a-*l);
		m.insert(*r-a);
		s.insert(a);
		cout<<*--m.end()<<endl;
	}
	return 0;
}