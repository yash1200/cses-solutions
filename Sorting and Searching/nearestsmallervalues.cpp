#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n,ans;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<pair<int,int>> a;
	for(int i=0;i<n;i++){
		while(a.size()>0){
			ans=a.back().first;
			if(a.back().second<v[i])
				break;
			a.pop_back();
		}
		if(a.size()==0)
			ans=0;
		cout<<ans<<" ";
		a.push_back({i+1,v[i]});
	}
	cout<<endl;
	return 0;
}