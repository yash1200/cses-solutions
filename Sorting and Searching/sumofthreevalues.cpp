#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i].first;
    	v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++){
    	if(v[i].first>=x)
    		break;
    	for(int j=i+1;j<n-1;j++){
    		if(v[i].first+v[j].first>=x)
    			break;
    		auto itr=lower_bound(&v[j+1],&v[n],pair<int,int>(x-(v[i].first+v[j].first),0));
    		if((v[i].first+v[j].first+(*itr).first)!=x)
    			continue;
    		cout<<v[i].second<<" "<<v[j].second<<" "<<(*itr).second<<endl;
    		return 0;
    	}
    }
    cout<<"IMPOSSIBLE\n";
	return 0;
}