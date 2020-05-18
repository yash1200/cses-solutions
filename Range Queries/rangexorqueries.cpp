#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n,q,a,b;
    cin>>n>>q;
    vector<int> v(n),x(n+1,0);
    for(int i=0;i<n;i++)
    	cin>>v[i],x[i+1]=x[i]^v[i];
    while(q--){
    	cin>>a>>b;
    	cout<<(x[b]^x[a-1])<<endl;
    }
	return 0;
}