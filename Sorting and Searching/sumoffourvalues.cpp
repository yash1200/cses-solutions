#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	vector<tuple<int,int,int>> b;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			b.emplace_back(v[i]+v[j],i+1,j+1);
	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++){
		int a=get<0>(b[i]);
		if(a>x/2)
			break;
		auto itr=lower_bound(&b[i+1],&b[b.size()],make_tuple(x-a,0,0));
		while(a+get<0>(*itr)==x){
			int p,q,r,x,y,z;
			tie(x,y,z)=b[i];
			tie(p,q,r)=*itr;
			if(y==q||y==r||z==q||z==r){
				++itr;
				continue;
			}
			cout<<y<<" "<<z<<" "<<q<<" "<<r<<endl;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
	return 0;
}