#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll x,y,ans;
		cin>>y>>x;
		if(y>=x){
			if(y%2==0)
				ans=y*y-(x-1);
			else
				ans=(y-1)*(y-1)+1+(x-1);
		}else{
			if(x%2==0)
				ans=(x-1)*(x-1)+1+(y-1);
			else
				ans=x*x-(y-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}