#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define p 1000000007
int main(){
	int n;
	cin>>n;
	ll ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	ll curr=ar[0],max1=ar[0];
	for(int i=1;i<n;i++){
		curr=max(ar[i],curr+ar[i]);
		max1=max(max1,curr);
	}
	cout<<max1<<endl;
	return 0;
}