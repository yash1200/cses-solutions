#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,a;
	cin>>t;
	while(t--){
		int s=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			if(i%2)
				s^=a;
		}
		cout<<(s?"first":"second")<<endl;
	}
	return 0;
}