#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int getAns(){
	ll n,a=0;
	cin>>n;
	vector<int> v(n),count(1000002);
	for(int i=0;i<n;i++){
		cin>>v[i];
		count[v[i]]++;
	}
	int max1=*max_element(v.begin(),v.end());
	for(int i=max1;i>=1;i--){
		int j=i;
		a=0;
		while(j<=max1){
			if(count[j]>=2)
				return j;
			else if(count[j]==1)
				a++;
			j+=i;
			if(a==2)
				return i;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout<<getAns()<<endl;
	return 0;
}