#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,a;
	cin>>t;
	while(t--){
		int res=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a,res^=a;
		if(res==0)
			cout<<"second\n";
		else
			cout<<"first\n";
	}
	return 0;
}