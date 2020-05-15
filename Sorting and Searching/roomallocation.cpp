#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n,x,y,max1=-1,count=0;
	cin>>n;
	multimap<pair<int,int>,int> m;
	vector<int> b(n);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		m.insert({{x,y},i});
	}
	for(auto itr=m.begin();itr!=m.end();++itr){
		int c=0;
		pair<int,int> p=itr->first;
		if(q.empty()||q.top().first>=p.first)
			c=++count;
		else
			c=q.top().second,q.pop();
		q.push({p.second,c});
		b[itr->second]=c;
	}
	cout<<count<<endl;
	for(int x:b)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}